#include "pch.h"
#include "utils.h"
#include "Settings.h"
#include "GameChangableSettingsClass.h"
#include "HooksClass.h"

#include "dpl/LifeNode_MissionComplete.h"
#include "dpl/LifeNode_DebugText.h"
#include "dpl/State_VEdit.h"

#include "dllmain.h"

#define USE_DEFINED_WINDOWSIZE
#define HWND_Width 800
#define HWND_Height 600
#define HWND_Style WS_OVERLAPPEDWINDOW //WS_POPUP | WS_CAPTION | WS_SYSMENU

void OnInitializePlugin()
{
	// Patches based on settings
	if (SettingsMgr != NULL)
	{
		// ping in & ping out radius
		*(float*)(0x6414f8) = SettingsMgr->fInstances_Spawn_Radius - INSTANCES_SPAWN_RADIUS_PING_IN_OFFSET;
		*(float*)(0x641420) = SettingsMgr->fInstances_Spawn_Radius;

		*(float*)(0x6dd660) = SettingsMgr->fVehicles_HeadLight_DegreesAngle;

		// float _11SDrawHelper$m_draw_distance[3]
		*(float*)(0x6cfcb4) = SettingsMgr->fDraw_Distance1;
		*(float*)(0x6cfcb4 + 4) = SettingsMgr->fDraw_Distance2;
		*(float*)(0x6cfcb4 + 8) = SettingsMgr->fDraw_Distance3;

		// show console if the settings allow
		if (SettingsMgr->bShow_Console_Output)
		{
			AllocConsole();
			freopen("CONOUT$", "w", stdout);
			freopen("CONIN$", "r", stdin);
		}

		if (SettingsMgr->bWindowed_Mode)
		{
			printf("Windowed mode on\n");
			Nop(0x575680, 33); // before the hook, to disable the other code stuff
			InjectHook(0x57567C, CreateCustomWindow, PATCH_CALL); // windowed mode / custom window

			// windowMode = SW_SHOWNORMAL
			Patch<char>(0x5FE99F + 1, 1);

			if (SettingsMgr->bPause_Game_In_Windowed_Mode == false)
			{
				WriteAt(0x57168B + 3, "\x00", 1); // all thanks to my ol' helper - Cheat Engine!
			}
		}

		if (SettingsMgr->bBackground_Glow_In_ShaderVer_1)
		{
			Nop(0x623ff7, 11); // if (/*shaderVer < 1*/ && g_iGlowFinalBlend != 0)
		}
	}

#ifdef _SHOW_WINDOW_ON_CREATE
	Nop(0x57572b, 10); // prevent the window from showing more than once
	Nop(0x575735, 7); // prevent the window from updating more than once
#endif

	// Default patches
	WritePointerAt(0x442b4c + 4, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fPedDensityBaseNoPingInRadius));
	WritePointerAt(0x442b44 + 4, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fPedDensityPingMultiplier));
	WritePointerAt(0x4485f5 + 4, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fPedDensitySubtractionNoPingInRadius));
	WritePointerAt(0x448346 + 4, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fPedPingOut));
	WritePointerAt(0x448356 + 4, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fPedPingIn));
	WritePointerAt(0x404275 + 3, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fAICivilianCarGiveUpJourneySquareDistance));
	
	// TODO: maybe fix this... it's for the complete mission debug option
	//Patch(0x647A20, &CLifeNode_MissionComplete::OnUpdate);

	if (SettingsMgr->bAllow_Missions_Debug_Text)
	{
		Patch(0x64836c, &CLifeNode_DebugText::OnInitialise);
		Patch(0x648374, &CLifeNode_DebugText::OnEnable);
	}

	// replace CState_VEdit->Step() with our step_hook, but call the original function as well our custom function
	// this is for the garage camera fix/re-implementation
	Patch(0x643628, &CState_VEdit::Step_Hook);

	//WritePointerAt(0x471f54 + 4, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fInstances_Ping_In));
	//WritePointerAt(0x471f61 + 4, reinterpret_cast<uintptr_t>(&GameChangableSettings::g_fInstances_Ping_Out));

	*(float*)(0x6778e0) = GameChangableSettings::g_fAICivilianCarTopSpeedForward;
	*(float*)(0x6778dc) = GameChangableSettings::g_fAICivilianCarTopSpeedReverse;
	*(float*)(0x6778d8) = GameChangableSettings::g_fAICivilianCarGainGrad;

	if (SettingsMgr->bPS2_Glow_Effects_Settings)
	{
		// Prevent it from being overwrited by D:PL's code
		Nop(0x5ecc3b, 6);
		Nop(0x5ed472, 6);

		InjectHook(0x5ecc3b, HooksClass::PS2_Glow_SFX_Settings_Patch, PATCH_JUMP);
	}

	// HOOKS
	InjectHook(0x465721, HooksClass::Before_OnEnterGarageState, PATCH_JUMP);

	Nop(0x465e30, 7);
	InjectHook(0x465e30, HooksClass::After_OnEnterGarageState, PATCH_JUMP);

	Nop(0x4c4cb9, 9);
	InjectHook(0x4c4cb9, HooksClass::ProcessCommandExtension_Frontend, PATCH_JUMP);

	Nop(0x45acc4, 7);
	InjectHook(0x45acc4, &HooksClass::GameSimulationStep, PATCH_JUMP);

	WriteAt(0x5fc7e6 + 1, "\x09", 1);
	Nop(0x5fc7e3, 3);
	Nop(0x5fc7f1, 9);
	InjectHook(0x5fc7f1, HooksClass::HeapFree_Fix_Validation, PATCH_JUMP);

	InjectHook(0x4a80c9, &CState_Frontend::OnEnterState, PATCH_CALL);

	Nop(0x4aa075, 6);
	InjectHook(0x4aa075, &HooksClass::Custom_Load_Dev_Menu, PATCH_JUMP);

	Nop(0x5AF86C, 5);
	InjectHook(0x5AF86C, &HooksClass::Classic_BurnOut_Hook, PATCH_JUMP);

	Nop(0x49f986, 6);
	InjectHook(0x49f986, &HooksClass::Turn_Signal_Feature, PATCH_JUMP);

	// HRESULT __fastcall EndScene__i4HRESULT(CViewport *viewport)
	Nop(0x5e455b, 15); // nop all except 'ret' (return)
	InjectHook(0x5e455b, &HooksClass::D3DDevice_EndScene_Patches, PATCH_JUMP); // re-direct the function to ours, like a thunk function

	//InjectHook(0x4b7f36, HooksClass::GameOverlays_DrawHooked_Debug);

	//Nop(0x4b9ef1, 6);
	//InjectHook(0x4b9ef1, HooksClass::OverheadMap_DrawHooked_Debug);

	if (SettingsMgr->bDev_Menu_On)
	{
		WriteAt(0x459f8e + 1, "\x01", 1); // pause_devMenuBTN->SetRenderState(1);
		
		// NOTE: for your safety you can't access frontend dev menu by default!
		// it will crash the game, so stick to the pause menu dev menu :/
		//WriteAt(0x4AA523 + 1, "\x01", 1); // frontend_devMenuBTN->SetRenderState(1);
	
		//Nop(0x459f8c, 14);
	}
	if (SettingsMgr->bMinimap_Driver3_Goons)
	{
		WriteAt(0x4bdf71 + 3, "\x4C", 1); // ambColour.Y = 0;
		//WriteAt(0x4bdf92 + 7, "\x05\x00\x35", 4); // instance.hModel = MinimapIcon_AlertedCop;
		
		// Prevent the player icon into becoming one of them
		Nop(0x4bdf47, 6);
		InjectHook(0x4bdf47, HooksClass::OnCase_EMapItem_Player_CustomBlock, PATCH_JUMP);
		Nop(0x4bdf92, 11);
		InjectHook(0x4bdf92, HooksClass::DrawMapItem_ModelCheck, PATCH_JUMP);
	}

	printf("DPLFusionFix is initialized\n");
}

static const char* newHWNDtitle = "Driver: Parallel Lines";
HWND CreateCustomWindow(HINSTANCE hamsterModule, DWORD zero)
{
	char strHamsterMainWndClass[16];
	strncpy(strHamsterMainWndClass, "HamsterMainWnd", 15);

	// else use current from the user's PC
	int width =
#ifdef USE_DEFINED_WINDOWSIZE
		HWND_Width
#else
		GetSystemMetrics(SM_CXSCREEN)
#endif

		;

	int height =
#ifdef USE_DEFINED_WINDOWSIZE
		HWND_Height
#else
		GetSystemMetrics(SM_CYSCREEN)
#endif

		;

	HWND wnd = CreateWindowExA(0, strHamsterMainWndClass, newHWNDtitle, HWND_Style, CW_USEDEFAULT, CW_USEDEFAULT, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
		(HWND)NULL, (HMENU)NULL, hamsterModule, (LPVOID)NULL);

#ifdef _SHOW_WINDOW_ON_CREATE
		ShowWindow(wnd, SW_SHOWNORMAL);
#endif

	return wnd;
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		OnInitializePlugin();
	}
}
