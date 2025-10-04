#pragma once
#include "Input.h"
#include "EInputAction.h"

class CVisualsInputManager
{
public:
	// _vt$20CInputManager
	virtual ~CVisualsInputManager() = default;

	// Input_impl* input = nullptr;
	// input = get_input(input, EInputAction_Pause);
	virtual Input_impl* get_input(Input_impl *__return_storage_ptr__, EInputAction eAction) = 0;

	float Get_Camera_LookLeft_HACK();
	float Get_Camera_LookRight_HACK();
	float Get_Camera_LookBack_HACK();
	float Get_Camera_LookForward_HACK();
};

CVisualsInputManager* GetVisualsInputManager();