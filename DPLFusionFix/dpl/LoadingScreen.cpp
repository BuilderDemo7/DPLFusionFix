#include "LoadingScreen.h"

CLoadingScreen* GetLoadingScreen()
{
	return (CLoadingScreen*)(*(int*)0x70C798);
}

void CLoadingScreen::Activate(bool relocating)
{
	((void* (__thiscall*)(CLoadingScreen*, bool))0x4A76EF)(this, relocating);
}

void CLoadingScreen::Deactivate()
{
	((void* (__thiscall*)(CLoadingScreen*))0x4A7732)(this);
}

// 00563280 - CLoadingScreen::Update() (or draw?)