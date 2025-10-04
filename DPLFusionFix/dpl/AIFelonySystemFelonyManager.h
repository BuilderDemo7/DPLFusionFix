#pragma once
#include "Character.h"
#include "Vehicle.h"
#include "Vector4.h"

enum AIFelonySystemPatrolCarTypeEnum {
	E_PATROLCARTYPE_COP = 0,
	E_PATROLCARTYPE_GOON = 1,
	E_PATROLCARTYPE_NUM_OF = 2,
	E_PATROLCARTYPE_NONE = 3
};

class CVehicle;
class CCharacter;

class AIFelonySystemFelonyManagerClass {
public:
	void SetChaseCarMaxChasers(int inChaseCarMaxChasers, int inPatrolCarType = 0);
	void SetVehicleFelonyLevel(CVehicle* pVehicle, int CarType, float Value);
	void SetFelonyLevel(CCharacter* pCharacter, int CarType, float Value);
	void CreatePatrolCharacterOnFoot(Vector4* position, float angle);
	void CreatePatrolVehicleUnit(Vector4* position, float angle, bool snapToTerrain = false, bool useSecondaryVehicleType = false);
	void CreatePatrolHelicopterUnit(Vector4* Position, AIFelonySystemPatrolCarTypeEnum CarType, float Angle);
};

AIFelonySystemFelonyManagerClass* GetFelonyManager();