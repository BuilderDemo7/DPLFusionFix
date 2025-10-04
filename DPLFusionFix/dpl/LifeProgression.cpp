#include <iostream>
#include "LifeProgression.h"

CLifeProgression* GetLifeProgression()
{
    return ((CLifeProgression* (__cdecl*)())0x4700B3)();
}

// If not in a mission?
bool CLifeProgression::IsShowingIcons()
{
	return *(int*)(this + 0x14) != 0 ? true : false;
}

void CLifeProgression::RunEvent(int EventID)
{
    ((void(__thiscall*)(CLifeProgression*, int))0x47125A)(this, EventID);
}
