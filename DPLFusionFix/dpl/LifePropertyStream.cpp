#include "LifePropertyStream.h"

bool CLifePropertyStream::GetWireCollection(char *pszName, WireCollection *property)
{
	return ((bool(__thiscall*)(CLifePropertyStream*, char*, WireCollection*))0x48419f)(this, pszName, property);
}

bool CLifePropertyStream::GetString(char *pszName, char **property)
{
	return ((bool(__thiscall*)(CLifePropertyStream*, char*, char**))0x48449f)(this, pszName, property);
}