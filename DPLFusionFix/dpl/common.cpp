#include "common.h"
#include "Character.h"
#include "VehicleManager.h"
#include "CharacterManager.h"
#include "ResourceManager.h"
#include "LifeSystem.h"
#include "LifeInstances.h"
#include "LifeAcquirableVehicleManager.h"
#include "CharacterCategoryManager.h"
#include "ResidentArea.h"
#include "Vector4.h"
#include <iostream>
#include "AutoPtr.h"
#include "FontManager.h"

using namespace Common;

// 00475BBB - you will thank me later | CAutoPtr<> (CreateObject(EFactoryType_LifeInstance_Character))
// 0055E4B9 - another one?            | CAutoPtr<> (CreateObjectState(EStateType_LoadEssentials))

HWND GetHamsterHWND()
{
	return *(HWND*)(0x710380);
}

Vector GetWindowClientSize(HWND hwnd) 
{
	RECT rect;
	Vector size;
	size.X = 0;
	size.Y = 0;
	size.Z = 0;

	if (GetClientRect(hwnd, &rect)) {
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		size.X = (float)width;
		size.Y = (float)height;
	}

	return size;
}

void LoadDevMenu()
{
	CMenuManager* menuManager = GetMenuManager();
	if (menuManager != NULL)
	{
		if (!menuManager->IsLoaded(EMenu_Dev))
		{
			printf("Loading GUI\\DEV.MEC ...\n");

			menuManager->LoadMenu_THUNK("GUI\\DEV", EMenu_Dev, false);

			printf("GUI\\DEV.MEC Loaded!\n");
		}
	}
}

void OnSimulationDraw(CPCViewport* viewport)
{
	// bruh, damn you CFontManager optimized functions
	/*
	CFontManager* fontman = GetFontManager();
	if (fontman != NULL)
	{
		Vector4 offset;
		offset.X, offset.Y, offset.Z, offset.W = 0;
		FontSpecs spec;
		spec.x = 0.1f;
		spec.y = 0.1f;
		//fontman->DebugPrint(viewport, &spec, const_cast<char*>("Hello"));
		fontman->Print(viewport, &spec, const_cast<char*>("Hello"), offset);
	}
	*/
}

void OnGameStep()
{
	/*
	if (SettingsMgr != NULL)
	{
		if (SettingsMgr->bWindowed_Mode)
		{
			HWND hamsterWnd = GetHamsterHWND();
			Vector windowSize = GetWindowClientSize(hamsterWnd);

			if (windowSize.X != 0 && windowSize.Y != 0)
			{
				CPCViewport* simulationViewport = GetSimulationViewport();
				CPCViewport* genViewport = GetGenericViewport();
				if (simulationViewport != NULL)
				{
					simulationViewport->SetWidth(windowSize.X);
					simulationViewport->SetHeight(windowSize.Y);
				}
				if (genViewport != NULL)
				{
					genViewport->SetWidth(windowSize.X);
					genViewport->SetHeight(windowSize.Y);
				}
			}
		}
	}
	*/

#ifdef _WINDOWED_MODE_VIEWPORT_RESTRETCH
	if (SettingsMgr != NULL)
	{
		if (SettingsMgr->bWindowed_Mode)
		{
			HWND hamsterWnd = GetHamsterHWND();
			int width = GetSystemMetrics(SM_CXSCREEN);
			int height = GetSystemMetrics(SM_CYSCREEN);

			if (width != 0 && height != 0)
			{
				CPCViewport* simulationViewport = GetSimulationViewport();
				CPCViewport* genViewport = GetGenericViewport();
				CPCViewport* mapViewport = NULL;
				COverheadMap* ohMap = GetOverheadMap();
				if (ohMap != NULL)
				{
					mapViewport = ohMap->m_piViewport;
				}
				if (simulationViewport != NULL)
				{
					simulationViewport->SetWidth(width);
					simulationViewport->SetHeight(height);
				}
				if (genViewport != NULL)
				{
					genViewport->SetWidth(width);
					genViewport->SetHeight(height);
				}
				if (mapViewport != NULL)
				{
					mapViewport->SetWidth(width);
					mapViewport->SetHeight(height);
				}
			}
		}
	}
#endif

	if (bDebug_OverrideTime)
	{
		CLifeEnvironment* env = GetEnvironment();
		if (env != NULL)
		{
			float& timeHour = *(float*)((int)GetEnvironment() + 272);
			timeHour = (float)(bDebug_SetTimeHours * 3600);
		}
	}
	if (bDebug_PlayerAlwaysEnabled)
	{
		CLifeSystem* lifeSys = GetLifeSystem();
		if (lifeSys != NULL)
		{
			lifeSys->GetPlayer()->m_bCanMove = true;
		}
	}
	if (bDebug_OverrideGameDiff)
	{
		CProfileSettings* profSet = GetProfileSettings();
		if (profSet != NULL)
		{
			profSet->SetGameDifficulty(bDebug_SetGameDiff);
		}
	}
}

