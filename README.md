# icueRegisterCallback
Modified Register Callback example from Corsair SDK outputting SC combinations for each keyevent and logging last held time duration and detecting current profile


Very specifically, Corsair's team released an SDK (which is only included herewith to the extent I assume I am allowed to redistribute, please see their webiste for any particulars or details, linked below).  Using the register callback example provided by Corsair, we are simply emitting scancode events to be registered elsewhere (autohotkey).  This software also records the currently active corsair icue profile, by reading an assumed static key - in my case the q key.  Your mileage may vary in that respect, but in my experience, static lighting on a single key is not especially noticable and you get the full fidelity of rgb per key in the software so there are many variations available if you had further profiles than I.

I use the profiles as a double check in autohotkey to ensure expected behavior as I came to autohotkey as a heavy icue user.

The profiles and the last held time are saved to an extern int, to be read via memory in autohotkey as per the examples.

Additionally, the program is setup to recieve messages using the windows framework, to receive a message notifying it that the pointer to the "current profile" and the last held time pointer (the position in memory) should be sent back to the calling application.  Presently, this behavior is limited and only of use to me as the filename is statically listed.  You would need to recompile, or adjust the application to accept parameters, or to even search for the running ahk filename in order to send the message back. (this is on the TODO list, to broaden functionality for another user, who may run the ahk from anywhere, or if the version number changes).

the initial load up of the example has been modified to retry every 10 seconds until successful handshake occurs.  This is because sometimes icue has not loaded and the applicaiton is run, either by user or the task scheduler.  Seems to work, but could probably have some 'abort' / 'resume' functionality added.

TODO:  Strip out the bunk from the default Visual Studio Examples (about box etc)
        Autohide the window
        see if i can get the lambda working
        check if up events happen properly, as in AHK for example, last held time is irrelevant if you detect for {SC0xx Up} events...

Corsair website en us:
https://www.corsair.com/us/en/
SDK available here, latest version as of writing this:
http://downloads.corsair.com/Files/CUE/CUESDK_3.0.234.zip
