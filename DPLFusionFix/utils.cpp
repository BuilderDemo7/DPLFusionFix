#include "utils.h"

void WriteAt(unsigned int address, const char* buffer, size_t size)
{
	DWORD		dwProtect;
	VirtualProtect((void*)address, size, PAGE_EXECUTE_READWRITE, &dwProtect);
	memcpy((void*)address, buffer, size);
	VirtualProtect((void*)address, size, dwProtect, &dwProtect);
}

void WriteAt(unsigned int address, int integer)
{
	DWORD		dwProtect;
	VirtualProtect((void*)address, sizeof(int), PAGE_EXECUTE_READWRITE, &dwProtect);
	memcpy((void*)address, (void*)integer, sizeof(int));
	VirtualProtect((void*)address, sizeof(int), dwProtect, &dwProtect);
}

void WritePointerAt(unsigned int address, intptr_t ptr)
{
	DWORD dwProtect;
	VirtualProtect((void*)address, sizeof(ptr), PAGE_EXECUTE_READWRITE, &dwProtect);
	memcpy((void*)address, &ptr, sizeof(ptr));
	VirtualProtect((void*)address, sizeof(ptr), dwProtect, &dwProtect);
}