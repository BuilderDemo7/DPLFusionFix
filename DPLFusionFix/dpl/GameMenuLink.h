#pragma once
#include "EMenuState.h"

class CGameMenuLink
{
public:
	int GetVTableAddress();

	void SetState(EMenuState eState);
	void SetText(wchar_t* szText);
	void SetDebugText(char* szText);
	void SetValue(int nValue);
};

CGameMenuLink* GetGameMenuLink();