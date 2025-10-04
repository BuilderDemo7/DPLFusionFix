#pragma once
#include <iostream>
#include <stdio.h>

#include "DebugOptions.h"
#include "LevelList.h"
#include "GameMenuLink.h"
#include "InGameMovie.h"
#include "GenericStringManager.h"
#include "LifeSystem.h"
#include "ProfileSettings.h"
#include "MenuManager.h"
#include "HACK_VehicleTypeSelection.h"

#include "..\HooksClass.h"
#include "..\Settings.h"
#include "..\GameChangableSettingsClass.h"

#define NUMBER_OF_ORIGINAL_DBG_RENDERER_OPTIONS 77
#define PTR_ORIGINAL_DBG_RENDERER_OPTIONS 0x974900

struct SDebugOption
{
	char szName[512];
	int iMaxValue;
	int iMinValue;
	int iValue;
};

enum eDebugOptionsType
{
	eDebugOptions_Game,
	eDebugOptions_Renderer,
};

class CState_Frontend
{
public:
	static int m_iPreviewFMVId;
	static int m_iPreviewFMVCount;
	static char* m_pszFMVName;

	static const char* m_pszGameDebugOptions[];
	static const char* m_pszCustomRendererDebugOptions[];
	static eDebugOptionsType m_eDebugOptionsType;
	static int m_debugOffset;
	static int m_debugOption;

	void UpdatePreviewFMVName();
	void NextFMV();
	void PreviousFMV();

	void OnEnterState();

	void ProcessCommand_Development(char *szCommand, char *szParameters);
	void EnterGame(unsigned int nLevel);
};
