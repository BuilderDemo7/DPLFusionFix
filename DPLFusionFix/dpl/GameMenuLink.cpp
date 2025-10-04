#include "GameMenuLink.h"

int CGameMenuLink::GetVTableAddress()
{
	return *(int*)(this);
}

void CGameMenuLink::SetState(EMenuState eState)
{
	((void(__thiscall*)(CGameMenuLink*, EMenuState))*(int*)(GetVTableAddress() + 0x1C))(this, eState);
}

void CGameMenuLink::SetText(wchar_t* szText)
{
	((void(__thiscall*)(CGameMenuLink*, wchar_t*))*(int*)(GetVTableAddress() + 0x20))(this, szText);
}

void CGameMenuLink::SetDebugText(char* szText)
{
	((void(__thiscall*)(CGameMenuLink*, char*))*(int*)(GetVTableAddress() + 0x24))(this, szText);
}

void CGameMenuLink::SetValue(int nValue)
{
	((void(__thiscall*)(CGameMenuLink*, int))*(int*)(GetVTableAddress() + 0x34))(this, nValue);
}

CGameMenuLink* GetGameMenuLink()
{
	return *(CGameMenuLink**)0x70C660;
}