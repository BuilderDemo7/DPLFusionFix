// NOTE: This was supposed to be Profile Settings but it's used for frontend state
// NOTE: Frontend state singleton should be at 0x70C740 and this singleton is at 0x70C7A0

#include "State_Frontend.h"

const char* g_CurrentBuildName = "Release 1.01 - April 4 2007 - 10:19:57";
const char* g_DebugOptionsSeperator = "==================";

// Renderer
const char* g_ProjectedHeadLightFOV = "Projected head light FOV";
const char* g_DrawDistance1 = "Objects High Draw Distance";
const char* g_DrawDistance2 = "Objects Medium Draw Distance";
const char* g_DrawDistance3 = "Objects Low Draw Distance";

const char* g_WireFrameMode = "Wireframe Mode (TEST)";

// Game (from prototypes)
const char* g_ShowVersion = "Show Version";
const char* g_ShowCamera = "Show Camera";
const char* g_ShowFPS = "Show FPS";
const char* g_CompleteMission = "Complete Mission";
const char* g_Display_HUD_and_Map = "Display HUD and Map";
const char* g_Take_Screenshot_With_R3 = "Take screenshot with R3";
const char* g_PAD2_R3_toggles_Sim = "PAD2 R3 toggles simulation";
const char* g_PAD2_DPAD_controls_zoom = "PAD2 DPAD controls zoom";
const char* g_ShowTime = "Show time";
const char* g_OverrideTime = "Override Time";
const char* g_SetTime = "Set Time (hours)";
const char* g_OverrideRateOfTime = "Override Rate of Time";
const char* g_SetRateOfTime = "Set Rate Of Time [seconds per hour]";
const char* g_Show_Overstretched_Spool_Requests = "Show overstretched spool requests";

// Custom Game options
const char* g_NoCollisions = "No Physics Collision Decisions";
const char* g_DisableLoadingScreens = "Disable Loading Screens [prevents infinite loading]";
const char* g_InvincibleToWater = "Player Invincible To Water";
const char* g_PlayerAlwaysEnabled = "Player Always Enabled [move in ingame-cutscenes]";
const char* g_OverrideGameDifficulty = "Override Game Difficulty";
const char* g_SetGameDifficulty = "Set Game Difficulty";
const char* g_SetOdometerDist = "Set Odometer Distance";
const char* g_CopSkinAsset = "Cop Skin Asset";
const char* g_CopCarAsset = "Cop Car Asset";
const char* g_Cop2006InitWep = "Cop 2006 Initial Weapon";
const char* g_Cop1978InitWep = "Cop 1978 Initial Weapon";

const char* g_LFSPingOut = "Life System Instances Ping Out";
const char* g_LFSPingIn = "Life System Instances Ping In";
const char* g_AICivilianCarTopSpeedForward = "AI Civilian Car Top Speed Forward";
const char* g_AICivilianCarTopSpeedReverse = "AI Civilian Car Top Speed Reverse";
const char* g_AICivilianCarGainGrad = "AI Civilian Car Gain Grad";
const char* g_AICivilianCarGiveUpJourneyDist = "AI Civilian Car Give Up Journey Square Distance";

const char* CState_Frontend::m_pszGameDebugOptions[] = {
	// Prototypes debug options
	g_ShowVersion,
	g_ShowCamera,
	g_ShowFPS,
	g_CompleteMission,
	g_Display_HUD_and_Map,
	g_Take_Screenshot_With_R3,
	g_PAD2_R3_toggles_Sim,
	g_PAD2_DPAD_controls_zoom,
	g_ShowTime,
	g_OverrideTime,
	g_SetTime,
	g_OverrideRateOfTime,
	g_SetRateOfTime,
	g_Show_Overstretched_Spool_Requests,

	// Our debug options :D
	"== DRIVER: Parallel Lines - Fusion Fix ==",

	g_NoCollisions,
	g_DisableLoadingScreens,
	g_InvincibleToWater,
	g_PlayerAlwaysEnabled,
	g_OverrideGameDifficulty,
	g_SetGameDifficulty,
	g_SetOdometerDist,

	g_DebugOptionsSeperator,

	g_CopSkinAsset,
	g_CopCarAsset,

	g_Cop2006InitWep,
	g_Cop1978InitWep,

	g_DebugOptionsSeperator,

	g_LFSPingOut,
	g_LFSPingIn,

	g_DebugOptionsSeperator,

	g_AICivilianCarTopSpeedForward,
	g_AICivilianCarTopSpeedReverse,
	g_AICivilianCarGainGrad,
	g_AICivilianCarGiveUpJourneyDist

	// put another seperator here if there's more options
};

