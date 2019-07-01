// WindowsProject1.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name



extern int currentProfile;
int currentProfile = 999;

extern int lastHeldTime;
int lastHeldTime = 999;
const char * scriptName = "C:\\Users\\asmith\\Desktop\\backupPCREHeading.ahk - AutoHotkey v1.1.30.03";
int * pointerToCurrentProfile = &currentProfile;
int * pointerToLHT = &lastHeldTime;
struct Context
{
	//adding it up here would seem to make sense, make the initial press time part of the incoming context to the lambda function...
	CorsairKeyId m_lastPressedKey;
};

const std::unordered_map<CorsairKeyId, std::string> keyIdStrings = {
	{CorsairKey_Invalid, "CorsairKey_Invalid"},
	{CorsairKeyKb_G1, "CorsairKeyKb_G1"},
	{CorsairKeyKb_G2, "CorsairKeyKb_G2"},
	{CorsairKeyKb_G3, "CorsairKeyKb_G3"},
	{CorsairKeyKb_G4, "CorsairKeyKb_G4"},
	{CorsairKeyKb_G5, "CorsairKeyKb_G5"},
	{CorsairKeyKb_G6, "CorsairKeyKb_G6"},
	{CorsairKeyKb_G7, "CorsairKeyKb_G7"},
	{CorsairKeyKb_G8, "CorsairKeyKb_G8"},
	{CorsairKeyKb_G9, "CorsairKeyKb_G9"},
	{CorsairKeyKb_G10, "CorsairKeyKb_G10"},
	{CorsairKeyKb_G11, "CorsairKeyKb_G11"},
	{CorsairKeyKb_G12, "CorsairKeyKb_G12"},
	{CorsairKeyKb_G13, "CorsairKeyKb_G13"},
	{CorsairKeyKb_G14, "CorsairKeyKb_G14"},
	{CorsairKeyKb_G15, "CorsairKeyKb_G15"},
	{CorsairKeyKb_G16, "CorsairKeyKb_G16"},
	{CorsairKeyKb_G17, "CorsairKeyKb_G17"},
	{CorsairKeyKb_G18, "CorsairKeyKb_G18"},

	{CorsairKeyMouse_M1, "CorsairKeyMouse_M1"},
	{CorsairKeyMouse_M2, "CorsairKeyMouse_M2"},
	{CorsairKeyMouse_M3, "CorsairKeyMouse_M3"},
	{CorsairKeyMouse_M4, "CorsairKeyMouse_M4"},
	{CorsairKeyMouse_M5, "CorsairKeyMouse_M5"},
	{CorsairKeyMouse_M6, "CorsairKeyMouse_M6"},
	{CorsairKeyMouse_M7, "CorsairKeyMouse_M7"},
	{CorsairKeyMouse_M8, "CorsairKeyMouse_M8"},
	{CorsairKeyMouse_M9, "CorsairKeyMouse_M9"},
	{CorsairKeyMouse_M10, "CorsairKeyMouse_M10"},
	{CorsairKeyMouse_M11, "CorsairKeyMouse_M11"},
	{CorsairKeyMouse_M12, "CorsairKeyMouse_M12"}
};

