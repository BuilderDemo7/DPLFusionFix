#pragma once
#include <Windows.h>

// Renderer
#define DEFAULT_DRAW_DISTANCE1 260.0f
#define DEFAULT_DRAW_DISTANCE2 435.0f
#define DEFAULT_DRAW_DISTANCE3 510.0f
#define DEFAULT_VEHICLES_HEADLIGHT_ANGLE 45.0f
#define DEFAULT_HIGHPOLY_CIVILIAN_CARS true
#define DEFAULT_PS2_GLOW_SFX_SET true
#define DEFAULT_BACKGROUND_GLOW_IN_SHADER1 true

// Game
#define DEFAULT_ALLOW_MISSION_DEBUGTEXT false
#define DEFAULT_DEV_MENU_ON false
#define DEFAULT_LOAD_FRONTEND_DEV_MENU false

#define MINIMUM_INSTANCES_SPAWN_RADIUS 30.0f 
#define MAXIMUM_INSTANCES_SPAWN_RADIUS 400.0f
#define DEFAULT_INSTANCES_SPAWN_RADIUS 210.0f // a.k.a Ping Out radius, Ping In = pingout - 10
#define INSTANCES_SPAWN_RADIUS_PING_IN_OFFSET 10.0f

// Misc
#define DEFAULT_CONSOLE_OUTPUT_COND false
#define DEFAULT_WINDOWED_MODE false
#define DEFAULT_PAUSE_GAME_IN_WINDOW_MODE false
#define DEFAULT_INVERT_GARAGE_CAMERA false
#define DEFAULT_CLASSIC_BURNOUT false
#define DEFAULT_HEAPFREE_VALIDATION_FIX true

// New Visual
#define DEFAULT_MINIMAP_DRIVER3_GOONS true

// New Feature
#define DEFAULT_PLAYER_CAN_USE_TURN_SIGNAL true

class eSettingsManager
{
	const char* pszRendererSectionName = "Renderer";
	const char* pszGameSectionName = "Game";
	const char* pszMiscSectionName = "Misc";
	const char* pszNew_VisualSectionName = "New_Visual";
	const char* pszNew_FeatureSectionName = "New_Feature";
public:
	eSettingsManager();

	// Renderer
	float fDraw_Distance1 = DEFAULT_DRAW_DISTANCE1;
	float fDraw_Distance2 = DEFAULT_DRAW_DISTANCE2;
	float fDraw_Distance3 = DEFAULT_DRAW_DISTANCE3;
	float fVehicles_HeadLight_DegreesAngle = DEFAULT_VEHICLES_HEADLIGHT_ANGLE;
	bool bHighPoly_Civilian_Cars = DEFAULT_HIGHPOLY_CIVILIAN_CARS;
	bool bPS2_Glow_Effects_Settings = DEFAULT_PS2_GLOW_SFX_SET;
	bool bBackground_Glow_In_ShaderVer_1 = DEFAULT_BACKGROUND_GLOW_IN_SHADER1;

	// Game
	bool bAllow_Missions_Debug_Text = DEFAULT_ALLOW_MISSION_DEBUGTEXT;
	bool bDev_Menu_On = DEFAULT_DEV_MENU_ON;
	bool bLoad_Frontend_Dev_Menu = DEFAULT_LOAD_FRONTEND_DEV_MENU;
	float fInstances_Spawn_Radius = DEFAULT_INSTANCES_SPAWN_RADIUS;

	// Misc
	bool bShow_Console_Output = DEFAULT_CONSOLE_OUTPUT_COND;
	bool bWindowed_Mode = DEFAULT_WINDOWED_MODE;
	bool bPause_Game_In_Windowed_Mode = DEFAULT_PAUSE_GAME_IN_WINDOW_MODE;
	bool bInvert_Garage_Camera = DEFAULT_INVERT_GARAGE_CAMERA;
	bool bClassic_BurnOut = DEFAULT_CLASSIC_BURNOUT;
	bool bHeapFree_Validation_Fix = DEFAULT_HEAPFREE_VALIDATION_FIX;

	// New_Visual
	bool bMinimap_Driver3_Goons = DEFAULT_MINIMAP_DRIVER3_GOONS;

	// New_Feature
	bool bPlayer_Can_Use_Turn_Signal = DEFAULT_PLAYER_CAN_USE_TURN_SIGNAL;
};

extern eSettingsManager* SettingsMgr;