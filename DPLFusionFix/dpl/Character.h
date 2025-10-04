#pragma once
#include <map>
#include <iostream>
#include <list>
#include "..\core\Vector.h"
#include "Vector4.h"
#include "Vehicle.h"
#include "Viewport.h"
#include "..\core\Matrix.h"
#include "AnimInstance.h"
#include "Weapon.h"
#include "ECharAnimType.h"
#include "EVehicleDoor.h"
#include "AutoPtr.h"

class CVehicle;
class CCharacter;
class CPCViewport;

class CCharacterRendering {
public:

};


class CCharacter {
public:

	int GetCharacterType();

	void GetPosition(Vector4* pos);
	Vector4* GetVelocity();

	void SetArmour(float armour);

	bool IsCrouching();
	void Crouch(bool a1, bool a2);

	void SetScaredOfBeingRunnedOver(int scareType);

	void Draw(CPCViewport viewport);

	void SetArrested();
	
	void ForceIdleMode();
	void PlayMissionAnimation(unsigned int animHash, bool unk);
	void KillMissionAnimations();
	
	void EnterVehicle(CVehicle* pVehicle, int nDoor, bool hijack, bool unk2);
	void ExitVehicle(int Reason, int unk1, int unk2);
	///<summary>
    ///Ejects the character from the vehicle.
    ///</summary>
	void EjectFromVehicle();
	
	void GetAnimationRootMatrix(Matrix* m, HAnimClip* clip, float time);
	bool ValidWeapon();

	bool IsDriving();

	void SetPosition(Vector4* pos);
	void SetModel(int model);
	void SetAnimType(int type);

	int* GetAnimTypePointer();
	int GetPointer();
	int GetVTableAddress();

	void DrawCrosshair(int Viewport, int unk);
	void DrawCrosshairHook(int Viewport, int unk);

	void Melee(CCharacter* target);

	void SetTarget(Vector4 target);

	void Walk(Vector4 velocity, bool strafe, bool scared);
	void Walk(Vector4* velocity, bool strafe, bool scared);
	void FaceDirection(Vector4 worldVec);
	void FaceDirection(Vector4* worldVec);

	void HolsterWeapon();
	void DrawWeapon(AutoPtr<CWeapon, int> weapon);
	void ReloadWeapon();
	void ShootWeapon(bool hitTarget, bool checkTarget, float angularInaccuracy);

	CCharacterRendering* GetRendering();
	CVehicle* GetVehicle();
	CVehicle* GetEnteringVehicle();
	float GetAngle();
	Matrix* GetMatrix();
	HAnimInstance* GetAnimInstance();
	CWeapon* GetWeapon();

	bool operator==(CCharacter* other);
	bool operator!=(CCharacter* other);

	///<summary>
	///Teleports the player instantly into a vehicle
	///</summary>
	void TeleportToVehicle(CVehicle* pVehicle, int seat, bool unk1);

	EVehicleDoor GetVehicleDoor();

	///<summary>
    ///Sets the character's health to a certain value.
    ///</summary>
	void SetHealth(float health);
	///<summary>
     ///Returns the amount of health of this character.
    ///</summary>
	float GetHealth();

	bool IsValid();

	void SetRole(int role);
	int GetRole();

	static void OnCreate(int address);
	static void OnDelete(int address);
	static void Hook_CharacterCtor();
	static void Hook_CharacterDtor();

	void SetAllowGetOutOfVehicle(bool allow);
	bool GetAllowGetOutOfVehicle();
	void AllowVehicleExit(bool enable);

	int GetId();
	
	bool GetIsSpawned();
	void SetIsSpawned(bool spawned);

	int GetModel();

	// junkyard
	void Unknown(CVehicle* pVehicle, CCharacter* pTarget);
	void Unknown2(CVehicle* pVehicle, CVehicle* pTarget);
	void Unknown3();
	void Unknown4();
	
};

static int MaxCharacters = 256;
static CCharacter* Characters[256] = { NULL };
static int CharactersCount = 0;
CCharacter* GetCharacter(int id);