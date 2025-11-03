#include "DebugOptions.h"

bool bDebug_ShowVersion = false;
bool bDebug_ShowFPS = false;
bool bDebug_CompleteMission = false;
bool bDebug_Display_HUD_and_Map = true;
bool bDebug_OverrideTime = false;
bool bDebug_OverrideRateOfTime = false;
bool bDebug_PlayerAlwaysEnabled = false;
bool bDebug_DisableLoadingScreen = false;
bool bDebug_InvincibleToWater = false;
bool bDebug_NoCollisions = false;

int bDebug_SetTimeHours = 13;

bool bDebug_OverrideGameDiff = false;
int bDebug_SetGameDiff = 0;
int bDebug_Max_SetGameDiff = 1000;
int bDebug_Min_SetGameDiff = 0;

void Update_Debug_DisableLoadingScreen()
{
	if (bDebug_DisableLoadingScreen)
	{
		WriteAt(0x4a76ef, "\xC2\x04\x00", 3);
	}
	else
	{
		WriteAt(0x4a76ef, "\x56\x8B\xF1", 3);
	}
}

void Update_Debug_InvincibleToWater()
{
	if (bDebug_InvincibleToWater)
	{
		Nop(0x4A268D, 6);
		InjectHook(0x4A268D, 0x4A27A5, PATCH_JUMP);
	}
	else
	{
		WriteAt(0x4A268D, "\x0F\x84\x12\x01\x00\x00", 6);
	}
}

void Set_Debug_Cop2006InitWep(char newOne)
{
	WriteAt(0x430046 + 0x1, &newOne, 1);
}

void Set_Debug_Cop1978InitWep(char newOne)
{
	WriteAt(0x43004a + 0x1, &newOne, 1);
}

void Update_Debug_NoCollisions()
{
	if (bDebug_NoCollisions)
	{
		WriteAt(0x5ccd9d, "\xc3", 1);
	}
	else
	{
		WriteAt(0x5ccd9d, "\x55", 1);
	}
}