#pragma once
#include "WireCollection.h"
#include "LifeEventData.h"
#include "LifePropertyStream.h"

class CLifeNode_DebugText
{
public:
	char undefined[0x20];

	WireCollection wireCollection;
	char* szMessage;

	void OnInitialise(CLifePropertyStream* propertiesStream, CLifeEventData* pOwningLifeEvent);
	void OnEnable(bool *enabled, eNodeFireWire *wireToFire);
};