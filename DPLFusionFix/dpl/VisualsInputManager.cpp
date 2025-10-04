#include "VisualsInputManager.h"

CVisualsInputManager* GetVisualsInputManager()
{
	return *(CVisualsInputManager**)0x70C6F0;
}

float CVisualsInputManager::Get_Camera_LookLeft_HACK()
{
	return *(float*)((int)this + 0x4C);
}

float CVisualsInputManager::Get_Camera_LookRight_HACK()
{
	return *(float*)((int)this + 0x58);
}

float CVisualsInputManager::Get_Camera_LookBack_HACK()
{
	return *(float*)((int)this + 0x64);
}

float CVisualsInputManager::Get_Camera_LookForward_HACK()
{
	return *(float*)((int)this + 0x70);
}