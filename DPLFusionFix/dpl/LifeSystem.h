#pragma once
#include "Player.h"
#include "Marker.h"

class CLifeSystem {
public:
	int field0;
	int field4;
	CLifePlayer* pPlayer;
	int m_iPlayerIsDeadTimer;
	float m_fPingInRadius;
	float m_fPingOutRadius;
	unsigned int m_lifeTimeClicks;

	CLifePlayer* GetPlayer();

	void GetPingRadii(float* r);

	// 0x47199F - RegisterPlayerActor__11CLifeSystemGQ27hamstert8CAutoPtr2Z10ILifeActorZi(CLifeSystem* this,CAutoPtr<> actor);
};


CLifeSystem* GetLifeSystem();