const char* CState_Frontend::m_pszCustomRendererDebugOptions[] = {
	"== Below options requires mission restart ==",

	g_DrawDistance1,
	g_DrawDistance2,
	g_DrawDistance3,

	"== Direct3D9 Stuff ==",

	g_WireFrameMode,

	g_DebugOptionsSeperator // reserved for the original debug renderer options
};

eDebugOptionsType CState_Frontend::m_eDebugOptionsType = eDebugOptions_Game;
int CState_Frontend::m_debugOffset = 0;
int CState_Frontend::m_debugOption = 0;

char* FMVName1 = "FMV\\ATARI.XMV";
char* FMVName2 = "FMV\\ATTRACT.XMV";
char* FMVName3 = "FMV\\CREDITS.XMV";
char* FMVName4 = "FMV\\FRONTEND.XMV";
char* FMVName5 = "FMV\\LOGO.XMV";

int CState_Frontend::m_iPreviewFMVId = 0;
int CState_Frontend::m_iPreviewFMVCount = 5;
char* CState_Frontend::m_pszFMVName = FMVName1;

// Thank you, Mark, as you did this for Driv3r
static int GetDebugOptionIndex(const char *message)
{
	if (!_stricmp(message, "DebugOption0")) return 0;
	if (!_stricmp(message, "DebugOption1")) return 1;
	if (!_stricmp(message, "DebugOption2")) return 2;
	if (!_stricmp(message, "DebugOption3")) return 3;
	if (!_stricmp(message, "DebugOption4")) return 4;
	if (!_stricmp(message, "DebugOption5")) return 5;
	if (!_stricmp(message, "DebugOption6")) return 6;
	if (!_stricmp(message, "DebugOption7")) return 7;
	if (!_stricmp(message, "DebugOption8")) return 8;
	if (!_stricmp(message, "DebugOption9")) return 9;

	return -1;
}

static int GetOriginalRendererDebugOptionValue(char* optionName)
{
	SDebugOption* ogopt_base = (SDebugOption*)PTR_ORIGINAL_DBG_RENDERER_OPTIONS;
	for (int id = 0; id < NUMBER_OF_ORIGINAL_DBG_RENDERER_OPTIONS; id++)
	{
		SDebugOption* ogopt = &ogopt_base[id];

		if (_stricmp(ogopt->szName, optionName) == 0)
		{
			return ogopt->iValue;
		}
	}

	return 0;
}

static void SetOriginalRendererDebugOptionValue(char* optionName, int value, bool canRoll = true)
{
	SDebugOption* ogopt_base = (SDebugOption*)PTR_ORIGINAL_DBG_RENDERER_OPTIONS;
	for (int id = 0; id < NUMBER_OF_ORIGINAL_DBG_RENDERER_OPTIONS; id++)
	{
		SDebugOption* ogopt = &ogopt_base[id];

		if (_stricmp(ogopt->szName, optionName) == 0)
		{
			int limitedValue = value;

			if (!canRoll)
			{
				if (limitedValue > ogopt->iMaxValue)
					limitedValue = ogopt->iMaxValue;
				if (limitedValue < ogopt->iMinValue)
					limitedValue = ogopt->iMinValue;
			}
			else
			{
				if (limitedValue > ogopt->iMaxValue)
					limitedValue = ogopt->iMinValue;
				if (limitedValue < ogopt->iMinValue)
					limitedValue = ogopt->iMaxValue;
			}

			ogopt->iValue = limitedValue;

			break;
		}
	}
}

