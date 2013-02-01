RemindersImport
===============

Command-line tool for migrating Mac OS X Reminders from the canonical system storage to The Omni Group's OmniFocus app.

Description
===========

The Omni Group's <a href="http://www.omnigroup.com/products/omnifocus-iphone/">OmniFocus for iOS</a> takes advantage of a clever trick for allowing users to add items by voice instruction to Siri. OmniFocus will import items from the phone's central Reminders list, so that when you want to add something "to OmniFocus" you can just ask Siri to "add it to my reminders list."

Unfortunately, <a href="http://www.omnigroup.com/products/omnifocus/">OmniFocus for Mac</a> doesn't support this. I love OmniFocus for both Mac and iOS, but it turns out that because I lean so heavily on using Siri to add items, I tend not to open OmniFocus while I'm on the go. When I come home and get to work on my Mac, I notice that OmniFocus doens't contain any of my recently added items, so I have to go through the cumbersome steps of opening my iPhone and launching OmniFocus <em>just to get this theoretically time-saving trick to work right.</em>

RemnindersImport solves this problem by adding behavior to my Mac that strongly emulates the behavior built in to OmniFocus for iOS. When launched, the tool will scan for non-location-based reminders, add them to OmniFocus (with start and due dates in-tact!), and then remove them from Apple's reminders list.

Usage
=====

<strong>Warning:</strong> RemindersImport is designed to scan your Mac OS X Reminders <em>and remove them</em> from the default location in your Reminders list so that they may be added instead to OmniFocus. You should understand very well that this is what you want to do before building and running the tool.

Let's say you have 5 Reminders that you added via Siri on your phone. In the background, thanks to Apple's aggressive syncing, these have been migrated over to your Mac and are now visible in Reminders.app. To migrate these from Reminders to OmniFocus, just run the tool once:

<pre>
% ./RemindersImport
</pre>

If you've opted to use a different reminders list for OmniFocus, you can specify the name on the command line to import from that list instead:

<pre>
% ./RemindersImport "Junk to Do"
</pre>

Automatic Execution
====================

Running the tool by hand is about as annoying as having to remember to open up the iPhone and launch OmniFocus, so ideally you'll want to set this thing up to run on its own automatically. I haven't yet settled on the ideal approach for this, but a crude way of setting it up would be to just use Mac OS X's built-in cron scheduling service to run the tool very often, say every minute:

<pre>
*/1 * * * * /Users/daniel/bin/RemindersImport
</pre>

Something I'd like to look into is whether it would make sense to set this tool up as lightweight daemon that just stays running all the time, waiting for Reminders database changes to happen, and then snagging stuff. For now, the crontab based trick is doing the job well enough for my needs.
