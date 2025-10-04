#pragma once
#include "dpl/LifeSystem.h"
#include "dpl/State_Frontend.h"

#include "dpl/DebugOptions.h"
#include "Settings.h"
#include "GameChangableSettingsClass.h"

#include <d3d9.h>

#include "dpl/common.h"

extern bool D3DDevice_WireFrame_On;

class HooksClass
{
public:
	static void Before_OnEnterGarageState();
	static void After_OnEnterGarageState();
	
	static void OnCase_EMapItem_Player_CustomBlock();
	static void DrawMapItem_ModelCheck();

	static void ProcessCommandExtension_Frontend();

	static void GameSimulationStep();

	static void GameOverlays_DrawHooked_Debug();
	static void OverheadMap_DrawHooked_Debug();

	static void HeapFree_Fix_Validation();

	static void PS2_Glow_SFX_Settings_Patch();

	static void Custom_Load_Dev_Menu();

	static void Classic_BurnOut_Hook();
	static void Turn_Signal_Feature();

	static HRESULT __fastcall D3DDevice_EndScene_Patches(int Viewport);
};

