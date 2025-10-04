#include <iostream>

#include "Character.h"
#include "GameOverlayManager.h"

#include "LifeSystem.h"
#include "Player.h"

// REMINDER:
// 0x64E908 IS the address (in game memmory) to the pointer of functions to this class
// If you find any not here please try it and try to make it usable 
// BUT do not try 0x4F922C, it crashes the game for no reason ;)

// 0070C824 - must be the CCharacterManager struct...

void CCharacter::GetPosition(Vector4* pos)
{
	((void(__thiscall*)(CCharacter*, Vector4*))0x4F2A5E)(this, pos);
}

void CCharacter::Crouch(bool a1, bool a2)
{
	((void(__thiscall*)(CCharacter*, bool, bool))0x4E7ADC)(this, a1, a2);
}

int CCharacter::GetCharacterType()
{
	return ((int(__thiscall*)(CCharacter*, CVehicle*))0x4E7990)(this, this->GetVehicle());
}

void CCharacter::SetArmour(float armour)
{
	((void(__thiscall*)(CCharacter*, float, bool))0x4E7A1E)(this, armour, false);
}

bool CCharacter::IsCrouching()
{
	((void(__thiscall*)(CCharacter*, bool, bool))0x4E7ADC)(this, false, false);
	return false;
}

void CCharacter::SetScaredOfBeingRunnedOver(int scareType)
{
	((void(__thiscall*)(CCharacter*, int))0x4E7AF7)(this, scareType);
}

void CCharacter::Draw(CPCViewport viewport)
{
	((void(__thiscall*)(CCharacter*, CPCViewport))0x4F09AD)(this, viewport);
}

void CCharacter::SetArrested()
{
	((void(__thiscall*)(CCharacter*))0x4F2A32)(this);
}

void CCharacter::ForceIdleMode()
{
	((void(__thiscall*)(CCharacter*))0x4E9E0A)(this);
}

void CCharacter::PlayMissionAnimation(unsigned int animHash, bool unk)
{
	((void(__thiscall*)(CCharacter*, unsigned int, bool))0x4E9E24)(this, animHash, unk);
}

void CCharacter::KillMissionAnimations()
{
	((void(__thiscall*)(CCharacter*))0x4E863F)(this);
}

void CCharacter::EnterVehicle(CVehicle* pVehicle, int nDoor, bool hijack, bool unk2)
{
	((void(__thiscall*)(CCharacter*, CVehicle*, int, bool, bool))0x4EBF46)(this, pVehicle, nDoor, hijack, unk2);
}

void CCharacter::ExitVehicle(int Reason, int unk1, int unk2)
{
	((void(__thiscall*)(CCharacter*, int, int, int))0x4EB560)(this, Reason, unk1, unk2);
}

// the true EnterVehicleImmediate
void CCharacter::TeleportToVehicle(CVehicle* pVehicle, int seat, bool unk1)
{
	((void(__thiscall*)(CCharacter*, CVehicle*, int, bool))0x4EF9EE)(this, pVehicle, seat, unk1);
}

void CCharacter::GetAnimationRootMatrix(Matrix* m, HAnimClip* clip, float time)
{
	((void(__thiscall*)(CCharacter*, Matrix*, HAnimClip*, float))0x4E7FC7)(this, m, clip, time);
}

void CCharacter::EjectFromVehicle()
{
	((void(__thiscall*)(CCharacter*))0x4EA603)(this);
}

void CCharacter::AllowVehicleExit(bool enable)
{
	((void(__thiscall*)(CCharacter*, bool))0x4F29CA)(this, enable);
}

void CCharacter::Melee(CCharacter* target)
{
	((void(__thiscall*)(CCharacter*, CCharacter*))0x4E7B11)(this, target);
}

void CCharacter::ReloadWeapon()
{
	((void(__thiscall*)(CCharacter*))0x4E8D64)(this);
}

void CCharacter::SetTarget(Vector4 target)
{
	((void(__thiscall*)(CCharacter*, Vector4))0x4E8750)(this, target);
}

void CCharacter::Walk(Vector4 velocity, bool strafe, bool scared)
{
	((void(__thiscall*)(CCharacter*, Vector4*, bool, bool))0x4E7990)(this, &velocity, strafe, scared);
}

void CCharacter::Walk(Vector4* velocity, bool strafe, bool scared)
{
	((void(__thiscall*)(CCharacter*, Vector4*, bool, bool))0x4E7990)(this, velocity, strafe, scared);
}

