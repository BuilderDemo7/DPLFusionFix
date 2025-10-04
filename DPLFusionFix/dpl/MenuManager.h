#pragma once
#include "EMenu.h"

class CMenuManager
{
public:
	int GetVTableAddress();

	// To prevent "LoadMenu" definition from windows.h or something...
	void LoadMenu_THUNK(const char* szMenuFileName, EMenu eMenuId, bool bLoadToSuperregion);

	void DeActivateMenu(EMenu eMenuID);
	void ActivateMenu(EMenu eMenuID);

	bool IsLoaded(EMenu eMenuId);
	void LoadMenu(const char* szMenuFileName, EMenu eMenuId, bool bLoadToSuperregion);
	void UnLoadMenu(EMenu eMenuId);
};

CMenuManager* GetMenuManager();