#include "AIFelonySystemFelonyManager.h"

AIFelonySystemFelonyManagerClass* GetFelonyManager()
{
    return *(AIFelonySystemFelonyManagerClass**)(0x70C5C8);
}

/*
void __thiscall
SetChaseCarMaxChasers__32AIFelonySystemFelonyManagerClassUc31AIFelonySystemPatrolCarTypeEnum
		  (AIFelonySystemFelonyManagerClass *this,uint8 inChaseCarMaxChasers,int inPatrolCarType)
*/
void AIFelonySystemFelonyManagerClass::SetChaseCarMaxChasers(int inChaseCarMaxChasers, int inPatrolCarType)
{
	((void(__thiscall*)(AIFelonySystemFelonyManagerClass*, int, int))0x430783)(this, inChaseCarMaxChasers, inPatrolCarType);
}

void AIFelonySystemFelonyManagerClass::SetVehicleFelonyLevel(CVehicle* pVehicle, int CarType, float Value)
{
    ((void(__thiscall*)(AIFelonySystemFelonyManagerClass*, CVehicle*, float, int))0x430FF9)(this, pVehicle, Value, CarType);
}

void AIFelonySystemFelonyManagerClass::SetFelonyLevel(CCharacter* pCharacter, int CarType, float Value)
{
    ((void(__thiscall*)(AIFelonySystemFelonyManagerClass*, CCharacter*, float, int))0x430A18)(this, pCharacter, Value, CarType);
}

void AIFelonySystemFelonyManagerClass::CreatePatrolCharacterOnFoot(Vector4* position, float angle)
{
    ((void(__thiscall*)(AIFelonySystemFelonyManagerClass*, Vector4*, float))0x429949)(this, position, angle);
}

void AIFelonySystemFelonyManagerClass::CreatePatrolVehicleUnit(Vector4* position, float angle, bool snapToTerrain, bool useSecondaryVehicleType)
{
	((void(__thiscall*)(AIFelonySystemFelonyManagerClass*, Vector4*, float, bool, bool))0x429973)(this, position, angle, snapToTerrain, useSecondaryVehicleType);
}

void AIFelonySystemFelonyManagerClass::CreatePatrolHelicopterUnit(Vector4* Position, AIFelonySystemPatrolCarTypeEnum CarType, float Angle)
{
    ((void(__thiscall*)(AIFelonySystemFelonyManagerClass*,Vector4*, float, AIFelonySystemPatrolCarTypeEnum))0x4299A3)(this, Position, Angle, CarType);
}
