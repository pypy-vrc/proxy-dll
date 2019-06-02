#include "stdafx.h"
#if (_MSC_VER < 1300)
#pragma comment(linker, "/OPT:NOWIN98")
#endif

extern BOOL proxy(void);

HINSTANCE instance_;

BOOL APIENTRY DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
	BOOL target = TRUE;
	switch (reason) {
	case DLL_PROCESS_DETACH:
		if (target)
			cleanup();
		break;
	case DLL_PROCESS_ATTACH:
		SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
		DisableThreadLibraryCalls(instance_ = instance);
		return proxy() && (!target || setup());
	}
	return TRUE;
}