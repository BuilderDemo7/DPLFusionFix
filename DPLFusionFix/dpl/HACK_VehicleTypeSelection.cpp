#include "HACK_VehicleTypeSelection.h"
// FUN Fact: most of this code was recycled from the January 6 Build of the game :D

int* _22VEHICLE_SELECTION_HACK$currentVehicle = (int*)0x68ee20;
int* _22VEHICLE_SELECTION_HACK$currentVehicleType = (int*)0x68ee24;

sNameToEVehicleType* VEHICLE_SELECTION_HACK::GetVehicleTypeMatchTable()
{
	return *(sNameToEVehicleType**)0x6ec5b4;
}

void VEHICLE_SELECTION_HACK::PrevVehicle()
{
	*_22VEHICLE_SELECTION_HACK$currentVehicle = *_22VEHICLE_SELECTION_HACK$currentVehicle - 1;
	if (*_22VEHICLE_SELECTION_HACK$currentVehicle < -1) {
		*_22VEHICLE_SELECTION_HACK$currentVehicle = GetNumVehicles() - 1;
	}

	// Set default vehicle 
	if (*_22VEHICLE_SELECTION_HACK$currentVehicle == -1) {
		*_22VEHICLE_SELECTION_HACK$currentVehicleType = *_22VEHICLE_SELECTION_HACK$currentVehicle;
		return;
	}

	// Validate the vehicle from the vehicle type match table
	sNameToEVehicleType* vehicleTypeMatchTable = GetVehicleTypeMatchTable();
	if (vehicleTypeMatchTable != NULL) {
		sNameToEVehicleType currentVehicleTypeMatch = vehicleTypeMatchTable[*_22VEHICLE_SELECTION_HACK$currentVehicle];

		*_22VEHICLE_SELECTION_HACK$currentVehicleType = currentVehicleTypeMatch.type;
	}
}

void VEHICLE_SELECTION_HACK::NextVehicle()
{
	*_22VEHICLE_SELECTION_HACK$currentVehicle = *_22VEHICLE_SELECTION_HACK$currentVehicle + 1;
	if (*_22VEHICLE_SELECTION_HACK$currentVehicle >= GetNumVehicles()) {
		*_22VEHICLE_SELECTION_HACK$currentVehicle = -1;
	}

	// Set default vehicle 
	if (*_22VEHICLE_SELECTION_HACK$currentVehicle == -1) {
		*_22VEHICLE_SELECTION_HACK$currentVehicleType = *_22VEHICLE_SELECTION_HACK$currentVehicle;
		return;
	}
	
	// Validate the vehicle from the vehicle type match table
	sNameToEVehicleType* vehicleTypeMatchTable = GetVehicleTypeMatchTable();
	if (vehicleTypeMatchTable != NULL) {
		sNameToEVehicleType currentVehicleTypeMatch = vehicleTypeMatchTable[*_22VEHICLE_SELECTION_HACK$currentVehicle];

		*_22VEHICLE_SELECTION_HACK$currentVehicleType = currentVehicleTypeMatch.type;
	}
}

char* VEHICLE_SELECTION_HACK::GetCurrentVehicleName()
{
	sNameToEVehicleType* vehicleTypeMatchTable = GetVehicleTypeMatchTable();

	if (vehicleTypeMatchTable == NULL) {
		return "error";
	}
	if (*_22VEHICLE_SELECTION_HACK$currentVehicle == -1) {
		return "Default";
	}

	return vehicleTypeMatchTable[*_22VEHICLE_SELECTION_HACK$currentVehicle].str;
}

int VEHICLE_SELECTION_HACK::GetNumVehicles()
{
	return *(int*)0x6ec5b0;
}