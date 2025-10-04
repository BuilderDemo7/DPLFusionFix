#pragma once
#include "PlayerDriverBehaviour.h"
#include "Character.h"

class CLifePlayer {
public:
	int field0;
	CCharacter* pCharacter;
	CPlayerDriverBehaviour* pDriverBehaviour;
	bool m_bCanMove;

	CPlayerDriverBehaviour* GetDriverBehaviour();

	void SetPlayerCanMove(bool can);
	bool* GetPlayerCanMove();
};