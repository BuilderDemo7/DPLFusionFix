#include "Player.h"

CPlayerDriverBehaviour* CLifePlayer::GetDriverBehaviour()
{
    return pDriverBehaviour;
}

void CLifePlayer::SetPlayerCanMove(bool can)
{
	*(bool*)((int)this + 0xC) = can;
}

bool* CLifePlayer::GetPlayerCanMove()
{
	return (bool*)((bool)(int)(this + 0xC));
}