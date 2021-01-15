#pragma once
#include <Windows.h>

#define DDE __declspec (dllexport)
constexpr auto MAX_LENGTH = 64;

#ifdef __cplusplus
#define	EXPORT extern "C" DDE
#else
#define	EXPORT DDE
#endif

EXPORT BOOL CALLBACK AddString(PCHAR);
EXPORT BOOL CALLBACK DeleteString();
EXPORT BOOL CALLBACK GetString(PCHAR);