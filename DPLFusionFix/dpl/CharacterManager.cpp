#include "CharacterManager.h"

CCharacterManager* GetCharacterManager()
{
	return (CCharacterManager*)(*(int*)0x70C6E0); // 0x0070C6A4
}

/* CCharacter ** __thiscall
CreateCharacter__17CCharacterManagerQ42d46assets9character4typeRC4MAv4f17EnumAnimCondition15ECharacterRolesT2bGQ27hamstert8CAutoPtr2Z7IWeaponZiT2T7f
(CCharacterManager *this, int eType, MAv4 *v4Position, MAreal fHeading,
	EnumAnimCondition eAnimCondition, ECharacterRoles eRole, MAv4 *velocity, bool strafe,
	void **weaponPtr, MAv4 *targetPosition, bool crouch, float health)
*/
/*
// No
CCharacter** CCharacterManager::CreateCharacter(ECharacterType eType, CCharacter** pCharacter, CVehicle** piVehicle, Vector4* position, ECharacterRoles eRole, EVehicleDoor eDoor, EnumAnimCondition eCondition, eAnimState eState, CWeapon** weapon, eWeaponAnimType eHanded, float health)
{
	return ((CCharacter** (__thiscall*)(CCharacterManager*, ECharacterType, CVehicle**, Vector4*, ECharacterRoles, EVehicleDoor, EnumAnimCondition, eAnimState, CWeapon**, eWeaponAnimType, float))0x4F723B)(this, eType, piVehicle, position, eRole, eDoor, eCondition, eState, weapon, eHanded, health);
}
*/
CCharacter* CCharacterManager::CreateCharacter
(AutoPtr<CCharacter, int> *outChar, int eType, Vector4 *v4Position, float fHeading,
	EnumAnimCondition eAnimCondition, ECharacterRoles eRole, Vector4 *velocity, bool strafe,
	AutoPtr<CWeapon, int> weaponPtr, Vector4 *targetPosition, bool crouch, float health)
{
	return ((CCharacter*(__thiscall*)(
		CCharacterManager*, 
		AutoPtr<CCharacter, int> *, // it doesn't have in the PS2 preview build but it's kind of pointless when it can just be returned sometimes
		int, 
		Vector4*, 
		float,
		EnumAnimCondition,
		ECharacterRoles,
		Vector4*,
		bool,
		AutoPtr<CWeapon, int>,
		Vector4*,
		bool,
		float))0x4F723B)(
			this, outChar, eType, v4Position, fHeading, eAnimCondition, eRole, velocity, strafe, weaponPtr, targetPosition, crouch, health);
}

// fake
/*
// CAutoPtr<>CreateCharacter__17CCharacterManagerQ42d46assets9character4typeRC4MAv4f17EnumAnimCondition15ECharacterRolesT2bGQ27hamstert8CAutoPtr2Z7IWeaponZiT2T7f(CCharacterManager *this,ECharacterType eType,MAv4 *v4Position,MAreal fHeading,EnumAnimCondition eAnimCondition,ECharacterRoles eRole,MAv4 *velocity,bool strafe,CAutoPtr<> weaponPtr,MAv4 *targetPosition,bool crouch,float health)
CCharacter** CCharacterManager::CreateCharacter(ECharacterType eType, Vector4 *v4Position, float fHeading, EnumAnimCondition eAnimCondition, ECharacterRoles eRole, Vector4 *velocity, bool strafe, CWeapon** weaponPtr, Vector4 *targetPosition, bool crouch, float health)
{
	return ((CCharacter** (__thiscall*)(CCharacterManager*, ECharacterType, Vector4*, float, EnumAnimCondition, ECharacterRoles, Vector4*, bool, CWeapon**, Vector4*, bool, float))0x4F736E)(this, eType, v4Position, fHeading, eAnimCondition, eRole, velocity, strafe, weaponPtr, targetPosition, crouch, health);
}
*/