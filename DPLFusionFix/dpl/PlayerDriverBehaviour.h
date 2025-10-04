#pragma once
#include "CharacterWeapons.h"
#include "Character.h"
#include "..\core\Matrix.h"
#include "PlayerInVehicleInputs.h"

/*
struct fixed_map<hamster::CAutoPtr<const ICharacter, int>, AIFelonySystemFelonySuspectClass, 5, less<hamster::CAutoPtr<const ICharacter, int> >, ri::fuz_container_failure_policy> {
	struct fixed_list<pair<const hamster::CAutoPtr<const ICharacter, int>, AIFelonySystemFelonySuspectClass>, 5, ri::fuz_container_failure_policy> m_list;
	struct less<hamster::CAutoPtr<const ICharacter, int> > m_compare;
	undefined field2_0xcbd;
	undefined field3_0xcbe;
	undefined field4_0xcbf;
};

struct CInputMap {
	struct CInputMap__vtable *__vtable; // Inherited from IInterface
	struct fixed_map<int, int, 1, less<int>, ri::fuz_container_failure_policy> test;
	struct fixed_map<EInputAction, CInputMap::SButton, 16, less<EInputAction>, ri::fuz_container_failure_policy> m_mButtons;
	struct fixed_map<EInputAction, hamster::CAutoPtr<IStickInput, int>, 16, less<EInputAction>, ri::fuz_container_failure_policy> m_mSticks;
	struct fixed_map<EInputAction, hamster::CAutoPtr<IInput, int>, 16, less<EInputAction>, ri::fuz_container_failure_policy> m_mGeneric;
	struct CAutoPtr<IDefineInputMap, int> m_piDefine;
	enum GAMEPAD_ID m_ePadID;
	struct CGetInput_Button m_getButton;
	struct CGetInput_Stick m_getStick;
	struct CAutoPtr<IInputManager_detail, int> m_piManager;
};
*/

struct CPlayerVehicleBehaviour {
	struct CPlayerVehicleBehaviour__vtable *__vtable; // Inherited from IInterface
	//struct CAutoPtr<IInputMap, int> m_piInputMap;
	//struct CAutoPtr<IVehicleBehaviour_InputMap, int> m_piBehaviour;
};

class CPlayerDriverBehaviour {
public:
	CCharacterWeapons* GetWeapons();

	CCharacter* GetCharacter();
	bool GetIsStrafing();
	PlayerInVehicleInputs* GetVehicleInputs();
	void SetCharacter(CCharacter* character);
	CPlayerVehicleBehaviour* GetVehicleBehaviour();
	void SetVehicleBehavior(CPlayerVehicleBehaviour* behaviour);
	bool HasShotRecently();
	void AddAllWeapons();
	bool IsFreeAiming();
	void PlayerIsStuck();
};