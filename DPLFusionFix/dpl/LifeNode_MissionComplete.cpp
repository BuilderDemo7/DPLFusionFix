#include "LifeNode_MissionComplete.h"

void CLifeNode_MissionComplete::OnUpdate()
{
	if (bDebug_CompleteMission)
	{
		bDebug_CompleteMission = false;
		this->OnEnable();
	}
}

void CLifeNode_MissionComplete::OnEnable()
{
	((void(__thiscall*)(CLifeNode_MissionComplete*))0x48F295)(this);
}