void CCharacter::FaceDirection(Vector4 worldVec)
{
	((void(__thiscall*)(CCharacter*, Vector4*))0x4E7A1E)(this, &worldVec);
}

void CCharacter::FaceDirection(Vector4* worldVec)
{
	((void(__thiscall*)(CCharacter*, Vector4*))0x4E7A1E)(this, worldVec);
}

void CCharacter::DrawWeapon(AutoPtr<CWeapon, int> weapon)
{
	((void(__thiscall*)(CCharacter*, AutoPtr<CWeapon, int>))0x4E8C9D)(this, weapon);
}

void CCharacter::HolsterWeapon()
{
	((void(__thiscall*)(CCharacter*))0x4E8CCC)(this);
}

void CCharacter::ShootWeapon(bool hitTarget, bool checkTarget, float angularInaccuracy)
{
	((void(__thiscall*)(CCharacter*, bool, bool, float))0x4E8D22)(this, hitTarget, checkTarget, angularInaccuracy);
}

// I'm not sure what this is
// looks like AI functions?
void CCharacter::Unknown(CVehicle* pVehicle, CCharacter* pTarget) {
	((void(__thiscall*)(CCharacter*, CVehicle*, CCharacter*))0x4EC2F1)(this, pVehicle, pTarget);
}

void CCharacter::Unknown2(CVehicle* pVehicle, CVehicle* pTarget) {
	((void(__thiscall*)(CCharacter*, CVehicle*, CVehicle*))0x4E8700)(this, pVehicle, pTarget);
}

// this one feels like it returns something.......
void CCharacter::Unknown3() {
	((void(__thiscall*)(CCharacter*, CVehicle*))0x4E8750)(this,this->GetVehicle());
}

// another useless function yet again?
// or am I not calling corresponding parameters?
void CCharacter::Unknown4()
{
	((void(__thiscall*)(CCharacter*, CVehicle*, bool))0x4E9E24)(this, this->GetVehicle(), false);
}

void CCharacter::SetAllowGetOutOfVehicle(bool allow)
{
	((char*)(this + 0x7A6))[0] = allow ? 1 : 0;
}

bool CCharacter::GetAllowGetOutOfVehicle()
{
	return (((char*)(this + 0x7A6))[0] != 0);
}

bool CCharacter::ValidWeapon()
{
	return 	((bool(__thiscall*)(CCharacter*))0x4E8163)(this);
}

// deprecated
bool CCharacter::IsDriving()
{
	return 	((bool(__thiscall*)(CCharacter*))0x4E8163)(this);
}

float CCharacter::GetAngle()
{
	Vector fwd = GetMatrix()->forward;
	return atan2(fwd.X, fwd.Y);
}

void CCharacter::SetPosition(Vector4* pos)
{
	GetMatrix()->pos = { pos->X, pos->Y, pos->Z };
}

void CCharacter::SetModel(int model)
{
	*(int*)((int)this + 0x744) = model;
	*(int*)((int)this + 0x764) = model;
}

int CCharacter::GetModel()
{
	return *(int*)((int)this + 0x744);
}

void CCharacter::SetAnimType(int type)
{
	*(int*)((int)this + 0x63C) = type;
}

int* CCharacter::GetAnimTypePointer()
{
	return (int*)((int)this + 0x63C);
}

void CCharacter::DrawCrosshair(int Viewport, int unk)
{
	((void(__thiscall*)(CCharacter*, int, int))0x4EB954)(this, Viewport, unk);
}

void CCharacter::DrawCrosshairHook(int Viewport, int unk)
{
	if (m_bDisableHUD)
		return;

	DrawCrosshair(Viewport, unk);
}

CCharacterRendering* CCharacter::GetRendering()
{
	return (CCharacterRendering*)((int)this + 1680);
}

CVehicle* CCharacter::GetVehicle()
{
	return *(CVehicle**)((int)this + 0x688);
}

CVehicle* CCharacter::GetEnteringVehicle()
{
	return *(CVehicle**)((int)this + 0x5C8);
}

Matrix* CCharacter::GetMatrix()
{
	return (Matrix*)((int)this + 16);
}

Vector4* CCharacter::GetVelocity()
{
	return (Vector4*)((int)this + 0x534);
}

HAnimInstance* CCharacter::GetAnimInstance()
{
	return  (HAnimInstance*)((int)this + 0x5FC);
}

CWeapon* CCharacter::GetWeapon()
{
	if (!ValidWeapon())
		return nullptr;
	return (CWeapon*)((int)this + 208);
}

int CCharacter::GetPointer() 
{
	return (int)(this);
}

