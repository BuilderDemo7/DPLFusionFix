#include "MenuManager.h"

CMenuManager* GetMenuManager()
{
	return *(CMenuManager**)0x70c658;
}

int CMenuManager::GetVTableAddress()
{
	return *(int*)(this);
}

// To prevent "LoadMenu" definition from windows.h or something...
void CMenuManager::LoadMenu_THUNK(const char* szMenuFileName, EMenu eMenuId, bool bLoadToSuperregion)
{
	this->LoadMenu(szMenuFileName, eMenuId, bLoadToSuperregion);
}

void CMenuManager::LoadMenu(const char* szMenuFileName, EMenu eMenuId, bool bLoadToSuperregion)
{
	((void(__thiscall*)(CMenuManager*, const char*, EMenu, bool))*(int*)(GetVTableAddress() + 0x18))(this, szMenuFileName, eMenuId, bLoadToSuperregion);
}

void CMenuManager::UnLoadMenu(EMenu eMenuId)
{
	((void(__thiscall*)(CMenuManager*, EMenu))*(int*)(GetVTableAddress() + 0x1C))(this, eMenuId);
}

bool CMenuManager::IsLoaded(EMenu eMenuId)
{
	return ((bool(__thiscall*)(CMenuManager*, EMenu))*(int*)(GetVTableAddress() + 0x20))(this, eMenuId);
}

void CMenuManager::ActivateMenu(EMenu eMenuId)
{
	((void(__thiscall*)(CMenuManager*, EMenu))*(int*)(GetVTableAddress() + 0x24))(this, eMenuId);
}

void CMenuManager::DeActivateMenu(EMenu eMenuId)
{
	((void(__thiscall*)(CMenuManager*, EMenu))*(int*)(GetVTableAddress() + 0x28))(this, eMenuId);
}