bool* GetGameIsPaused()
{
	return (bool*)(0x6E73E2);
}

void SetGameIsPaused(bool paused)
{
	*(bool*)(0x6E73E2) = paused;
}

int CreateObject(int factoryType)
{
	return ((int(__cdecl*)(int))0x483A3D)(factoryType);
	//((void(__thiscall*)(int))0x483A3D)(factoryType);
}

void AddVehicleToGarage(int vehicleType)
{
	((void(__fastcall*)(int))0x546272)(vehicleType);
}

void EjectAllFromVehicle(CVehicle* vehicle)
{
	if (GetVehicleManager() == NULL)
		return;

	GetVehicleManager()->EjectAllFromVehicle(vehicle);
}

CCharacter* CreateCharacter(ECharacterType eType, Vector* pos, float heading, ECharacterRoles eRole, EnumAnimCondition eCondition, float health)
{
	CCharacter* pChar = NULL;

	GetResourceManager()->RequestEntity(2, eType, NULL, 1);
	GetResourceManager()->SetEntityPriority(2, eType, 1);
	bool loaded = (GetResourceManager()->IsEntityLoaded(2, eType));
	for (int attempt = 0; attempt < 20; attempt++) {
		loaded = (GetResourceManager()->IsEntityLoaded(2, eType));
		if (loaded)
			break;
		GetResourceManager()->SetEntityPriority(2, eType, 1);
	}

	if (GetResourceManager()->IsEntityLoaded(2, eType))
	{
		//CVehicleSpecification::g_bTankEnable = true;
		AutoPtr<CWeapon, int> weaponPtr = AutoPtr<CWeapon, int>();
		AutoPtr<CCharacter, int> *out = new AutoPtr<CCharacter, int>();
		GetCharacterManager()->CreateCharacter(out, eType, &Vector4(pos->X, pos->Y, pos->Z, 1), heading, eCondition, eRole, new Vector4(), false, weaponPtr, new Vector4(), false, health);
		//CCharacter** out = GetCharacterManager()->CreateCharacter(eType, &Vector4(pos->X, pos->Y, pos->Z, 1), 0, eCondition, eRole, &Vector4(0,0,0,0), false, NULL, &Vector4(0,0,0,0), false, health);
		pChar = out->m_pPointer;
		//CVehicleSpecification::g_bTankEnable = false;

		if (pChar)
		{
			return pChar;
		}
	}
	/*
	else
	{
		printf("Required assets for %d are not loaded yet.", id);
	}
	*/
	
	return pChar;
}

void DeleteVehicle(CVehicle* vehicle)
{
	//GetLifeAcquirableVehicleManager()->RemoveVehicle(vehicle, 1);
	if (vehicle->IsValid())
	{
		GetVehicleManager()->EjectAllFromVehicle(vehicle);

		// Placeholder
		SVehicleManipulationPacket packetForMoving;
		packetForMoving.fThrust = 0.001f;
		vehicle->SetDrivingType(4, true); // set physics & render priority to 4
		vehicle->SendManipulationPacket(&packetForMoving); // activate it's physics thru a manipulation packet
		vehicle->SetPosition(Vector(3000, 0, 3000));

		// just in case the spool centre deletes it.
		if (vehicle->IsValid())
		{
			vehicle->SetVelocity(Vector(0, 0, 0));
			
			packetForMoving.fThrust = 0;
			vehicle->SendManipulationPacket(&packetForMoving); // make it stop
		}
	}

	// crashes the game
	//((void(__fastcall*)(AutoPtr<IHandlingInternal, int>, CVehicle*))0x5B28F1)(vehicle->m_piQueryHandling, vehicle);
}

