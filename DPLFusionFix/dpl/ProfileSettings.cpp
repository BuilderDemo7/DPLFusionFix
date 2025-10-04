#include "ProfileSettings.h"

bool CProfileSettings::IsCheatActive(ECheat cheat)
{
    return ((bool(__thiscall*)(CProfileSettings*, ECheat))0x4C2AB6)(this, cheat);
}

void CProfileSettings::UnlockCheat(ECheat cheat)
{
    ((void(__thiscall*)(CProfileSettings*, ECheat))0x4C243F)(this, cheat);
}

void CProfileSettings::EnableCheat(ECheat cheat)
{
    ((void(__thiscall*)(CProfileSettings*, ECheat))0x4C249B)(this, cheat);
}

void CProfileSettings::SetCheatStatus(ECheat cheat, bool value)
{
    if (cheat < eCheat_NUM_CHEATS)
    {
        char* cheatsData = (char*)((int)this + 0x13060);
        cheatsData[cheat] = value ? 3 : 1;
    }

}

int CProfileSettings::GetMoney()
{
    return *(int*)((int)this + 0x884);
}

void CProfileSettings::SetMoney(int Money)
{
    *(int*)((int)this + 0x884) = Money;
}

float CProfileSettings::GetOdometer()
{
	return *(float*)((int)this + 0x88C);
}

void CProfileSettings::SetOdometer(float odometer)
{
	*(float*)((int)this + 0x88C) = odometer;
}

int CProfileSettings::GetGameDifficulty()
{
	return *(int*)((int)this + 0x890);
}

void CProfileSettings::SetGameDifficulty(int diff)
{
	*(int*)((int)this + 0x890) = diff;
}

bool* CProfileSettings::GetGameIsCompleted()
{
	return (bool*)((int)this + 0x894);
}

void CProfileSettings::SetGameIsCompleted(bool complete)
{
	*(bool*)((int)this + 0x894) = complete;
}

void CProfileSettings::AddMoney(int Amount)
{
    SetMoney(GetMoney() + Amount);
}

CProfileSettings* GetProfileSettings()
{
    return *(CProfileSettings**)(0x70C7A0);
}