static int GetDebugOptionValue(char* optionName)
{
	//if (eType == eDebugOptions_Game)
	{
		if (_stricmp(optionName, g_ProjectedHeadLightFOV) == 0)
		{
			return (int)(*(float*)(0x6dd660));
		}
		else if (_stricmp(optionName, g_CopCarAsset) == 0)
		{
			return *(int*)(0x6e7464);
		}
		else if (_stricmp(optionName, g_CopSkinAsset) == 0)
		{
			return *(int*)(0x6e7468);
		}
		else if (_stricmp(optionName, g_Cop2006InitWep) == 0)
		{
			return (int)*(char*)(0x430046 + 0x1);
		}
		else if (_stricmp(optionName, g_Cop1978InitWep) == 0)
		{
			return (int)*(char*)(0x43004a + 0x1);
		}
		else if (_stricmp(optionName, g_LFSPingOut) == 0)
		{
			return (int)(*(float*)(0x641420));
		}
		else if (_stricmp(optionName, g_LFSPingIn) == 0)
		{
			return (int)(*(float*)(0x6414f8));
		}
		else if (_stricmp(optionName, g_DrawDistance1) == 0)
		{
			return (int)(*(float*)(0x6cfcb4));
		}
		else if (_stricmp(optionName, g_DrawDistance2) == 0)
		{
			return (int)(*(float*)(0x6cfcb4 + 4));
		}
		else if (_stricmp(optionName, g_DrawDistance3) == 0)
		{
			return (int)(*(float*)(0x6cfcb4 + 8));
		}
		else if (_stricmp(optionName, g_WireFrameMode) == 0)
		{
			return D3DDevice_WireFrame_On ? 1 : 0;
		}
		else if (_stricmp(optionName, g_AICivilianCarTopSpeedForward) == 0)
		{
			return (int)GameChangableSettings::g_fAICivilianCarTopSpeedForward;
		}
		else if (_stricmp(optionName, g_AICivilianCarTopSpeedReverse) == 0)
		{
			return (int)GameChangableSettings::g_fAICivilianCarTopSpeedReverse;
		}
		else if (_stricmp(optionName, g_AICivilianCarGainGrad) == 0)
		{
			return (int)GameChangableSettings::g_fAICivilianCarGainGrad;
		}
		else if (_stricmp(optionName, g_AICivilianCarGiveUpJourneyDist) == 0)
		{
			return (int)GameChangableSettings::g_fAICivilianCarGiveUpJourneySquareDistance;
		}
		else if (_stricmp(optionName, g_ShowVersion) == 0)
		{
			return bDebug_ShowVersion ? 1 : 0;
		}
		else if (_stricmp(optionName, g_ShowFPS) == 0)
		{
			return bDebug_ShowFPS ? 1 : 0;
		}
		else if (_stricmp(optionName, g_CompleteMission) == 0)
		{
			return bDebug_CompleteMission ? 1 : 0;
		}
		else if (_stricmp(optionName, g_Display_HUD_and_Map) == 0)
		{
			return bDebug_Display_HUD_and_Map ? 1 : 0;
		}
		else if (_stricmp(optionName, g_SetTime) == 0)
		{
			return bDebug_SetTimeHours;
		}
		else if (_stricmp(optionName, g_OverrideTime) == 0)
		{
			return bDebug_OverrideTime ? 1 : 0;
		}
		else if (_stricmp(optionName, g_PlayerAlwaysEnabled) == 0)
		{
			return bDebug_PlayerAlwaysEnabled ? 1 : 0;
		}
		else if (_stricmp(optionName, g_OverrideGameDifficulty) == 0)
		{
			return bDebug_OverrideGameDiff ? 1 : 0;
		}
		else if (_stricmp(optionName, g_SetGameDifficulty) == 0)
		{
			return bDebug_SetGameDiff;
		}
		else if (_stricmp(optionName, g_SetOdometerDist) == 0)
		{
			CProfileSettings* profSet = GetProfileSettings();
			int val = 0;
			if (profSet != NULL)
			{
				val = (int)(profSet->GetOdometer() * 0.000621f);
			}
			return val;
		}
		else if (_stricmp(optionName, g_DisableLoadingScreens) == 0)
		{
			return bDebug_DisableLoadingScreen ? 1 : 0;
		}
		else if (_stricmp(optionName, g_NoCollisions) == 0)
		{
			return bDebug_NoCollisions ? 1 : 0;
		}
		else if (_stricmp(optionName, g_InvincibleToWater) == 0)
		{
			return bDebug_InvincibleToWater ? 1 : 0;
		}
		else
		{
			return GetOriginalRendererDebugOptionValue(optionName);
		}
	}
	return 0;
}