int CCharacter::GetVTableAddress()
{
	return *(int*)(this);
}

bool CCharacter::operator==(CCharacter* other) {
	if (this == other)
		return true;
	return false;
}

bool CCharacter::operator!=(CCharacter* other) {
	return !(*this == other);
}

EVehicleDoor CCharacter::GetVehicleDoor()
{
	return ((EVehicleDoor(__thiscall*)(CCharacter*))0x4E86B4)(this);
}

float CCharacter::GetHealth()
{
	return *(float*)(this + 0x684);
}

void CCharacter::SetHealth(float health)
{
	*(float*)(this + 0x684) = health;
}

void CCharacter::SetRole(int role)
{
	*(int*)(this + 0x770) = role; // old: 0x3E0
}

int CCharacter::GetRole()
{
	return *(int*)(this + 0x770);
}

bool CCharacter::GetIsSpawned()
{
	//return (((int*)(address + 0x680))[0] != 0 && ((int*)(address + 0x674))[0] != 0);
	return (((int*)(this + 0x674))[0] != 0);
}

void CCharacter::SetIsSpawned(bool spawned)
{
	//return (((int*)(address + 0x680))[0] != 0 && ((int*)(address + 0x674))[0] != 0);
	((char*)(this + 0x674))[0] = spawned ? 1 : 0;
}

bool CCharacter::IsValid()
{
	try {
		return (this && *(int*)(this->GetPointer())) == 0x64E928;
	}
	catch (std::exception ex) {
		return false;
	}
}

void CCharacter::OnCreate(int address)
{
	printf("Character Ctor -> %X\n", address);
	if (CharactersCount == MaxCharacters) {
		CharactersCount = 0; // reset index
	}
	if (CharactersCount != MaxCharacters) {
		Characters[CharactersCount] = (CCharacter*)(address);
		CharactersCount++;
	}
}

void CCharacter::OnDelete(int address)
{
	printf("Character Dtor -> %X\n", address);
	CCharacter* character = (CCharacter*)(address + 12);
	if (character != NULL || character != nullptr)
	{
		printf("Deleting character %p from the list ......", character);
		if (character->IsValid()) {
			int id = character->GetId();
			if (id != -1) {
				Characters[id] = NULL;
				CharactersCount--;
			}
		}
	}
}

// Gets the ID from the character to the characters list, returns -1 if not found
int CCharacter::GetId()
{
	for (int id = 0; id < MaxCharacters; id++)
	{
		if (Characters[id] != NULL && Characters[id] == this)
		{
			return id;
		}
	}
	return -1;
}


CCharacter* GetCharacter(int id)
{
	return Characters[id];
}

void _declspec(naked) CCharacter::Hook_CharacterCtor()
{
	// + 5
	static int jump_continue = 0x4EB708 + 5;
	static int calladdr = 0x4F2937;
	static int outECX = 0;
	//static int CALL = 0x4F2937;
	//static int call_next = 0x4F2937;
	// og code:  55 8B EC 83 EC 10
	// our code: E9 B7 5C 9A 0F 10
	/*
	__asm {
		//push eax
		//push edx
		//push ecx
		//push ebp
		//push ebx
		//push esi

		//push ecx
		//call OnCreate

		//pop esi
		//pop ebx
		//pop ebp
		//pop ecx
		//pop edx
		//pop eax

		//push ebp
		//mov ebp, esp
		//sub esp, 0x10
		//push ebx
		//mov ebx, ecx


		//call call_next
		push ebp
		mov ebp, [esp]
		sub esp, 10

		push ecx
		call OnCreate
		//mov[pCharacter], eax
		jmp jump_continue
	}
	*/
	_asm {
		call calladdr

		// EDIT: this code crashes the game so... I got an better idea!!
		// ECX register is the poiner to the character
		// so do 'push' it as the 'int address' parameter
		//push ecx
		//call OnCreate

		//push edx // crash fix

		// Better idea:
		// Let's copy the ECX register memory to an outsider variable and call OnCreate out of __asm!
		mov[outECX], ecx // (stonks)

		//jmp jump_continue
	}
	OnCreate(outECX); // call
	_asm {
		// jump
		jmp jump_continue
	}
}

void _declspec(naked) CCharacter::Hook_CharacterDtor()
{
	// + 6
	static int jmp_cont = 0x4EB8C8;
	static int cptr = 0;
	_asm {
		push ecx
		inc edx
		//xchg eax, esi
		push es
		add al, bh
		mov [cptr], ecx
	}
	OnDelete(cptr);
	_asm
	{
		jmp jmp_cont
	}
}