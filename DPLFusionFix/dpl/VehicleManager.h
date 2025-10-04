#pragma once
#include "VehicleSpecification.h"
#include "VehicleModel.h"
#include "Vehicle.h"

class CVehicle;

class CVehicleManager {
public:
	CVehicle** CreateVehicle(CVehicle** pVehicle, tVehicleModelUID tVehicle, float x, float y, float z, float w, float fRotation, bool bsnapterrain, bool bsnapphysics, bool bnetworkpublish);
	void EjectAllFromVehicle(CVehicle* pVehicle);
	void DeleteObject(CVehicle* pVehicle);

	CVehicle* GetVehicle(int id);
};


CVehicleManager* GetVehicleManager();