const std::unordered_map<CorsairKeyId, CorsairLedId> keyIdToLedId = {
	{CorsairKey_Invalid, CLI_Invalid},

	{CorsairKeyKb_G1, CLK_G1},
	{CorsairKeyKb_G2, CLK_G2},
	{CorsairKeyKb_G3, CLK_G3},
	{CorsairKeyKb_G4, CLK_G4},
	{CorsairKeyKb_G5, CLK_G5},
	{CorsairKeyKb_G6, CLK_G6},
	{CorsairKeyKb_G7, CLK_G7},
	{CorsairKeyKb_G8, CLK_G8},
	{CorsairKeyKb_G9, CLK_G9},
	{CorsairKeyKb_G10, CLK_G10},
	{CorsairKeyKb_G11, CLK_G11},
	{CorsairKeyKb_G12, CLK_G12},
	{CorsairKeyKb_G13, CLK_G13},
	{CorsairKeyKb_G14, CLK_G14},
	{CorsairKeyKb_G15, CLK_G15},
	{CorsairKeyKb_G16, CLK_G16},
	{CorsairKeyKb_G17, CLK_G17},
	{CorsairKeyKb_G18, CLK_G18},

	{CorsairKeyMouse_M1, CLM_1},
	{CorsairKeyMouse_M2, CLM_2},
	{CorsairKeyMouse_M3, CLM_3},
	{CorsairKeyMouse_M4, CLM_4},
	{CorsairKeyMouse_M5, CLM_5},
	{CorsairKeyMouse_M6, CLM_6},
	{CorsairKeyMouse_M7, CLK_A},
	{CorsairKeyMouse_M8, CLK_B},
	{CorsairKeyMouse_M9, CLK_C},
	{CorsairKeyMouse_M10, CLK_D},
	{CorsairKeyMouse_M11, CLK_E},
	{CorsairKeyMouse_M12, CLK_F}
};

const char* toString(CorsairError error)
{
	switch (error) {
	case CE_Success:
		return "CE_Success";
	case CE_ServerNotFound:
		return "CE_ServerNotFound";
	case CE_NoControl:
		return "CE_NoControl";
	case CE_ProtocolHandshakeMissing:
		return "CE_ProtocolHandshakeMissing";
	case CE_IncompatibleProtocol:
		return "CE_IncompatibleProtocol";
	case CE_InvalidArguments:
		return "CE_InvalidArguments";
	default:
		return "unknown error";
	}
}

//
auto startTimeG1 = Time::now();
auto startTimeG2 = Time::now();
auto startTimeG3 = Time::now();
auto startTimeG4 = Time::now();
auto startTimeG5 = Time::now();
auto startTimeG6 = Time::now();
auto startTimeG7 = Time::now();
auto startTimeG8 = Time::now();
auto startTimeG9 = Time::now();
auto startTimeG10 = Time::now();
auto startTimeG11 = Time::now();
auto startTimeG12 = Time::now();
auto startTimeG13 = Time::now();
auto startTimeG14 = Time::now();
auto startTimeG15 = Time::now();
auto startTimeG16 = Time::now();
auto startTimeG17 = Time::now();
auto startTimeG18 = Time::now();
auto startTimeM1 = Time::now();
auto startTimeM2 = Time::now();
auto startTimeM3 = Time::now();
auto startTimeM4 = Time::now();
auto startTimeM5 = Time::now();
auto startTimeM6 = Time::now();
auto startTimeM7 = Time::now();
auto startTimeM8 = Time::now();
auto startTimeM9 = Time::now();
auto startTimeM10 = Time::now();
auto startTimeM11 = Time::now();
auto startTimeM12 = Time::now();
//
auto endTime = Time::now();
auto diff = std::chrono::milliseconds::zero();

HWND hWnd = FindWindowA(NULL, "C:\\Users\\asmith\\Desktop\\backupPCREHeading.ahk - AutoHotkey v1.1.30.03");

int profileGetter(CorsairLedColor ledColor) {
	if (ledColor.r == 20 && ledColor.b == 0)
	{
		currentProfile = 0;
	}
	else if (ledColor.r == 238 && ledColor.b == 255)
	{
		currentProfile = 1;
	}
	else if (ledColor.r == 155 && ledColor.g == 255 && ledColor.b == 0)
	{
		currentProfile = 2;
	}
	else if (ledColor.r == 43)
	{
		currentProfile = 3;
	}
	else if (ledColor.r == 98 && ledColor.g == 255)
	{
		currentProfile = 4;
	}
	else if (ledColor.b == 1)
	{
		currentProfile = 5;
	}
	else if (ledColor.g == 13 && ledColor.b == 60)
	{
		currentProfile = 6;
	}
	else if (ledColor.r == 53 && ledColor.b == 255)
	{
		currentProfile = 7;
	}
	else if (ledColor.r == 255 && ledColor.b == 165)
	{
		currentProfile = 8;
	}
	else if (ledColor.r == 255 && ledColor.g == 170 && ledColor.b == 0)
	{
		currentProfile = 9;
	}
	else if (ledColor.g == 255)
	{
		currentProfile = 10;
	}
	else if (ledColor.g == 254)
	{
		currentProfile = 11;
	}
	else
	{

	}
	//return for future / old compatibility, we are assigning a global or a wider scope variable above
	return currentProfile;
}
void otherCallBack() {
	auto ledId = CLK_Q;
	CorsairLedColor ledColor = { ledId, 0, 0, 0 };
	CorsairGetLedsColors(1, &ledColor);
	currentProfile = profileGetter(ledColor);
}

