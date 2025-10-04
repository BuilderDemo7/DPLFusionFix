#pragma once
#include "..\core\Vector.h"
#include "Character.h"
#include "VehicleModel.h"
#include "VehicleManager.h"
#include "CharacterManager.h"
#include "VehicleSpecification.h"
#include "Weapons.h"
#include "Weapon.h"
#include "LifeSystem.h"
#include "Vehicle.h"
#include "DebugOptions.h"
#include "LifeEnvironment.h"
#include "ProfileSettings.h"
#include "Viewport.h"
#include "GameOverlayManager.h"
#include "MenuManager.h"

#include "..\Settings.h"

#include <windows.h>

#define WAIT_FOR_VEHICLE_TO_LOAD
#define CHECK_IS_VEHICLE_LOADED
#define _WINDOWED_MODE_VIEWPORT_RESTRETCH

HWND GetHamsterHWND();
Vector GetWindowClientSize(HWND hwnd);

void LoadDevMenu();

typedef enum SpooledPackageType {
    SpooledPackageType_Vehicles=0,
    SpooledPackageType_Missions=1,
    SpooledPackageType_CharacterSkins=2,
    SpooledPackageType_CharacterAnimations=3,
    SpooledPackageType_Audio=4,
    SpooledPackageType_Localisation=5,
    SpooledPackageType_Subtitles=6,
    SpooledPackageType_numSpooledPackageTypes=7,
    SpooledPackageType_Uninitialised=8
} SpooledPackageType;

namespace Common {
	static CCharacter* originalPlayer;
};

bool* GetGameIsPaused();
void SetGameIsPaused(bool paused);

int CreateObject(int factoryType);

void AddVehicleToGarage(int vehicleType);

CCharacter* CreateCharacter(ECharacterType eType, Vector* pos, float heading, ECharacterRoles eRole = eCharacterRole_Civilian, EnumAnimCondition eCondition = eACond_Default, float health = 1.0f);

CVehicle* CreateVehicle(tVehicleModelUID id, Vector* pos, float angle, float r = 1, float g = 1, float b = 1, bool autoAcquirable = true);
void GiveWeaponToPlayer(EWeapons eWeapon);
void TeleportPlayer(Vector* pos);
CWeapon* GetPlayerWeapon();
void SetPlayerModel(int model);

void DeleteVehicle(CVehicle* vehicle);
void EjectAllFromVehicle(CVehicle* vehicle);

void SetPlayerAsCharacter(CCharacter* newCharacter);
void SetPlayerBackToOriginal();

void OnGameStep();