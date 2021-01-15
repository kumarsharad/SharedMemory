// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdlib.h>
#include "SharedMemoryLibraray.h"
#define _CRT_SECURE_NO_WARNINGS

#pragma data_seg("shared")
CHAR szString[MAX_LENGTH + 1] = { '\0' };
#pragma data_seg()

#pragma comment(linker,"/SECTION:shared,RWS")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    return TRUE;
}

EXPORT BOOL CALLBACK AddString(PCHAR pStringIn)
{
	int iLength = 0;
	if ((iLength = strlen(pStringIn)) == 0)
		return FALSE;
	strcpy_s(szString, iLength+1, pStringIn);
	return TRUE;
}

EXPORT BOOL CALLBACK DeleteString()
{
	szString[0] = '\0';
	return TRUE;
}
EXPORT BOOL CALLBACK GetString(PCHAR pStringOut)
{
	int iLength = 0;
	if ((iLength = strlen(szString)) == 0)
		return FALSE;
	strcpy_s(pStringOut, iLength+1, szString);
	return TRUE;
}
