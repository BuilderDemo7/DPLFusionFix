#include "GenericStringManager.h"

wchar_t* CGenericStringManager::GetString(EGenericTextID eID, int index)
{
	return ((wchar_t* (__thiscall*)(CGenericStringManager*, EGenericTextID, int))0x456248)(this, eID, index);
}

CGenericStringManager* GetGenericStringManager()
{
	return *(CGenericStringManager**)0x70C7B0;
}