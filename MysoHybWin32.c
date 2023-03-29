#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>

BOOL WINAPI consoleHandler(DWORD signal) {
	switch (signal)
	{
	case CTRL_C_EVENT:
		printf("Ctrl-C handled\n");
		exit(0);
		return TRUE;
	default:
		return FALSE;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	BOOL WINAPI bSwitch = TRUE;
	BOOL WINAPI bRunning = TRUE;

	if (!SetConsoleCtrlHandler(consoleHandler, TRUE)) {
		printf("\nERROR: Could not set control handler"); 
		return 1;
	}

	while (1) {
		if (bSwitch == TRUE)
		{
			SetCursorPos(200, 200);
			bSwitch = FALSE;
		} 
		else 
		{
			SetCursorPos(100, 100);
			bSwitch = TRUE;
		}		
		Sleep(1000);
	}
	return 0;
}
