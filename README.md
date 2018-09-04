RemindersImport
===============

Command-line tool for migrating Mac OS X Reminders from the canonical system storage to The Omni Group's OmniFocus Pro app. Because this tool relies upon AppleScript support, it will not work with the non-pro version of OmniFocus.

Description
===========

The Omni Group's <a href="http://www.omnigroup.com/products/omnifocus-iphone/">OmniFocus for iOS</a> takes advantage of a clever trick for allowing users to add items by voice instruction to Siri. OmniFocus will import items from the phone's central Reminders list, so that when you want to add something "to OmniFocus" you can just ask Siri to "add it to my reminders list."

Unfortunately, <a href="http://www.omnigroup.com/products/omnifocus/">OmniFocus for Mac</a> doesn't support this. I love OmniFocus for both Mac and iOS, but it turns out that because I lean so heavily on using Siri to add items, I tend not to open OmniFocus while I'm on the go. When I come home and get to work on my Mac, I notice that OmniFocus doens't contain any of my recently added items, so I have to go through the cumbersome steps of opening my iPhone and launching OmniFocus <em>just to get this theoretically time-saving trick to work right.</em>

RemnindersImport solves this problem by adding behavior to my Mac that strongly emulates the behavior built in to OmniFocus for iOS. When launched, the tool will scan for non-location-based reminders, add them to OmniFocus (with start and due dates in-tact!), and then remove them from Apple's reminders list.

Build It
========

The tool should build easily using modern Xcode tools. Assuming you have the command-line xcodebuild in your path:

<pre>
git clone git@github.com:danielpunkass/RemindersImport.git
cd RemindersImport
xcodebuild
</pre>

The built tool is now in ./build/Release/RemindersImport

Use It
=====

<strong>Warning:</strong> RemindersImport is designed to scan your Mac OS X Reminders <em>and remove them</em> from the default location in your Reminders list so that they may be added instead to OmniFocus. You should understand very well that this is what you want to do before building and running the tool.

Let's say you have 5 Reminders that you added via Siri on your phone. In the background, thanks to Apple's aggressive syncing, these have been migrated over to your Mac and are now visible in Reminders.app. To migrate these from Reminders to OmniFocus, just run the tool once:

<pre>
./RemindersImport
</pre>

If you've opted to use a different reminders list for OmniFocus, you can specify the name on the command line to import from that list instead:

<pre>
./RemindersImport "Junk to Do"
</pre>

Automatic Execution
====================

Running the tool by hand is about as annoying as having to remember to open up the iPhone and launch OmniFocus, so ideally you'll want to set this thing up to run on its own automatically. Previously I used a crude crontab entry to achieve this, but starting in OS X 10.12 I have found that the cron-initiated task for some reason fails to perform the desired import. I've switched to using a launchd "Launch Agent" which can be achieved by adding a file like this to for example ~/Library/LaunchAgents/com.punkitup.remindersimport.plist:

<pre>
&lt;?xml version="1.0" encoding="UTF-8"?>
&lt;!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
&lt;plist version="1.0">
&lt;dict>
        &lt;key>Label&lt;/key>
        &lt;string>com.punkitup.remindersimport&lt;/string>
        &lt;key>Program&lt;/key>
        &lt;string>/Volumes/Data/daniel/bin/RemindersImport&lt;/string>
        &lt;key>LowPriorityIO&lt;/key>
        &lt;true/>
        &lt;key>Nice&lt;/key>
        &lt;integer>1&lt;/integer>
        &lt;key>StartInterval&lt;/key>
        &lt;integer>60&lt;/integer>
&lt;/dict>
&lt;/plist>
</pre>

With this configuration, thanks to the "StartInterval" value of 60, the importer will run every minute to see if any new reminders are available to import.

Something I'd like to look into is whether it would make sense to set this tool up as lightweight daemon that just stays running all the time, waiting for Reminders database changes to happen, and then snagging stuff. For now, the launchd based trick is doing the job well enough for my needs.
