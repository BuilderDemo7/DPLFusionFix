#include "InGameMovie.h"

CInGameMovie* GetInGameMovie()
{
	return *(CInGameMovie**)(0x70C790);
}

void CInGameMovie::PlayMovie(char* szFileName, bool bLoop, bool pauseAtEnd)
{
	((void* (__thiscall*)(CInGameMovie*, char*, bool, bool))0x45A1AC)(this, szFileName, bLoop, pauseAtEnd);
}