static void SetDebugOptionValue(char* optionName, int value, bool canRoll = true)
{
	int limitedValue = value;
	//if (eType == eDebugOptions_Game)
	{
		if (_stricmp(optionName, g_ProjectedHeadLightFOV) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 360)
					limitedValue = 360;
				if (limitedValue < 1)
					limitedValue = 1;
			}
			else
			{
				if (limitedValue > 360)
					limitedValue = 1;
				if (limitedValue < 1)
					limitedValue = 360;
			}

			*(float*)(0x6dd660) = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_CopCarAsset) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 255)
					limitedValue = 255;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 255)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 255;
			}
			*(int*)(0x6e7464) = limitedValue;
		}
		else if (_stricmp(optionName, g_CopSkinAsset) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 255)
					limitedValue = 255;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 255)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 255;
			}
			*(int*)(0x6e7468) = limitedValue;
		}
		else if (_stricmp(optionName, g_Cop2006InitWep) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 0x11)
					limitedValue = 0x11;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 0x11)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 0x11;
			}
			Set_Debug_Cop2006InitWep((char)limitedValue);
		}
		else if (_stricmp(optionName, g_Cop1978InitWep) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 0x11)
					limitedValue = 0x11;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 0x11)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 0x11;
			}
			Set_Debug_Cop1978InitWep((char)limitedValue);
		}
		else if (_stricmp(optionName, g_LFSPingOut) == 0)
		{
			CLifeSystem* lifeSys = GetLifeSystem();
			if (!canRoll)
			{
				if (limitedValue > 410)
					limitedValue = 410;
				if (limitedValue < 15)
					limitedValue = 15;
			}
			else
			{
				if (limitedValue > 410)
					limitedValue = 15;
				if (limitedValue < 15)
					limitedValue = 410;
			}

			*(float*)(0x641420) = (float)limitedValue;
			lifeSys->m_fPingOutRadius = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_LFSPingIn) == 0)
		{
			CLifeSystem* lifeSys = GetLifeSystem();
			if (!canRoll)
			{
				if (limitedValue > 400)
					limitedValue = 400;
				if (limitedValue < 10)
					limitedValue = 10;
			}
			else
			{
				if (limitedValue > 400)
					limitedValue = 10;
				if (limitedValue < 10)
					limitedValue = 400;
			}
			*(float*)(0x6414f8) = (float)limitedValue;
			lifeSys->m_fPingInRadius = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_DrawDistance1) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 20000)
					limitedValue = 20000;
				if (limitedValue < 1)
					limitedValue = 1;
			}
			else
			{
				if (limitedValue > 20000)
					limitedValue = 1;
				if (limitedValue < 1)
					limitedValue = 20000;
			}
			*(float*)(0x6cfcb4) = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_DrawDistance2) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 20000)
					limitedValue = 20000;
				if (limitedValue < 1)
					limitedValue = 1;
			}
			else
			{
				if (limitedValue > 20000)
					limitedValue = 1;
				if (limitedValue < 1)
					limitedValue = 20000;
			}
			*(float*)(0x6cfcb8) = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_DrawDistance3) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 20000)
					limitedValue = 20000;
				if (limitedValue < 1)
					limitedValue = 1;
			}
			else
			{
				if (limitedValue > 20000)
					limitedValue = 1;
				if (limitedValue < 1)
					limitedValue = 20000;
			}
			*(float*)(0x6cfcbc) = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_WireFrameMode) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		D3DDevice_WireFrame_On = (bool)limitedValue;
		}
		else if (_stricmp(optionName, g_AICivilianCarTopSpeedForward) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 99999)
					limitedValue = 99999;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 99999)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 99999;
			}
			GameChangableSettings::g_fAICivilianCarTopSpeedForward = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_AICivilianCarTopSpeedReverse) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 99999)
					limitedValue = 99999;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 99999)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 99999;
			}
			GameChangableSettings::g_fAICivilianCarTopSpeedReverse = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_AICivilianCarGainGrad) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 99999)
					limitedValue = 99999;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 99999)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 99999;
			}
			GameChangableSettings::g_fAICivilianCarGainGrad = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_AICivilianCarGiveUpJourneyDist) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 99999)
					limitedValue = 99999;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 99999)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 99999;
			}
			GameChangableSettings::g_fAICivilianCarGiveUpJourneySquareDistance = (float)limitedValue;
		}
		else if (_stricmp(optionName, g_CompleteMission) == 0)
		{
			if (!canRoll)
			{
				if (limitedValue > 1)
					limitedValue = 1;
				if (limitedValue < 0)
					limitedValue = 0;
			}
			else
			{
				if (limitedValue > 1)
					limitedValue = 0;
				if (limitedValue < 0)
					limitedValue = 1;
			}
			bDebug_CompleteMission = (bool)limitedValue;
		}
		else if (_stricmp(optionName, g_Display_HUD_and_Map) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		bDebug_Display_HUD_and_Map = (bool)limitedValue;
		}
		else if (_stricmp(optionName, g_SetTime) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 23)
				limitedValue = 23;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 23)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 23;
		}
		bDebug_SetTimeHours = limitedValue;
		}
		else if (_stricmp(optionName, g_OverrideTime) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		bDebug_OverrideTime = (bool)limitedValue;
		}
		else if (_stricmp(optionName, g_PlayerAlwaysEnabled) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		bDebug_PlayerAlwaysEnabled = (bool)limitedValue;
		}
		else if (_stricmp(optionName, g_OverrideGameDifficulty) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		bDebug_OverrideGameDiff = (bool)limitedValue;
		}
		else if (_stricmp(optionName, g_SetGameDifficulty) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > bDebug_Max_SetGameDiff)
				limitedValue = bDebug_Max_SetGameDiff;
			if (limitedValue < bDebug_Min_SetGameDiff)
				limitedValue = bDebug_Min_SetGameDiff;
		}
		else
		{
			if (limitedValue > bDebug_Max_SetGameDiff)
				limitedValue = bDebug_Min_SetGameDiff;
			if (limitedValue < bDebug_Min_SetGameDiff)
				limitedValue = bDebug_Max_SetGameDiff;
		}
		bDebug_SetGameDiff = (bool)limitedValue;
		}
		else if (_stricmp(optionName, g_SetOdometerDist) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 99999)
				limitedValue = 99999;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 99999)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 99999;
		}
		CProfileSettings* profSet = GetProfileSettings();
		if (profSet != NULL)
		{
			profSet->SetOdometer(((float)limitedValue) / 0.000621f);
		}
		}
		else if (_stricmp(optionName, g_DisableLoadingScreens) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		bDebug_DisableLoadingScreen = (bool)limitedValue;
		Update_Debug_DisableLoadingScreen();
		}
		else if (_stricmp(optionName, g_NoCollisions) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		bDebug_NoCollisions = (bool)limitedValue;
		Update_Debug_NoCollisions();
		}
		else if (_stricmp(optionName, g_InvincibleToWater) == 0)
		{
		if (!canRoll)
		{
			if (limitedValue > 1)
				limitedValue = 1;
			if (limitedValue < 0)
				limitedValue = 0;
		}
		else
		{
			if (limitedValue > 1)
				limitedValue = 0;
			if (limitedValue < 0)
				limitedValue = 1;
		}
		bDebug_InvincibleToWater = (bool)limitedValue;
		Update_Debug_InvincibleToWater();
		}
		else
		{
			SetOriginalRendererDebugOptionValue(optionName, value);
		}
	}
}

