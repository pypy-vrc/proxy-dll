#include "stdafx.h"
#pragma comment(linker, "/EXPORT:EmptyWorkingSet=__stub0,@1")
#pragma comment(linker, "/EXPORT:EnumDeviceDrivers=__stub1,@2")
#pragma comment(linker, "/EXPORT:EnumPageFilesA=__stub2,@3")
#pragma comment(linker, "/EXPORT:EnumPageFilesW=__stub3,@4")
#pragma comment(linker, "/EXPORT:EnumProcessModules=__stub4,@5")
#pragma comment(linker, "/EXPORT:EnumProcessModulesEx=__stub5,@6")
#pragma comment(linker, "/EXPORT:EnumProcesses=__stub6,@7")
#pragma comment(linker, "/EXPORT:GetDeviceDriverBaseNameA=__stub7,@8")
#pragma comment(linker, "/EXPORT:GetDeviceDriverBaseNameW=__stub8,@9")
#pragma comment(linker, "/EXPORT:GetDeviceDriverFileNameA=__stub9,@10")
#pragma comment(linker, "/EXPORT:GetDeviceDriverFileNameW=__stub10,@11")
#pragma comment(linker, "/EXPORT:GetMappedFileNameA=__stub11,@12")
#pragma comment(linker, "/EXPORT:GetMappedFileNameW=__stub12,@13")
#pragma comment(linker, "/EXPORT:GetModuleBaseNameA=__stub13,@14")
#pragma comment(linker, "/EXPORT:GetModuleBaseNameW=__stub14,@15")
#pragma comment(linker, "/EXPORT:GetModuleFileNameExA=__stub15,@16")
#pragma comment(linker, "/EXPORT:GetModuleFileNameExW=__stub16,@17")
#pragma comment(linker, "/EXPORT:GetModuleInformation=__stub17,@18")
#pragma comment(linker, "/EXPORT:GetPerformanceInfo=__stub18,@19")
#pragma comment(linker, "/EXPORT:GetProcessImageFileNameA=__stub19,@20")
#pragma comment(linker, "/EXPORT:GetProcessImageFileNameW=__stub20,@21")
#pragma comment(linker, "/EXPORT:GetProcessMemoryInfo=__stub21,@22")
#pragma comment(linker, "/EXPORT:GetWsChanges=__stub22,@23")
#pragma comment(linker, "/EXPORT:GetWsChangesEx=__stub23,@24")
#pragma comment(linker, "/EXPORT:InitializeProcessForWsWatch=__stub24,@25")
#pragma comment(linker, "/EXPORT:QueryWorkingSet=__stub25,@26")
#pragma comment(linker, "/EXPORT:QueryWorkingSetEx=__stub26,@27")
static void *a_[27];
#define _($) __declspec(naked) _stub##$() { __asm jmp a_[$] }
_(0)_(1)_(2)_(3)_(4)_(5)_(6)_(7)_(8)_(9)_(10)_(11)_(12)_(13)_(14)_(15)_(16)_(17)_(18)_(19)_(20)_(21)_(22)_(23)_(24)_(25)_(26)
#undef _
BOOL proxy(void) {
	char s[256];
	HMODULE m = LoadLibrary((strcpy(&s[GetSystemDirectory(s, sizeof(s) - 16u)], "\\PSAPI.DLL"), s));
	if (!m)
		return FALSE;
	a_[0] = GetProcAddress(m, "EmptyWorkingSet");
	a_[1] = GetProcAddress(m, "EnumDeviceDrivers");
	a_[2] = GetProcAddress(m, "EnumPageFilesA");
	a_[3] = GetProcAddress(m, "EnumPageFilesW");
	a_[4] = GetProcAddress(m, "EnumProcessModules");
	a_[5] = GetProcAddress(m, "EnumProcessModulesEx");
	a_[6] = GetProcAddress(m, "EnumProcesses");
	a_[7] = GetProcAddress(m, "GetDeviceDriverBaseNameA");
	a_[8] = GetProcAddress(m, "GetDeviceDriverBaseNameW");
	a_[9] = GetProcAddress(m, "GetDeviceDriverFileNameA");
	a_[10] = GetProcAddress(m, "GetDeviceDriverFileNameW");
	a_[11] = GetProcAddress(m, "GetMappedFileNameA");
	a_[12] = GetProcAddress(m, "GetMappedFileNameW");
	a_[13] = GetProcAddress(m, "GetModuleBaseNameA");
	a_[14] = GetProcAddress(m, "GetModuleBaseNameW");
	a_[15] = GetProcAddress(m, "GetModuleFileNameExA");
	a_[16] = GetProcAddress(m, "GetModuleFileNameExW");
	a_[17] = GetProcAddress(m, "GetModuleInformation");
	a_[18] = GetProcAddress(m, "GetPerformanceInfo");
	a_[19] = GetProcAddress(m, "GetProcessImageFileNameA");
	a_[20] = GetProcAddress(m, "GetProcessImageFileNameW");
	a_[21] = GetProcAddress(m, "GetProcessMemoryInfo");
	a_[22] = GetProcAddress(m, "GetWsChanges");
	a_[23] = GetProcAddress(m, "GetWsChangesEx");
	a_[24] = GetProcAddress(m, "InitializeProcessForWsWatch");
	a_[25] = GetProcAddress(m, "QueryWorkingSet");
	a_[26] = GetProcAddress(m, "QueryWorkingSetEx");
	return TRUE;
}