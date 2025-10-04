#include "LevelList.h"

int CLevelList::GetLevelIndex()
{
	return this->m_uCurrentLevel;
}

char* CLevelList::GetLevelName(int nLevel)
{
	if (nLevel <= -1 || nLevel > this->m_uLevels)
	{
		return NULL;
	}

	int levelPtr = *(int*)(0x6e7d08 + (nLevel * 4)); // g_Levels[]
	if (levelPtr != NULL)
	{
		return (char*)levelPtr + 0x8;
	}
	else
	{
		return NULL;
	}
}

void CLevelList::NextLevel()
{
	this->m_uCurrentLevel = this->m_uCurrentLevel + 1;

	if (this->m_uCurrentLevel >= this->m_uLevels)
	{
		this->m_uCurrentLevel = 0;
	}

	int levelPtr = *(int*)(0x6e7d08 + (this->m_uCurrentLevel * 4)); // g_Levels[]
	*(int*)(0x6e8860) = levelPtr; // g_selectedLevel
}

void CLevelList::PreviousLevel()
{
	this->m_uCurrentLevel = this->m_uCurrentLevel - 1;

	if (this->m_uCurrentLevel < 0)
	{
		this->m_uCurrentLevel = this->m_uLevels - 1;
	}

	int levelPtr = *(int*)(0x6e7d08 + (this->m_uCurrentLevel * 4)); // g_Levels[]
	*(int*)(0x6e8860) = levelPtr; // g_selectedLevel
}

void CLevelList::SetLevelIndex(int nLevel)
{
	this->m_uCurrentLevel = nLevel;
}

void CLevelList::SetCurrentCharacter(int characterId)
{
	//*(int*)(this + 0xA50) = characterId;

	// Hack: pointer not working? use static addr
	*(int*)(0x6E7E08 + 0xA50) = characterId;
}

int CLevelList::GetCurrentCharacter()
{
	//return *(int*)(this + 0xA50);

	// Hack: pointer not working? use static addr
	return *(int*)(0x6E7E08 + 0xA50);
}

int CLevelList::GetNumLevels()
{
	return this->m_uLevels;
}

int CLevelList::GetNumberOfStartPoints()
{
	return *(int*)0x6E8850;
}

int CLevelList::GetCurrentStartPoint()
{
	return *(int*)0x6E8854;
}

void CLevelList::SetCurrentStartPoint(int uLevel)
{
	*(int*)0x6E8854 = uLevel;
}

void CLevelList::NextStartPoint()
{
	int startPoint = GetCurrentStartPoint();
	startPoint += 1;

	if (startPoint > GetNumberOfStartPoints())
	{
		startPoint = -1; // default start point
	}

	SetCurrentStartPoint(startPoint);
}

void CLevelList::PreviousStartPoint()
{
	int startPoint = GetCurrentStartPoint();
	startPoint -= 1;

	if (startPoint < -1)
	{
		startPoint = GetNumberOfStartPoints() - 1;
	}

	SetCurrentStartPoint(startPoint);
}

char* CLevelList::GetCurrentStartPointName()
{
	if (GetCurrentStartPoint() == -1) 
	{
		return "Default";
	}
	if (GetCurrentStartPoint() < -1 || GetCurrentStartPoint() >= GetNumberOfStartPoints())
	{
		return "???";
	}

	int startPointData = (0x6E7E50 + (GetCurrentStartPoint() * 80)); // g_startpoints[]
	return (char*)(startPointData);
}

CLevelList* GetLevelList()
{
	return (CLevelList*)0x6E7E08;
}