CVehicle* CreateVehicle(tVehicleModelUID id, Vector* pos, float angle, float r, float g, float b, bool autoAcquirable)
{
    CVehicle* pCar = nullptr;

	// NO, YOU DON'T!!
	// NOTE: Requesting entity twice can crash the game!
	//GetResourceManager()->RequestEntity(0, id, NULL, 1);
#ifdef WAIT_FOR_VEHICLE_TO_LOAD
	GetResourceManager()->SetEntityPriority(0, id, 1);
	bool loaded = (GetResourceManager()->IsEntityLoaded(0, id));
	for (int attempt = 0; attempt < 20; attempt++) {
		loaded = (GetResourceManager()->IsEntityLoaded(0, id));
		if (loaded)
			break;
		GetResourceManager()->SetEntityPriority(0, id, 1);
		GetResourceManager()->RequestEntity(0, id, NULL, 1);
	}

#endif
#ifdef CHECK_IS_VEHICLE_LOADED
    if (GetResourceManager()->IsEntityLoaded(0, id))
#endif
    {   
//#ifndef WAIT_FOR_VEHICLE_TO_LOAD
//		GetResourceManager()->RequestEntity(0, id, NULL, 1);
//#endif

		CVehicleSpecification::g_bTankEnable = true;
		CVehicle** out = GetVehicleManager()->CreateVehicle(&pCar, id, pos->X, pos->Y, pos->Z, 25.0f, angle, 0, 1, 1);
		pCar = *out;
		CVehicleSpecification::g_bTankEnable = false;

        if (pCar)
        {
			if (autoAcquirable)
				GetLifeAcquirableVehicleManager()->AddVehicle(pCar, 1);

            pCar->SetColor(r, g, b);

			return pCar;
        }
        else
        {
            printf("Failed to create %d!\n", id);
			return NULL;
		}
    }
#ifdef WAIT_FOR_VEHICLE_TO_LOAD
    else
    {
		printf("Required assets for %d are not loaded yet.\n", id);
		return NULL;
    }
#endif

	return pCar;
}

void GiveWeaponToPlayer(EWeapons eWeapon)
{
    CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();

    CCharacterWeapons* weaps = player->GetWeapons();
    weaps->AddWeapon(eWeapon, 9999, 1);
}

void TeleportPlayer(Vector* pos)
{
    if (!GetLifeSystem())
        return;
    CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();
    
    if (!player)
        return;

    Vector4 newPos = { pos->X, pos->Y, pos->Z, 1.0f };
    player->GetCharacter()->SetPosition(&newPos);
}

CWeapon* GetPlayerWeapon()
{
    if (!GetLifeSystem())
        return nullptr;
    CPlayerDriverBehaviour* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour();

    if (!player)
        return nullptr;

    return player->GetCharacter()->GetWeapon();
}

void SetPlayerModel(int model)
{
    if (!GetLifeSystem())
        return;
    CCharacter* player = GetLifeSystem()->GetPlayer()->GetDriverBehaviour()->GetCharacter();

    if (!player)
        return;

    if (GetResourceManager()->IsEntityPresent(2, model))
    {
        GetResourceManager()->SetEntityPriority(2, model, 1);
        GetCCM()->SetPlayerAvatar(model);
        player->SetModel(model);
    }

}

void SetPlayerAsCharacter(CCharacter* newCharacter)
{
	CLifePlayer* plr = GetLifeSystem()->GetPlayer();
	if (!originalPlayer)
	{
		originalPlayer = plr->GetDriverBehaviour()->GetCharacter();
	}
	// global hack
	*(int*)( *(int*)(0x6E8E28) + 88 ) = newCharacter->GetPointer();
	plr->GetDriverBehaviour()->SetCharacter(newCharacter);
	*(int*)(GetLifeSystem() + 8) = newCharacter->GetPointer();
}

void SetPlayerBackToOriginal()
{
	CLifePlayer* plr = GetLifeSystem()->GetPlayer();
	if (originalPlayer) {
		*(int*)(*(int*)(0x6E8E28) + 88) = originalPlayer->GetPointer();
		plr->GetDriverBehaviour()->SetCharacter(originalPlayer);
	}
}