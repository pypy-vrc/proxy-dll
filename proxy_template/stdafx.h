#pragma once
#define STRICT
#define _WIN32_WINNT 0x600
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(push, 3)
#include <winsock2.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#pragma intrinsic(_lrotl, _lrotr, _rotl, _rotr, _strset, abs, fabs, labs, memcmp, memcpy, memset, strcat, strcmp, strcpy, strlen)
#pragma warning(pop)
#pragma warning(disable : 100 127 152 514 706)
extern HINSTANCE instance_;
//
// app
//
extern void cleanup(void);
extern BOOL setup(void);
#pragma hdrstop