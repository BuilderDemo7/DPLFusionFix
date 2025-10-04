#include "Weapon.h"
#include "common.h"

void CWeapon::Shoot()
{
	((void(__thiscall*)(CWeapon*))0x525268)(this);
}

void CWeapon::Reload()
{
	((void(__thiscall*)(CWeapon*))0x5253B4)(this);
}

void CWeapon::Step()
{
	if (this == GetPlayerWeapon())
	{
		if (m_bRapidWeaponFire)
		{
			CooldownTimer = 0;
			CooldownTimerTwo = 0;
		}
		if (m_bInfiniteAmmo)
			CurrentAmmo = 99;
	}
	if (CooldownTimer > 0)
		CooldownTimer--;

	if (CooldownTimerTwo > 0)
		CooldownTimerTwo--;
}

bool CWeapon::IsAutomatic()
{
	return 	((bool(__thiscall*)(CWeapon*))0x525312)(this);
}

bool CWeapon::IsAutomaticHook()
{
	bool result = IsAutomatic();
	if (this == GetPlayerWeapon())
	{
		if (m_bEverythingIsAutofire)
			result = true;

	}
	return result;
}

void __declspec(naked) RapidFireCheat_Hook()
{
}
