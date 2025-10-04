#pragma once

#include "ECheat.h"

class CProfileSettings {
public:
	bool IsCheatActive(ECheat cheat);
	void UnlockCheat(ECheat cheat);
	void EnableCheat(ECheat cheat);

	void SetCheatStatus(ECheat cheat, bool value);

	int  GetMoney();
	void SetMoney(int Money);
	void AddMoney(int Amount);

	float GetOdometer();
	void SetOdometer(float odometer);

	int GetGameDifficulty();
	void SetGameDifficulty(int diff);

	bool* GetGameIsCompleted();
	void SetGameIsCompleted(bool complete);
};


CProfileSettings* GetProfileSettings();