bool mediaKeyProfileChecker()
{
	//I want the profile checking conditional on keypress not more than every 2 seconds or i might get some unanticipated results...that's why i am only conditionally calling it
	if (GetAsyncKeyState(VK_F3))
	{
		//progressFunction(3000);
		otherCallBack();
		std::cout << "here";
	}
	else if ((32767 + GetAsyncKeyState(VK_MEDIA_NEXT_TRACK)) == 0)
	{
		//progressFunction(3000);
		//this is never getting registered...use a separate program?
		otherCallBack();
	}
	else if ((32767 + GetAsyncKeyState(VK_MEDIA_PLAY_PAUSE)) == 0)
	{
		otherCallBack();
	}
	else if ((32767 + GetAsyncKeyState(VK_MEDIA_PREV_TRACK)) == 0)
	{
		otherCallBack();
	}
	else if ((32767 + GetAsyncKeyState(VK_MEDIA_STOP)) == 0)
	{
		return false;
	}
	return true;
}

void presserFunc(CorsairKeyId keyId, CorsairLedColor ledColor)
{
	profileGetter(ledColor);
	if (keyId == CLK_ScanNextTrack)
	{
		std::cout << "here";
	}
	else if (keyId == CorsairKeyKb_G1)
	{
		startTimeG1 = Time::now();
		keybd_event(VK_KANA, 0xC1, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G2)
	{
		startTimeG2 = Time::now();
		keybd_event(VK_KANA, 0xC2, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G3)
	{
		startTimeG3 = Time::now();
		keybd_event(VK_KANA, 0xC3, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G4)
	{
		startTimeG4 = Time::now();
		keybd_event(VK_KANA, 0xC4, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G5)
	{
		startTimeG5 = Time::now();
		keybd_event(VK_KANA, 0xC5, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G6)
	{
		startTimeG6 = Time::now();
		keybd_event(VK_KANA, 0xC6, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G7)
	{
		startTimeG7 = Time::now();
		keybd_event(VK_KANA, 0xC7, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G8)
	{
		startTimeG8 = Time::now();
		keybd_event(VK_KANA, 0xC8, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G9)
	{
		startTimeG9 = Time::now();
		keybd_event(VK_KANA, 0xC9, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G10)
	{
		startTimeG10 = Time::now();
		keybd_event(VK_KANA, 0xCA, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G11)
	{
		startTimeG11 = Time::now();
		keybd_event(VK_KANA, 0xCB, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G12)
	{
		startTimeG12 = Time::now();
		keybd_event(VK_KANA, 0xCC, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G13)
	{
		startTimeG13 = Time::now();
		keybd_event(VK_KANA, 0xCD, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G14)
	{
		startTimeG14 = Time::now();
		keybd_event(VK_KANA, 0xCE, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G15)
	{
		startTimeG15 = Time::now();
		keybd_event(VK_KANA, 0xCF, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G16)
	{
		startTimeG16 = Time::now();
		keybd_event(VK_KANA, 0xD0, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G17)
	{
		startTimeG17 = Time::now();
		keybd_event(VK_KANA, 0xD1, 0, 0);
	}
	else if (keyId == CorsairKeyKb_G18)
	{
		startTimeG18 = Time::now();
		keybd_event(VK_KANA, 0xD2, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M1)
	{
		startTimeM1 = Time::now();
		keybd_event(VK_KANA, 0xD3, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M2)
	{
		startTimeM2 = Time::now();
		keybd_event(VK_KANA, 0xD4, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M3)
	{
		startTimeM3 = Time::now();
		keybd_event(VK_KANA, 0xD5, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M4)
	{
		startTimeM4 = Time::now();
		keybd_event(VK_KANA, 0xD6, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M5)
	{
		startTimeM5 = Time::now();
		keybd_event(VK_KANA, 0xD7, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M6)
	{
		startTimeM6 = Time::now();
		keybd_event(VK_KANA, 0xD8, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M7)
	{
		startTimeM7 = Time::now();
		keybd_event(VK_KANA, 0xD9, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M8)
	{
		startTimeM8 = Time::now();
		keybd_event(VK_KANA, 0xDA, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M9)
	{
		startTimeM9 = Time::now();
		keybd_event(VK_KANA, 0xE9, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M10)
	{
		startTimeM10 = Time::now();
		keybd_event(VK_KANA, 0xEA, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M11)
	{
		startTimeM11 = Time::now();
		keybd_event(VK_KANA, 0xEB, 0, 0);
	}
	else if (keyId == CorsairKeyMouse_M12)
	{
		startTimeM12 = Time::now();
		keybd_event(VK_KANA, 0xEC, 0, 0);
	}
	else {
		//dont for now
	}
	return;
}

void releaseFunc(CorsairKeyId keyId)
{
	if (keyId == CLK_ScanNextTrack)
	{
		endTime = Time::now();
		//std::chrono::duration<double, std::milli> diff = endTime - startTimeG1;
		std::cout << "here";
	}
	else if (keyId == CorsairKeyKb_G1)
	{
		endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG1;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC1, KEYEVENTF_KEYUP, 0);
		startTimeG1 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G2)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG2;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC2, KEYEVENTF_KEYUP, 0);
		startTimeG2 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G3)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG3;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC3, KEYEVENTF_KEYUP, 0);
		startTimeG3 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G4)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG4;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC4, KEYEVENTF_KEYUP, 0);
		startTimeG4 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G5)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG5;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC5, KEYEVENTF_KEYUP, 0);
		startTimeG5 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G6)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG6;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC6, KEYEVENTF_KEYUP, 0);
		startTimeG6 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G7)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG7;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC7, KEYEVENTF_KEYUP, 0);
		startTimeG7 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G8)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG8;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC8, KEYEVENTF_KEYUP, 0);
		startTimeG8 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G9)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG9;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC9, KEYEVENTF_KEYUP, 0);
		startTimeG9 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G10)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG10;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xCA, KEYEVENTF_KEYUP, 0);
		startTimeG10 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G11)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG11;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xCB, KEYEVENTF_KEYUP, 0);
		startTimeG11 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G12)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG12;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xCC, KEYEVENTF_KEYUP, 0);
		startTimeG12 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G13)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG13;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xCD, KEYEVENTF_KEYUP, 0);
		startTimeG13 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G14)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG14;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xCE, KEYEVENTF_KEYUP, 0);
		startTimeG14 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G15)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG15;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xCF, KEYEVENTF_KEYUP, 0);
		startTimeG15 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G16)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG16;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD0, KEYEVENTF_KEYUP, 0);
		startTimeG16 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G17)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG17;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD1, KEYEVENTF_KEYUP, 0);
		startTimeG17 = Time::now();
	}
	else if (keyId == CorsairKeyKb_G18)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG18;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD2, KEYEVENTF_KEYUP, 0);
		startTimeG18 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M1)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM1;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD3, KEYEVENTF_KEYUP, 0);
		startTimeM1 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M2)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM2;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD4, KEYEVENTF_KEYUP, 0);
		startTimeM2 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M3)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM3;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD5, KEYEVENTF_KEYUP, 0);
		startTimeM3 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M4)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM4;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD6, KEYEVENTF_KEYUP, 0);
		startTimeM4 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M5)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM5;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD7, KEYEVENTF_KEYUP, 0);
		startTimeM5 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M6)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM6;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD8, KEYEVENTF_KEYUP, 0);
		startTimeM6 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M7)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM7;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xD9, KEYEVENTF_KEYUP, 0);
		startTimeM7 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M8)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM8;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xDA, KEYEVENTF_KEYUP, 0);
		startTimeM8 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M9)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM9;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xE9, KEYEVENTF_KEYUP, 0);
		startTimeM9 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M10)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM10;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xEA, KEYEVENTF_KEYUP, 0);
		startTimeM10 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M11)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM11;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xEB, KEYEVENTF_KEYUP, 0);
		startTimeM11 = Time::now();
	}
	else if (keyId == CorsairKeyMouse_M12)
	{
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeM12;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xEC, KEYEVENTF_KEYUP, 0);
		startTimeM12 = Time::now();
	}
	else {
		auto endTime = Time::now();
		std::chrono::duration<double, std::milli> diff = endTime - startTimeG1;
		lastHeldTime = diff.count();
		std::cout << "Time: " << lastHeldTime << " ms\n";
		keybd_event(VK_KANA, 0xC1, KEYEVENTF_KEYUP, 0);
	}
	return;
}

