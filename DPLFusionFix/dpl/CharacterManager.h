#pragma once
#include "Character.h"
#include "AutoPtr.h"

#include "ECharacterType.h"
#include "ECharacterRoles.h"
#include "EVehicleDoor.h"
#include "EAnimStates.h"
#include "eWeaponAnimType.h"

#include "Weapon.h"
#include "Vector4.h"

#include "Vehicle.h"

class CCharacterManager {
public:
	CCharacter* CreateCharacter(AutoPtr<CCharacter, int> *outChar, int eType, Vector4 *v4Position, float fHeading,
		EnumAnimCondition eAnimCondition, ECharacterRoles eRole, Vector4 *velocity, bool strafe,
		AutoPtr<CWeapon, int> weaponPtr, Vector4 *targetPosition, bool crouch, float health);
	// fake
	//CCharacter** CreateCharacter(ECharacterType eType, Vector4 *v4Position, float fHeading, EnumAnimCondition eAnimCondition, ECharacterRoles eRole, Vector4 *velocity, bool strafe, CWeapon** weaponPtr, Vector4 *targetPosition, bool crouch, float health);
};

CCharacterManager* GetCharacterManager();