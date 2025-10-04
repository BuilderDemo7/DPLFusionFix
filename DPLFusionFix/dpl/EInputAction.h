#pragma once
enum EInputAction
{
	EInputAction_Pause = 0,
	EInputAction_NoController = 1,
	EInputAction_Frontend_Begin = 4,
	EInputAction_Menu_Up = 5,
	EInputAction_Menu_Down = 6,
	EInputAction_Menu_Left = 7,
	EInputAction_Menu_Right = 8,
	EInputAction_Menu_Select = 9,
	EInputAction_Menu_Cancel = 10,
	EInputAction_Menu_Start = 11,

	EInputAction_Pause_Character_Teleport = 28,

	EInputAction_Visuals_Begin = 103,
	EInputAction_Camera_LookLeft = 108,
	EInputAction_Camera_LookRight = 109,
	EInputAction_Camera_LookForward = 110,
	EInputAction_Camera_LookBack = 111,
	EInputAction_Visuals_End = 112
};