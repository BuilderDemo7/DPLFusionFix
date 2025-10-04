#include "pch.h"
#include "Settings.h"
#include "IniReader.h"

eSettingsManager* SettingsMgr = new eSettingsManager();

eSettingsManager::eSettingsManager()
{
	CIniReader ini(const_cast<char*>(""));
	CIniReader user(const_cast<char*>("dplfusionfix_userconfig.ini"));

	fDraw_Distance1 = user.ReadFloat(const_cast<char*>(pszRendererSectionName), "Draw_Distance1", DEFAULT_DRAW_DISTANCE1);
	fDraw_Distance2 = user.ReadFloat(const_cast<char*>(pszRendererSectionName), "Draw_Distance2", DEFAULT_DRAW_DISTANCE2);
	fDraw_Distance3 = user.ReadFloat(const_cast<char*>(pszRendererSectionName), "Draw_Distance3", DEFAULT_DRAW_DISTANCE3);
	fVehicles_HeadLight_DegreesAngle = user.ReadFloat(const_cast<char*>(pszRendererSectionName), "Vehicles_HeadLight_DegreesAngle", DEFAULT_VEHICLES_HEADLIGHT_ANGLE);
	
	if (fVehicles_HeadLight_DegreesAngle > 360.0f)
	{
		fVehicles_HeadLight_DegreesAngle = 360.0f;
	}
	if (fVehicles_HeadLight_DegreesAngle < 0.1f)
	{
		fVehicles_HeadLight_DegreesAngle = 0.1f;
	}

	fInstances_Spawn_Radius = user.ReadFloat(const_cast<char*>(pszGameSectionName), "Instances_Spawn_Radius", DEFAULT_INSTANCES_SPAWN_RADIUS);
	if (fInstances_Spawn_Radius < MINIMUM_INSTANCES_SPAWN_RADIUS)
	{
		fInstances_Spawn_Radius = MINIMUM_INSTANCES_SPAWN_RADIUS;
	}
	if (fInstances_Spawn_Radius > MAXIMUM_INSTANCES_SPAWN_RADIUS)
	{
		fInstances_Spawn_Radius = MAXIMUM_INSTANCES_SPAWN_RADIUS;
	}

	bShow_Console_Output = user.ReadBoolean(const_cast<char*>(pszMiscSectionName), "Show_Console_Output", DEFAULT_CONSOLE_OUTPUT_COND);
	bWindowed_Mode = user.ReadBoolean(const_cast<char*>(pszMiscSectionName), "Windowed_Mode", DEFAULT_WINDOWED_MODE);
	bPause_Game_In_Windowed_Mode = user.ReadBoolean(const_cast<char*>(pszMiscSectionName), "Pause_Game_In_Windowed_Mode", DEFAULT_PAUSE_GAME_IN_WINDOW_MODE);
	bInvert_Garage_Camera = user.ReadBoolean(const_cast<char*>(pszMiscSectionName), "Invert_Garage_Camera", DEFAULT_INVERT_GARAGE_CAMERA);
	bClassic_BurnOut = user.ReadBoolean(const_cast<char*>(pszMiscSectionName), "Classic_BurnOut", DEFAULT_CLASSIC_BURNOUT);

	bPlayer_Can_Use_Turn_Signal = user.ReadBoolean(const_cast<char*>(pszNew_FeatureSectionName), "Player_Can_Use_Turn_Signal", DEFAULT_PLAYER_CAN_USE_TURN_SIGNAL);

	bMinimap_Driver3_Goons = user.ReadBoolean(const_cast<char*>(pszNew_VisualSectionName), "Minimap_Driver3_Goons", DEFAULT_MINIMAP_DRIVER3_GOONS);
	bAllow_Missions_Debug_Text = user.ReadBoolean(const_cast<char*>(pszGameSectionName), "Allow_Missions_Debug_Text", DEFAULT_ALLOW_MISSION_DEBUGTEXT);
	bDev_Menu_On = user.ReadBoolean(const_cast<char*>(pszGameSectionName), "Dev_Menu_On", DEFAULT_DEV_MENU_ON);
	bPS2_Glow_Effects_Settings = user.ReadBoolean(const_cast<char*>(pszRendererSectionName), "PS2_Glow_Effects_Settings", DEFAULT_PS2_GLOW_SFX_SET);
	bBackground_Glow_In_ShaderVer_1 = user.ReadBoolean(const_cast<char*>(pszRendererSectionName), "Background_Glow_In_ShaderVer_1", DEFAULT_BACKGROUND_GLOW_IN_SHADER1);
}