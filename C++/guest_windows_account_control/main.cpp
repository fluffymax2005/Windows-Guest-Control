#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <windows.h> 
#include <lm.h>
#include <exception>

#define ARGC 3

int wmain(int argc, wchar_t* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*DWORD dwLevel = 1003; // user password level
	USER_INFO_1003 ui;
	NET_API_STATUS nStatus;

	
	if (argc != ARGC) {
		fwprintf(stderr, L"Usage: %s \\\\ServerName Username\n", argv[0]);
		exit(1);
	}

	ui.usri1003_password = argv[2];

	nStatus = NetUserSetInfo(NULL, argv[1], dwLevel, (LPBYTE)&ui, NULL);*/

	DWORD dwLevel = 1011; // user password level
	USER_INFO_1011 ui;
	NET_API_STATUS nStatus;


	//if (argc != ARGC) {
	//	fwprintf(stderr, L"Usage: %s \\\\ServerName Username\n", argv[0]);
	//	exit(1);
	//}

	ui.usri1011_full_name = (WCHAR*)L"Test1";

	nStatus = NetUserSetInfo(NULL, ui.usri1011_full_name, dwLevel, (LPBYTE)&ui, NULL);



	if (nStatus == NERR_Success)
		fwprintf(stderr, L"User's password changed successfully");
	else
		fwprintf(stderr, L"A system error has occurred: %d\n", nStatus);
	return 0;
}