void CState_Frontend::UpdatePreviewFMVName()
{
	switch (m_iPreviewFMVId)
	{
	case 0:
		m_pszFMVName = FMVName1;
		break;
	case 1:
		m_pszFMVName = FMVName2;
		break;
	case 2:
		m_pszFMVName = FMVName3;
		break;
	case 3:
		m_pszFMVName = FMVName4;
		break;
	case 4:
		m_pszFMVName = FMVName5;
		break;
	}
}

void CState_Frontend::NextFMV()
{
	m_iPreviewFMVId++;
	if (m_iPreviewFMVId >= m_iPreviewFMVCount)
	{
		m_iPreviewFMVId = m_iPreviewFMVCount - 1;
	}
	UpdatePreviewFMVName();
}

void CState_Frontend::PreviousFMV()
{
	m_iPreviewFMVId--;
	if (m_iPreviewFMVId < 0)
	{
		m_iPreviewFMVId = 0;
	}
	UpdatePreviewFMVName();
}

void CState_Frontend::ProcessCommand_Development(char *szCommand, char *szParameters)
{
	if (_stricmp(szCommand, "dev_enter_game") == 0)
	{
		printf("[DEV] Entering game ...\n");
		this->EnterGame(GetLevelList()->GetLevelIndex());

		CMenuManager* menuManager = GetMenuManager();
		if (menuManager != NULL)
		{
			menuManager->DeActivateMenu(EMenu_Frontend);
			menuManager->DeActivateMenu(EMenu_Dev);
		}
	}
	if (_stricmp(szCommand, "launch_dev_menu") == 0)
	{
		CMenuManager* menuManager = GetMenuManager();
		if (menuManager != NULL)
		{
			printf("[DEV] Launching development menu ...\n");
			menuManager->DeActivateMenu(EMenu_Frontend);
			menuManager->ActivateMenu(EMenu_Dev);
		}
	}

	else if (_stricmp(szCommand, "DebugOption_Renderer") == 0)
	{
		m_debugOffset = 0;
		m_debugOption = 0;

		m_eDebugOptionsType = eDebugOptions_Renderer;
	}
	else if (_stricmp(szCommand, "DebugOptions_Game") == 0)
	{
		m_debugOffset = 0;
		m_debugOption = 0;

		m_eDebugOptionsType = eDebugOptions_Game;
	}
	
	if (_stricmp(szCommand, "stat_dev") == 0)
	{
		EMenuState state = eMenuState_Off;
		if (SettingsMgr->bDev_Menu_On)
		{
			state = eMenuState_On;
		}
		GetGameMenuLink()->SetState(state);
	}
	
	if (_stricmp(szCommand, "dev_txt_fmv") == 0)
	{
		GetGameMenuLink()->SetDebugText(m_pszFMVName);
	}
	else if (_stricmp(szCommand, "dev_next_fmv") == 0)
	{
		NextFMV();
	}
	else if (_stricmp(szCommand, "dev_prev_fmv") == 0)
	{
		PreviousFMV();
	}
	else if (_stricmp(szCommand, "dev_play_fmv") == 0)
	{
		GetInGameMovie()->PlayMovie(m_pszFMVName);
	}

	if (_stricmp(szCommand, "dev_val_total_level") == 0)
	{
		GetGameMenuLink()->SetValue(GetLevelList()->GetNumLevels());
	}
	else if (_stricmp(szCommand, "dev_val_level_number") == 0)
	{
		GetGameMenuLink()->SetValue(GetLevelList()->GetLevelIndex());
	}
	else if (_stricmp(szCommand, "dev_txt_level_name") == 0)
	{
		int levelId = GetLevelList()->GetLevelIndex();
		char* levelName = GetLevelList()->GetLevelName(levelId);
		if (levelName != NULL)
		{
			GetGameMenuLink()->SetDebugText(levelName);
		}
	}
	else if (_stricmp(szCommand, "dev_next_level") == 0)
	{
		GetLevelList()->NextLevel();
	}
	else if (_stricmp(szCommand, "dev_prev_level") == 0)
	{
		GetLevelList()->PreviousLevel();
	}

	if (_stricmp(szCommand, "dev_txt_startpoint") == 0)
	{
		char* startpointName = GetLevelList()->GetCurrentStartPointName();
		if (startpointName != NULL)
		{
			GetGameMenuLink()->SetDebugText(startpointName);
		}
	}
	else if (_stricmp(szCommand, "dev_prev_startpoint") == 0)
	{
		GetLevelList()->PreviousStartPoint();
	}
	else if (_stricmp(szCommand, "dev_next_startpoint") == 0)
	{
		GetLevelList()->NextStartPoint();
	}

	if (_stricmp(szCommand, "dev_txt_vehicle") == 0)
	{
		char* vehicleName = VEHICLE_SELECTION_HACK::GetCurrentVehicleName();
		if (vehicleName != NULL)
		{
			GetGameMenuLink()->SetDebugText(vehicleName);
		}
	}
	else if (_stricmp(szCommand, "dev_prev_vehicle") == 0)
	{
		VEHICLE_SELECTION_HACK::PrevVehicle();
	}
	else if (_stricmp(szCommand, "dev_next_vehicle") == 0)
	{
		VEHICLE_SELECTION_HACK::NextVehicle();
	}

	if (_stricmp(szCommand, "dev_val_char") == 0)
	{
		GetGameMenuLink()->SetValue(GetLevelList()->GetCurrentCharacter());
	}
	else if (_stricmp(szCommand, "dev_next_char") == 0)
	{
		int currentChar = GetLevelList()->GetCurrentCharacter() + 1;
		if (currentChar > 0xCC) {
			currentChar = 0xCC;
		}
		GetLevelList()->SetCurrentCharacter(currentChar);
		GetGameMenuLink()->SetValue(currentChar);
	}
	else if (_stricmp(szCommand, "dev_prev_char") == 0)
	{
		int currentChar = GetLevelList()->GetCurrentCharacter() - 1;
		if (currentChar < 0) {
			currentChar = 0;
		}
		GetLevelList()->SetCurrentCharacter(currentChar);
		GetGameMenuLink()->SetValue(currentChar);
	}

	uint32_t num_options = 0;
	if (m_eDebugOptionsType == eDebugOptions_Game)
	{
		num_options = sizeof(m_pszGameDebugOptions) / 4;
	}
	else if (m_eDebugOptionsType == eDebugOptions_Renderer)
	{
		num_options = (sizeof(m_pszCustomRendererDebugOptions) / 4);
	}
	int total_num_options = (num_options + (m_eDebugOptionsType == eDebugOptions_Renderer ? NUMBER_OF_ORIGINAL_DBG_RENDERER_OPTIONS : 0));

	if (!_stricmp(szCommand, "DebugOption_Next"))
	{
		if (m_debugOption < 9)
			++m_debugOption;
		else
		{
			m_debugOffset += 10;
			m_debugOption = 0;
			if (m_debugOffset > (total_num_options - 1))
				m_debugOffset = 0;
		}
	}
	else if (!_stricmp(szCommand, "DebugOption_Prev"))
	{
		if (m_debugOption > 0)
			--m_debugOption;
		else
		{
			m_debugOffset -= 10;
			m_debugOption = 9;
			if (m_debugOffset < 0)
				m_debugOffset = 10 * ((total_num_options - 1) / 10);
		}
	}

	SDebugOption* ogopt_base = (SDebugOption*)PTR_ORIGINAL_DBG_RENDERER_OPTIONS;

	// Update debug option text
	int option_idx = GetDebugOptionIndex(szCommand);
	if (option_idx != -1)
	{
		uint32_t option_num = (m_debugOffset + option_idx);
		char* optName = NULL;
		SDebugOption* ogopt = NULL;

		// default state
		GetGameMenuLink()->SetValue(0);
		GetGameMenuLink()->SetDebugText("");

		if (option_num < total_num_options && option_num >= 0)
		{
			if (m_eDebugOptionsType == eDebugOptions_Game)
			{
				optName = (char*)m_pszGameDebugOptions[option_num];
			}
			else if (m_eDebugOptionsType == eDebugOptions_Renderer)
			{
				if (option_num < num_options)
				{
					optName = (char*)m_pszCustomRendererDebugOptions[option_num];
				}
				else
				{
					ogopt = &ogopt_base[option_num - num_options];
					optName = ogopt->szName;
				}
			}
		}

		int option_val = 0;

		if (optName != NULL /*&& ogopt == NULL*/)
		{
			option_val = GetDebugOptionValue(optName);
		}
		//else if (ogopt != NULL)
		//{
		//	option_val = ogopt->iValue;
		//}

		if (optName != NULL || ogopt != NULL)
		{
			GetGameMenuLink()->SetValue(option_val);
			GetGameMenuLink()->SetDebugText(optName);
		}
	}

	// Make the debug options be changed
	if (m_debugOption >= 0 && m_debugOption < total_num_options)
	{
		uint32_t option_num = (m_debugOption + m_debugOffset);
		char* optName = NULL;
		SDebugOption* ogopt = NULL;

		if (m_eDebugOptionsType == eDebugOptions_Game)
		{
			optName = (char*)m_pszGameDebugOptions[option_num];
		}
		else if (m_eDebugOptionsType == eDebugOptions_Renderer)
		{
			if (option_num < num_options)
			{
				optName = (char*)m_pszCustomRendererDebugOptions[option_num];
			}
			else
			{
				ogopt = &ogopt_base[option_num - num_options];
				optName = ogopt->szName;
			}
		}

		{
			int option_val = 0;

			if (optName != NULL /*&& ogopt == NULL*/)
			{
				option_val = GetDebugOptionValue(optName);
			}
			//else if (ogopt != NULL)
			//{
			//	option_val = ogopt->iValue;
			//}

			bool option_changed = false;
			if (_stricmp(szCommand, "DO0Up") == 0)
			{
				option_val++;
				option_changed = true;
			}
			else if (_stricmp(szCommand, "DO0Down") == 0)
			{
				option_val--;
				option_changed = true;
			}

			if (option_changed)
			{
				SetDebugOptionValue(optName, option_val);
			}
		}
	}
}

void CState_Frontend::EnterGame(unsigned int nLevel)
{
	// NOTE: Called with the REAL frontend state identity, because calling with 'this' will crash the game.
	((void(__thiscall*)(CState_Frontend*, unsigned int))0x4A82CB)(*(CState_Frontend**)0x70C740, nLevel);
}

void CState_Frontend::OnEnterState()
{
	// AllocateVehicleSelectionHackTable__22VEHICLE_SELECTION_HACKv(void)
	((void(__cdecl*)())0x4a4319)();

	printf("FRONTEND - ENTER\n");
}