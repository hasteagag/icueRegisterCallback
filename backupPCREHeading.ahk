SetTitleMatchMode, 2
DetectHiddenWindows On
global lastHeldTimePointer=0
global profilePointer:=0
OnMessage(0x5556, "MsgMonitor")
ReadMemory(MADDRESS,PID)
{
	VarSetCapacity(MVALUE,4,0)
	ProcessHandle := DllCall("OpenProcess", "Int", 24, "Char", 0, "UInt", PID, "UInt")
	DllCall("ReadProcessMemory", "UInt", ProcessHandle, "Ptr", MADDRESS, "Ptr", &MVALUE, "Uint",4)
	Loop 4
	result += *(&MVALUE + A_Index-1) << 8*(A_Index-1)
	return, result
}
;these must match expected q key colors per cpp herein.  tweak as needed the RGB either in icue or in cpp:
ProfileName(readNumber)
{
	sendBackProfileName:=""
	if(readNumber=0)
	{
		sendBackProfileName:="Default"
	}
	else if(readNumber=1)
	{
		sendBackProfileName:="UltraMod"
	}
	else if(readNumber=2)
	{
		sendBackProfileName:="Sketchup"
	}
	else if(readNumber=3)
	{
		sendBackProfileName:="Acrobat"
	}
	else if(readNumber=4)
	{
		sendBackProfileName:="Dreamweaver"
	}
	else if(readNumber=5)
	{
		sendBackProfileName:="Outlook"
	}
	else if(readNumber=6)
	{
		sendBackProfileName:="Word"
	}
	else if(readNumber=7)
	{
		sendBackProfileName:="Photoshop"
	}
	else if(readNumber=8)
	{
		sendBackProfileName:="Bridge"
	}
	else if(readNumber=9)
	{
		sendBackProfileName:="Illustrator"
	}
	else if(readNumber=10)
	{
		sendBackProfileName:="Excel"
	}
	else if(readNumber=11)
	{
		sendBackProfileName:="programming"
	}
	return sendBackProfileName
}
requestProfilePointer(PID)
{
	SendMessage, 0x5557, 1,1,,ahk_pid %PID%,,,,
	WinHide,ahk_pid %PID%
	return
}
getCurProfile()
{
	Process, Exist, WindowsProject1.exe
	PID:=ErrorLevel
	if(profilePointer=0)
	{
		requestProfilePointer(PID)
	}
	Return ProfileName(ReadMemory(profilePointer,PID))
}
lastHeldTime()
{
	Process, Exist, WindowsProject1.exe
	PID:=ErrorLevel
	if(lastHeldTimePointer=0)
	{
		requestProfilePointer(PID)
	}
	return ReadMemory(lastHeldTimePointer,PID)
}
MsgMonitor(wParam, lParam, msg)
{
    profilePointer:=Format("{1:#x}", wParam)
	lastHeldTimePointer:=Format("{1:#x}", lParam)
	Return
}

;below is an example, an example of all G - m keys are below
+SC0CE Up::
	;Shift G14 detect long press hopefully and adds a locker
	profile := getCurProfile()
	lht:=lastHeldTime()
	if(profile == "Photoshop" && lht > 300) {
		; clickAndMoveBack(373,44)
		msgbox here
	}
return
SC0C1::
	;MsgBox G1
	;make your own magic happen here
return
SC0C2::
	;MsgBox G2	
return
SC0C3::
	;MsgBox G3	
return
SC0C4::
	;MsgBox G4	
return
SC0C5::
	;MsgBox G5	
return
SC0C6::
	;MsgBox G6	
return
SC0C7::
	;MsgBox G7	
return
SC0C8::
	;MsgBox G8	
return
SC0C9::
	;MsgBox G9	
return
SC0CA::
	;MsgBox G10	
return
SC0CB::
	;MsgBox G11	
return
SC0CC::
	;MsgBox G12	
return
SC0CD::
	;MsgBox G13	
return
SC0CE::
	;MsgBox G14
return
SC0CF::
	;MsgBox G15	
return
SC0D0::
	;MsgBox G16	
return
SC0D1::
	;MsgBox G17	
return
SC0D2::
	;MsgBox G18	
return
SC0D3::
	;MsgBox M1	
return
SC0D4::
	;MsgBox M2	
return
SC0D5::
	;MsgBox M3	
return
SC0D6::
	;MsgBox M4	
return
SC0D7::
	;MsgBox M5	
return
SC0D8::
	;MsgBox M6	
return
SC0D9::
	;MsgBox M7	
return
SC0E9::
	;MsgBox M9	
return
SC0EA::
	;MsgBox M10
return
SC0EB::
	;MsgBox M11	
return
SC0EC::
	;MsgBox M12	
return
