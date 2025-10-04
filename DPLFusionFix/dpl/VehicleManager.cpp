#include "VehicleManager.h"
#include <iostream>

// FUNCTION POINTERS 
// CVehicleManager
// 0x5B21EB
// 0x5B0B3C
// 0x5B0200
// 0x5B01E2
// 0x5B021E
// 0x5B23F3
// 0x5B2563
// 0x5B2BDA
// 0x5B2BFB - CVehicleManager::Draw(hamster::CAutoPtr<IViewport_Draw, int>)
// 0x5B10E9 - CVehicleManager::CreateVehicle(void*, tVehicleModelUID)
// 0x5B1181
// 0x5B154B - CVehicleManager::CreateVehicle(tVehicleModelUID, MAv4, float, bool, bool, bool)
// 0x5B02DD - CVehicleManager::CreateUninitialisedVehicle(tVehicleModelUID &)
// 0x5B2720 - CVehicleManager::AddVehicleToPhysicsList(CVehicle);
// Unknown
// 0x5AFF3B
// 0x5AFF45
// 0x5AFF5B
// 0x5AFF50
// 0x5AFF66
// 0x5AFF71
// 0x5AFF7C
// 0x566D65
// 0x5FC9A9

CVehicleManager* GetVehicleManager()
{
    return (CVehicleManager*)(*(int*)(0x70C830) - 4);
}

CVehicle* CVehicleManager::GetVehicle(int id)
{
	return (CVehicle*)(*(int*)(this+(0x10+(id*4))));
}

// CAutoPtr<> CreateVehicle__15CVehicleManager16tVehicleModelUIDG4MAv4fbN24(CVehicleManager *this,tVehicleModelUID eType,MAv4 position,MAreal fHeading,bool bsnapterrain,bool bsnapphysics,bool bnetworkpublish)
CVehicle** CVehicleManager::CreateVehicle(CVehicle** pVehicle, tVehicleModelUID tVehicle, float x, float y, float z, float w, float fRotation, bool bsnapterrain, bool bsnapphysics, bool bnetworkpublish)
{
    return ((CVehicle** (__thiscall*)(CVehicleManager*, CVehicle**, tVehicleModelUID, float, float, float, float, float, bool, bool, bool))0x5B154B)(this, pVehicle, tVehicle, x, y, z, w, fRotation, bsnapterrain, bsnapphysics, bnetworkpublish);
}

// DeleteObject__15CVehicleManagerRQ27hamstert8CAutoPtr2ZC8IVehicleZi(CVehicleManager *this,CAutoPtr<> *rpiVehicle)
void CVehicleManager::DeleteObject(CVehicle* pVehicle)
{
	((void* (__thiscall*)(CVehicleManager*, CVehicle*))0x5B2720)(this, pVehicle);
}

void CVehicleManager::EjectAllFromVehicle(CVehicle* pVehicle)
{
    ((void* (__thiscall*)(CVehicleManager*, CVehicle*))0x5B10E9)(this, pVehicle);
}
