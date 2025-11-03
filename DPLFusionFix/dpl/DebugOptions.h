#pragma once
#include "..\utils.h"

extern bool bDebug_ShowVersion;
extern bool bDebug_ShowFPS;
extern bool bDebug_CompleteMission;
extern bool bDebug_Display_HUD_and_Map;

extern bool bDebug_PlayerAlwaysEnabled;
extern bool bDebug_DisableLoadingScreen;
extern bool bDebug_InvincibleToWater;
extern bool bDebug_NoCollisions;

extern bool bDebug_OverrideTime;
extern int bDebug_SetTimeHours;

extern bool bDebug_OverrideGameDiff;
extern int bDebug_SetGameDiff;
extern int bDebug_Max_SetGameDiff;
extern int bDebug_Min_SetGameDiff;

void Update_Debug_DisableLoadingScreen();
void Update_Debug_InvincibleToWater();
void Update_Debug_NoCollisions();

void Set_Debug_Cop2006InitWep(char newOne);
void Set_Debug_Cop1978InitWep(char newOne);