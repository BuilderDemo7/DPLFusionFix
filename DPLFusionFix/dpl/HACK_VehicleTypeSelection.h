#pragma once
#include <iostream>

struct sNameToEVehicleType
{
	char str[128];
	int type;
};

extern int* _22VEHICLE_SELECTION_HACK$currentVehicle;
extern int* _22VEHICLE_SELECTION_HACK$currentVehicleType;

static class VEHICLE_SELECTION_HACK
{
public:
	static sNameToEVehicleType* GetVehicleTypeMatchTable();

	static void PrevVehicle();
	static void NextVehicle();

	static int GetNumVehicles();
	static char* GetCurrentVehicleName();
};