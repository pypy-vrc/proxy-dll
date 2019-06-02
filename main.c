#pragma comment(linker, "/OPT:NOWIN98")
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#pragma hdrstop

int main(int argc, const char **argv) {
	FILE *out = fopen("proxy.c", "w");
	if (out) {
		HMODULE module = LoadLibrary("VERSION.DLL");
		if (module) {
			char name[256];
			if (GetModuleFileName(module, name, sizeof(name))) {
				IMAGE_EXPORT_DIRECTORY *d = (IMAGE_EXPORT_DIRECTORY *)((unsigned)module + ((IMAGE_NT_HEADERS *)((unsigned)module + ((IMAGE_DOS_HEADER *)module)->e_lfanew))->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
				if ((unsigned)d != (unsigned)module) {
					unsigned i, j;
					printf("* total %u functions\n", d->NumberOfFunctions);
					system("pause");
					fputs("#include \"stdafx.h\"\n", out);
					for (i = 0u; i < d->NumberOfFunctions; ++i) {
						char *exported_name = NULL;
						for (j = 0u; j < d->NumberOfNames; ++j)
							if (i == ((WORD *)((unsigned)module + d->AddressOfNameOrdinals))[j]) {
								exported_name = (char *)((unsigned)module + ((DWORD *)((unsigned)module + d->AddressOfNames))[j]);
								break;
							}
						if (exported_name)
							if (strchr(exported_name, '@'))
								fprintf(out, "#pragma comment(linker, \"/EXPORT:%s=_stub%u,@%u\")\n", exported_name, i, d->Base + i);
							else
								fprintf(out, "#pragma comment(linker, \"/EXPORT:%s=__stub%u,@%u\")\n", exported_name, i, d->Base + i);
						else
							fprintf(out, "#pragma comment(linker, \"/EXPORT:__stub%u,@%u,NONAME\")\n", i, d->Base + i);
						printf("%s,@%u\n", exported_name, d->Base + i);
					}
					fprintf(out, "static void *a_[%u];\n", d->NumberOfFunctions);
					fputs("#define _($) __declspec(naked) void _stub##$() { __asm jmp a_[$] }\n", out);
					for (i = 0u; i < d->NumberOfFunctions; ++i)
						fprintf(out, "_(%u)", i);
					fprintf(out,
						"\n#undef _\n"
						"HMODULE proxy(void) {\n"
						"	char a[256];\n"
						"	HMODULE m = LoadLibrary((strcpy(&a[GetSystemDirectory(a, sizeof(a) - 16u)], \"\\\\%s\"), a));\n"
						"	if (m) {\n", strrchr(name, '\\') + 1u);
					for (i = 0u; i < d->NumberOfFunctions; ++i) {
						char *exported_name = NULL;
						for (j = 0u; j < d->NumberOfNames; ++j)
							if (i == ((WORD *)((unsigned)module + d->AddressOfNameOrdinals))[j]) {
								exported_name = (char *)((unsigned)module + ((DWORD *)((unsigned)module + d->AddressOfNames))[j]);
								break;
							}
						if (exported_name)
							fprintf(out, "		a_[%u] = GetProcAddress(m, \"%s\");\n", i, exported_name);
						else
							fprintf(out, "		a_[%u] = GetProcAddress(m, (char *)%u);\n", i, d->Base + i);
					}
					fputs("	}\n	return m;\n}", out);
				}
			}
		}
		fclose(out);
	}
	system("notepad proxy.c");
	return 0;
}