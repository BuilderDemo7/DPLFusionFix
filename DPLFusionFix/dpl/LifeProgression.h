#pragma once
#include <iostream>

#include "Vector4.h"
#include "..\core\Matrix.h"

struct CLifeEventList {
	int m_childPtr;   //TLifeEventPointer m_childPtr;
	int m_siblingPtr; //TLifeEventPointer m_siblingPtr;
	bool m_bRequestedSpooling;
	uint8_t field3_0x9;
	uint8_t field4_0xa;
	uint8_t field5_0xb;
	uint8_t field6_0xc;
	uint8_t field7_0xd;
	uint8_t field8_0xe;
	uint8_t field9_0xf;
	struct Matrix m_restartPosition;
	struct Vector4 v4Position;
	unsigned int eventType;
	char *filename;
	struct LocalisedString *m_eventName;
	char *m_fmvName;
	int display;
	int m_iconType;
	//struct SLifeEventData__129_10098 *m_data;
	//bool m_bPreviewViewed;
	//bool m_bRestartPositionSet;
	//uint8_t field21_0x7e;
	//uint8_t field22_0x7f;
};

struct a4 {
	uint8_t field0_0x0;
	uint8_t field1_0x1;
	uint8_t field2_0x2;
	uint8_t field3_0x3;
};

struct EventList_4
{
	struct a4 m_array[4];
	size_t m_size;
};

struct EventList_40
{
	struct a4 m_array[40];
	size_t m_size;
};

enum EMS_MissionID {
	EMS_MID_NotAGameMission = -2,
	EMS_MID_None = -1,
	EMS_MID_Mission00 = 0,
	EMS_MID_Mission01 = 1,
	EMS_MID_Mission02 = 2,
	EMS_MID_Mission03 = 3,
	EMS_MID_Mission04 = 4,
	EMS_MID_Mission05 = 5,
	EMS_MID_Mission06 = 6,
	EMS_MID_Mission07 = 7,
	EMS_MID_Mission08 = 8,
	EMS_MID_Mission09 = 9,
	EMS_MID_Mission10 = 10,
	EMS_MID_Mission11 = 11,
	EMS_MID_Mission12 = 12,
	EMS_MID_Mission13 = 13,
	EMS_MID_Mission14 = 14,
	EMS_MID_Mission15 = 15,
	EMS_MID_Mission16 = 16,
	EMS_MID_Mission17 = 17,
	EMS_MID_Mission18 = 18,
	EMS_MID_Mission19 = 19,
	EMS_MID_Mission20 = 20,
	EMS_MID_Mission21 = 21,
	EMS_MID_Mission22 = 22,
	EMS_MID_Mission23 = 23,
	EMS_MID_Mission24 = 24,
	EMS_MID_Mission25 = 25,
	EMS_MID_Mission26 = 26,
	EMS_MID_Mission27 = 27,
	EMS_MID_Mission28 = 28,
	EMS_MID_Mission29 = 29,
	EMS_MID_Mission30 = 30,
	EMS_MID_Mission31 = 31,
	EMS_MID_Mission32 = 32,
	EMS_MID_Mission33 = 33,
	EMS_MID_Mission34 = 34,
	EMS_MID_Mission35 = 35,
	EMS_MID_Mission36 = 36,
	EMS_MID_Mission37 = 37,
	EMS_MID_Mission38 = 38,
	EMS_MID_Mission39 = 39,
	EMS_MID_Mission40 = 40,
	EMS_MID_Mission41 = 41,
	EMS_MID_Mission42 = 42,
	EMS_MID_Mission43 = 43,
	EMS_MID_Mission44 = 44,
	EMS_MID_Mission45 = 45,
	EMS_MID_Mission46 = 46,
	EMS_MID_Mission47 = 47,
	EMS_MID_Mission48 = 48,
	EMS_MID_Mission49 = 49,
	EMS_MID_Mission50 = 50,
	EMS_MID_Mission51 = 51,
	EMS_MID_Mission52 = 52,
	EMS_MID_Mission53 = 53,
	EMS_MID_Mission54 = 54,
	EMS_MID_Mission55 = 55,
	EMS_MID_Mission56 = 56,
	EMS_MID_Mission57 = 57,
	EMS_MID_Mission58 = 58,
	EMS_MID_Mission59 = 59,
	EMS_MID_Mission60 = 60,
	EMS_MID_Mission61 = 61,
	EMS_MID_Mission62 = 62,
	EMS_MID_Mission63 = 63,
	EMS_MID_Mission64 = 64,
	EMS_MID_Mission65 = 65,
	EMS_MID_Mission66 = 66,
	EMS_MID_Mission67 = 67,
	EMS_MID_Mission68 = 68,
	EMS_MID_Mission69 = 69,
	EMS_MID_Mission70 = 70,
	EMS_MID_Mission71 = 71,
	EMS_MID_Mission72 = 72,
	EMS_MID_Mission73 = 73,
	EMS_MID_Mission74 = 74,
	EMS_MID_Mission75 = 75,
	EMS_MID_Mission76 = 76,
	EMS_MID_Mission77 = 77,
	EMS_MID_Mission78 = 78,
	EMS_MID_Mission79 = 79,
	EMS_MID_Mission80 = 80,
	EMS_MID_Mission81 = 81,
	EMS_MID_Mission82 = 82,
	EMS_MID_Mission83 = 83,
	EMS_MID_Mission84 = 84,
	EMS_MID_Mission85 = 85,
	EMS_MID_Mission86 = 86,
	EMS_MID_Mission87 = 87,
	EMS_MID_Mission88 = 88,
	EMS_MID_Proto_Base_89 = 89,
	EMS_MID_Proto_ChaseMe_90 = 90,
	EMS_MID_Proto_ChaseThem_91 = 91,
	EMS_MID_Proto_KillGoons_92 = 92,
	EMS_MID_Proto_Online_93 = 93
};

struct SLifeEventData__129_10098 {
	enum EMS_MissionID eLifeEvent;
	int eStatus;
};

struct SProgressionData {
	unsigned int numEvents;
	struct SLifeEventData__129_10098 missions[256];
};

class CLifeProgression {
public:

	CLifeEventList* m_baseLifeEvent;
	struct EventList_4 m_activeLifeEvents;
	struct EventList_4 m_waitingToLogicStop;
	struct EventList_40 m_incidentalEvents;
	CLifeEventList* m_activeIncidentalLifeEvent;
	SProgressionData* m_lifeEvents;
	SProgressionData* m_internalLifeEventsStore;
	//struct SLifeEventData__129_10098 m_lifeEvents_SoftSave[256];

	bool IsShowingIcons();
	void RunEvent(int EventID);
};

CLifeProgression* GetLifeProgression();