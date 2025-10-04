#include "AmbientSoundManager.h"

CAmbientSoundManager* GetAmbientSoundManager()
{
	return *(CAmbientSoundManager**)0x70C6B0;
}

void CAmbientSoundManager::SetMusicTrack(int track)
{
	((void(__thiscall*)(CAmbientSoundManager*, int))0x4E0420)(this, track);
}