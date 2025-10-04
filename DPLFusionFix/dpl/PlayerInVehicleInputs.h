#pragma once
#include <iostream>
#include "AutoPtr.h"
#include "Input.h"

// Input__10_25798->input_[int]
enum EVehicleInputType
{
	EVehicleInputType_Invalid = -1,
	EVehicleInputType_Thrust = 0,
	EVehicleInputType_Steer = 1,
	EVehicleInputType_Burnout = 2,
	EVehicleInputType_Handbrake = 8,
	EVehicleInputType_Nitro = 19,
	EVehicleInputType_BrakeIsPressed = 24,
	EVehicleInputType_LeanFB = 29
};

class PlayerInVehicleInputs
{
public:
	struct Input__10_25798 inputs[44];
};

