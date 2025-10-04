#pragma once
#include "stdint.h"
#include "Viewport.h"

#include "..\core\Vector.h"
#include "Vector4.h"

#include "Sprite.h"
#include "Model.h"

static bool m_bDisableHUD;

enum EMapItem {
	EMapItem_Uninitialised = 0,
	EMapItem_Camera = 1,
	EMapItem_Player = 2,
	EMapItem_Vehicle = 3,
	EMapItem_Character = 4,
	EMapItem_CopCar = 5,
	EMapItem_GoonCar = 6,
	EMapItem_Target = 7,
	EMapItem_PlotMission = 8,
	EMapItem_MiniMission = 9,
	EMapItem_SafeHouse = 10,
	EMapItem_VEditGarage = 11,
	EMapItem_Network_Portal = 12,
	EMapItem_Network_Player = 13,
	EMapItem_Positional_Marker = 14,
	EMapItem_COUNT = 15
};

enum EMapIcon {
	EMapIcon_Default = 0,
	EMapIcon_CircuitRace = 1,
	EMapIcon_Repoman = 2,
	EMapIcon_SafeHouse = 3,
	EMapIcon_StreetRace = 4,
	EMapIcon_TimeTravel = 5,
	EMapIcon_Vedit = 6,
	EMapIcon_78_LoanShark = 7,
	EMapIcon_06_Hitman = 8
};

struct STargetArrow {
	float fDistance;
	float fAngle;
};

struct SMapPosMarker {
	enum EMapIcon eMapIcon;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct SMapCopOrGoon {
	int status;
};

struct SMapTarget {
	enum EMapIcon eMapIcon;
	bool bShowArrow;
	uint8_t field2_0x5;
	uint8_t field3_0x6;
	uint8_t field4_0x7;
};

struct SMapNetPlayer {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
	bool bShowArrow;
};

struct SMapMission {
	enum EMapIcon eMapIcon;
	int missionID;
};

struct SMapVehicle {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
	bool bUseColour;
	bool bShowArrow;
};

struct SMapCharacter {
	bool bShowArrow;
};

union UMapSubItem {
	struct SMapCopOrGoon cop_goon;
	struct SMapTarget target;
	struct SMapMission mission;
	struct SMapVehicle vehicle;
	struct SMapCharacter character;
	struct SMapNetPlayer network;
	struct SMapPosMarker posmarker;
};

struct SMapItem {
	Vector4 position;
	float orientation;
	enum EMapItem type;
	const wchar_t *utfDescription;
	union UMapSubItem subItem;
	uint8_t field5_0x24;
	uint8_t field6_0x25;
	uint8_t field7_0x26;
	uint8_t field8_0x27;
	uint8_t field9_0x28;
	uint8_t field10_0x29;
	uint8_t field11_0x2a;
	uint8_t field12_0x2b;
};

struct CMapMarkers {
	bool m_MapMarkerActive;
	
	struct SMapItem m_MapMarker;
	struct SMapItem m_sItems[32];
	struct SMapItem m_camera;
	struct SMapItem m_player;
	struct SGameOverlayGraphic *m_pNorth;
	float m_width;
	float m_height;
	float m_zoom;
	float m_northDir;
	float m_minDistance;
	float m_highlight;
	int m_nItems;
	int m_selectedItem;
	int m_iCounter;
	uint8_t field30_0x6c8;
	uint8_t field31_0x6c9;
	uint8_t field32_0x6ca;
	uint8_t field33_0x6cb;
	uint8_t field34_0x6cc;
	uint8_t field35_0x6cd;
	uint8_t field36_0x6ce;
	uint8_t field37_0x6cf;
};

struct SGameOverlayGraphic {
	struct Vector4 vColour;
	float fX;
	float fY;
	float fW;
	float fH;
	float fU0;
	float fV0;
	float fU1;
	float fV1;
	float texW;
	float texH;
	unsigned short texID;
	uint8_t centreX;
	uint8_t centreY;
	float rotation;
};

struct COverheadMap {
	struct COverheadMap__vtable *__vtable; // Inherited from IInterface

	Vector4 m_cameraMinPos;
	Vector4 m_cameraMaxPos;

	int field13_0x24;
	int field14_0x28;
	int field15_0x2C;

	CPCViewport* m_piViewport;

	uint8_t field16_0x34;
	uint8_t field17_0x35;
	uint8_t field18_0x36;
	uint8_t field19_0x37;
	uint8_t field20_0x38;
	uint8_t field21_0x39;
	uint8_t field22_0x3a;
	uint8_t field23_0x3b;
	uint8_t field24_0x3c;
	uint8_t field25_0x3d;
	uint8_t field26_0x3e;
	uint8_t field27_0x3f;
	struct CMapMarkers m_cMapMarkers;
	struct SMapItem m_camera;
	struct SMapItem m_player;
	struct STargetArrow m_targetArrows[6];
	struct SGameOverlayGraphic *m_pMapGraphic;
	struct int8_t *m_pMapLookup;
	struct SSpriteInstance m_copSpriteInstance;
	uint8_t field35_0x7b8;
	uint8_t field36_0x7b9;
	uint8_t field37_0x7ba;
	uint8_t field38_0x7bb;
	uint8_t field39_0x7bc;
	uint8_t field40_0x7bd;
	uint8_t field41_0x7be;
	uint8_t field42_0x7bf;
	struct Sprite m_copSprite;
	struct IRuntimeModelModule m_piRTMM;
	float m_xPos;
	float m_yPos;
	float m_width;
	float m_height;
	float m_aspect;
	float m_zoom;
	float m_lastOrientation;
	int m_nTargetArrows;
	int m_counter;
	int m_flashtimer;
	int m_iEnableCount;
	bool m_bDrawMap;
	bool m_bZoomed;
	bool m_bCopsAware;
	bool m_bCopsWereAware;
	bool m_bCMDRegistered;
	uint8_t field61_0x825;
	uint8_t field62_0x826;
	uint8_t field63_0x827;
	uint8_t field64_0x828;
	uint8_t field65_0x829;
	uint8_t field66_0x82a;
	uint8_t field67_0x82b;
	uint8_t field68_0x82c;
	uint8_t field69_0x82d;
	uint8_t field70_0x82e;
	uint8_t field71_0x82f;
};

class CGameOverlayManager {
public:
	void Draw(int Viewport);
	
	void Toggle(bool toggled);

	void DrawHooked(int Viewport);
};


class COverheadMap_Hook {
public:
	void Draw(int Viewport);

	void DrawHooked(int Viewport);
};

COverheadMap* GetOverheadMap();
CGameOverlayManager* GetGameOverlayManager();