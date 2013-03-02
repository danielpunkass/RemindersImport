//
//  main.m
//  RemindersImport
//
//  Created by Daniel Jalkut on 1/30/13.
//  Copyright (c) 2013 Bitsplitting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EventKit/EventKit.h>

NSArray* importableReminderItems(EKEventStore* theEventStore)
{
	NSMutableArray* qualifiedItems = [NSMutableArray array];
	NSString* remindersListName = @"Reminders";
	if ([[[NSProcessInfo processInfo] arguments] count] < 2)
	{
		NSLog(@"No Reminders list name specified, defaulting to \"%@\"", remindersListName);
	}
	else
	{
		remindersListName = [[[NSProcessInfo processInfo] arguments] objectAtIndex:1];
	}

	// Get all events from the "Reminders" list
	__block BOOL done = NO;

	// Get all the dedicated Reminders calendars
	NSArray* remindersCalendars = [theEventStore calendarsForEntityType:EKEntityTypeReminder];

	NSPredicate *remindersPredicate = [theEventStore predicateForIncompleteRemindersWithDueDateStarting:nil ending:nil calendars:remindersCalendars];
	[theEventStore fetchRemindersMatchingPredicate:remindersPredicate completion:^(NSArray *reminders)
	{
		// Since fetchRemindresMatchingPredicate doesn't actually work with general-purpose NSPredicate,
		// we have to use one of the coarse-grained EKEventStore-vended predicates, and then further filter on
		// our own. This predicate attempts to match The Omni Group's own filtering approach: if the reminder
		// is in the list and is not a location-based reminder, just snag it and delete it, otherwise,
		// leave it alone.
		//
		// NOTE: I'm being lazy for starters and not figuring out how to specify that the matched reminder
		// should have NO alarms that feature a non-nil structuredLocation (i.e. the alarm is not to remind when
		// arriving at a speicfic location). I just filter those out in the for loop below.
		NSPredicate* fineGrainPredicate = [NSPredicate predicateWithFormat:@"calendar.title = %@", remindersListName];
		NSArray* targetReminderItems = [reminders filteredArrayUsingPredicate:fineGrainPredicate];

		for (EKReminder* thisReminder in targetReminderItems)
		{
			BOOL hasLocationBasedAlarm = NO;

			for (EKAlarm* thisAlarm in [thisReminder alarms])
			{
				if ([thisAlarm structuredLocation] != nil)
				{
					hasLocationBasedAlarm = YES;
					break;
				}
			}

			if (hasLocationBasedAlarm == NO)
			{
				[qualifiedItems addObject:thisReminder];
			}
		}
		done = YES;
	}];

	while (done == NO)
	{
		[[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
	}

	return qualifiedItems;
}

NSString* omniFocusAddTaskScriptTemplate()
{
	return @"\
-- Work around a problem where if OmniFocus is not already running,\n\
-- it might hang when trying to handle our request just as it's launching\n\
set isRunning to true\n\
tell application \"System Events\"\n\
	try\n\
		application process \"OmniFocus\"\n\
	on error\n\
		set isRunning to false\n\
	end try\n\
end tell\n\
\n\
-- Wait a good long 10 seconds to make sure OmniFocus has time to launch\n\
if (isRunning is false) then\n\
	tell application \"OmniFocus\" to launch\n\
	delay 10.0\n\
end if\n\
\
tell application \"OmniFocus\"\n\
	tell default document\n\
		make new inbox task with properties {name:\"%@\", start date:%@, due date:%@}\n\
	end tell\n\
end tell";
}

NSString* dateArgumentStringForDateString(NSString* theDateString)
{
	// The date arguments should be either "date \"<dateString>\"" or else "missing value" if nil
	NSString* dateArgument = ([theDateString length] > 0) ? [NSString stringWithFormat:@"date \"%@\"", theDateString] : @"missing value";
	return dateArgument;
}

BOOL makeOmniFocusInboxTaskFromReminderInfo(NSString* newTaskTitle, NSString* startDateString, NSString* dueDateString)
{
	BOOL didSucceed = NO;

	// Escape any quotes in the task title
	NSString* escapedTaskTitle = [newTaskTitle stringByReplacingOccurrencesOfString:@"\"" withString:@"\\\""];

	NSString* startDateArgument = dateArgumentStringForDateString(startDateString);
	NSString* dueDateArgument = dateArgumentStringForDateString(dueDateString);
	NSString* newTaskAppleScript = [NSString stringWithFormat:omniFocusAddTaskScriptTemplate(), escapedTaskTitle, startDateArgument, dueDateArgument];
	NSAppleScript* addTaskScript = [[[NSAppleScript alloc] initWithSource:newTaskAppleScript] autorelease];
	NSDictionary* anyError = nil;
	(void) [addTaskScript executeAndReturnError:&anyError];

	if (anyError != nil)
	{
		NSLog(@"Failed to add task, got scripting error: %@", anyError);
		didSucceed = NO;
	}
	else
	{
		NSLog(@"Added task \"%@\" to OmniFocus.", newTaskTitle);
		didSucceed = YES;
	}

	return didSucceed;
}

NSCalendar* gregorianCalendar()
{
	return [[[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar] autorelease];;
}

NSDateFormatter* gregorianFormatterWithFormat(NSString* formatString)
{
	NSDateFormatter* gregorianFormatter = [[[NSDateFormatter alloc] init] autorelease];
	[gregorianFormatter setFormatterBehavior:NSDateFormatterBehavior10_4];
	[gregorianFormatter setDateFormat:formatString];
	[gregorianFormatter setCalendar:gregorianCalendar()];
	return gregorianFormatter;
}

NSString* scriptableDateStringFromComponents(NSDateComponents* inComponents)
{
	NSString* dateString = nil;

	if (inComponents != nil)
	{
		// This is in Unicode format as described here: http://userguide.icu-project.org/formatparse/datetime,
		// and designed to match the example like "Thursday, January 31, 2013 4:32:40 PM". I observed this
		// format as the default format returned by AppleScript on my US-based English Mac. I can't vouch
		// for how well this will work in other locales, but let me know if you try it!
		NSString* dateFormatString = @"EEEE, LLLL d y hh:mm:ss a";
		NSDate *targetDate = [gregorianCalendar() dateFromComponents:inComponents];
		NSDateFormatter* dateFormatter = gregorianFormatterWithFormat(dateFormatString);
		dateString = [dateFormatter stringFromDate:targetDate];
	}

	return dateString;
}

int main(int argc, const char * argv[])
{
	@autoreleasepool
	{
		EKEventStore* eventStore = [[EKEventStore alloc] initWithAccessToEntityTypes:EKEntityMaskReminder];

		for (EKReminder* thisReminder in importableReminderItems(eventStore))
		{
			// Extract the information we need to ask OmniFocus to add the item
			NSString* newTaskName = [thisReminder title];

			NSString* startDateString = scriptableDateStringFromComponents([thisReminder startDateComponents]);
			NSString* dueDateString = scriptableDateStringFromComponents([thisReminder dueDateComponents]);

			if (makeOmniFocusInboxTaskFromReminderInfo(newTaskName, startDateString, dueDateString) == YES)
			{
				NSLog(@"Removing task %@ from event store", newTaskName);
				NSError* removeError = nil;
				if ([eventStore removeReminder:thisReminder commit:NO error:&removeError] == NO)
				{
					NSLog(@"Failed to remove reminder %@ from event store. Error: %@", newTaskName, [removeError localizedDescription]);
				}
			}
		}

		// We queued up any removes by specifying commit:NO, so let's commit now to finish the job
		NSError* commitError = nil;
		if ([eventStore commit:&commitError] == NO)
		{
			NSLog(@"Failed to commit reminder removes. Error: %@", [commitError localizedDescription]);
		}

		// Clean up because it just feels right.
		[eventStore release];
	}
    return 0;
}