void sendingAnotherMessage()
{
	HWND hWnd = FindWindowA(NULL, scriptName);
	PostMessageA(hWnd, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);
	return;
}

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);








int APIENTRY wWinMain(_In_ HINSTANCE hInstance,  _In_opt_ HINSTANCE hPrevInstance,       _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// TODO: Place code here.
	using namespace std::chrono_literals;
	currentProfile = 999;
	CorsairPerformProtocolHandshake();
	while (const auto error = CorsairGetLastError()) {
		CorsairPerformProtocolHandshake();
		std::cout << "Handshake failed: " << toString(error) << "\nWe will be retrying every 10 seconds, until the process is killed or is otherwise successful." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}

	HWND hWnd = FindWindowA(NULL, scriptName);

	int * pointerToCurrentProfile = &currentProfile;
	int * pointerToLHT = &lastHeldTime;

	/*std::cout << "We are sending the hWnd:  " << hWnd << std::endl
		<< " to " << scriptName << std::endl
		<< " and we are about to send it the pointer message, which is:  " << pointerToCurrentProfile << std::endl
		<< " and also the LHT pointer:  " << pointerToLHT << std::endl;*/

	PostMessageA(hWnd, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);






	//could pass start times into the lambda as reference but it seems overkill
	auto callback = [](void *context, CorsairKeyId keyId, bool pressed) mutable {
		auto ledIdGM = keyIdToLedId.at(keyId);
		CorsairLedColor ledColorGM = { ledIdGM, 0, 0 };
		CorsairGetLedsColors(1, &ledColorGM);
		Context *ctx = static_cast<Context*>(context);

		auto ledId = CLK_Q;
		CorsairLedColor ledColor = { ledId, 0, 0, 0 };
		CorsairGetLedsColors(1, &ledColor);
		profileGetter(ledColor);
		ctx->m_lastPressedKey = keyId;

		if (pressed) {
			presserFunc(keyId, ledColor);
		}
		else if (!pressed) {
			releaseFunc(keyId);
		}
	};

	Context context;
	CorsairRegisterKeypressCallback(callback, &context);


	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}/*
	while (true) {

		std::this_thread::sleep_for(10s);
		if (!mediaKeyProfileChecker())
		{
			break;
		}
	}*/



    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	
    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	const UINT t = 0x5557;
	if (message == t)
	{
		HWND hWnd2 = FindWindowA(NULL, scriptName);
		PostMessageA(hWnd2, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);
	}
	/*sendingAnotherMessage();*/
	//PostMessageA(hWnd2, 0x5556, (WPARAM)pointerToCurrentProfile, (WPARAM)pointerToLHT);
	//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);		
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
