#include "GameOverlayManager.h"

COverheadMap* GetOverheadMap()
{
	return (COverheadMap*)(*(int*)(*(int*)(0x0070C558) + 0x34));
}

CGameOverlayManager* GetGameOverlayManager()
{
	return (CGameOverlayManager*)(*(int*)(0x0070C558));
}

void CGameOverlayManager::Draw(int Viewport)
{
	((void(__thiscall*)(CGameOverlayManager*, int))0x4B7F36)(this, Viewport);
}

void CGameOverlayManager::DrawHooked(int Viewport)
{
	if (m_bDisableHUD)
		return;
	Draw(Viewport);
}

void CGameOverlayManager::Toggle(bool toggled)
{
	((void(__thiscall*)(CGameOverlayManager*, bool))0x5718A7)(this, toggled);
}

void COverheadMap_Hook::Draw(int Viewport)
{
	((void(__thiscall*)(COverheadMap_Hook*, int))0x4B9EF1)(this, Viewport);
}

void COverheadMap_Hook::DrawHooked(int Viewport)
{
	if (m_bDisableHUD)
		return;
	Draw(Viewport);
}
