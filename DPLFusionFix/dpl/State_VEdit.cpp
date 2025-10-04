#include "State_VEdit.h"
#include <math.h>

# define M_PI           3.14159265358979323846

void CState_VEdit::Step_Hook()
{
	// call the original function first
	((void(__thiscall*)(CState_VEdit*))0x464E4F)(this);

	Step_GarageCamera();
}

void CState_VEdit::Step_GarageCamera()
{
	// if display vehicle is spawned (not null)
	if (*(int*)((int)this + 0x70) != NULL) 
	{
		// HACK - fields as pointers, use asterisk (*) in the start of the expression for the pointer to set it's value
		float* m_DisplayHeading = (float*)(this + 0x84); // this->m_DisplayHeading
		float* m_DisplayRotate = (float*)(this + 0x88); // this->m_DisplayRotate
		float* m_DisplayElevate = (float*)(this + 0x8c); // this->m_DisplayElevate = M_PI // default value

		float* m_GarageCam_m_EO = (float*)((int)this + (0x90 + 0x90)); // this->m_GarageCam.m_EO
		float* m_GarageCam_m_HO = (float*)((int)this + (0x90 + 0x94)); // this->m_GarageCam.m_HO

		void* m_GarageCam = (void*)((int)this + 0x90);

		CVisualsInputManager* vinput = GetVisualsInputManager();

		// stored in stack??
		// Input_impl CarLookLeft;
		// Input_impl CarLookRight;
		// /*CarLookLeft =*/ vinput->get_input(&CarLookLeft, EInputAction_Camera_LookLeft);
		// /*CarLookRight =*/ vinput->get_input(&CarLookRight, EInputAction_Camera_LookRight);

		//if (CarLookLeft != nullptr && CarLookRight != nullptr)
		{
			//float inputleft = CarLookLeft.value_;
			//float inputright = CarLookRight.value_;
			float inputleft = vinput->Get_Camera_LookLeft_HACK();
			float inputright = vinput->Get_Camera_LookRight_HACK();
			float inputback = vinput->Get_Camera_LookBack_HACK();
			float inputforward = vinput->Get_Camera_LookForward_HACK();

			static float camerainput_deadzone = 0.125f;

			if (SettingsMgr->bInvert_Garage_Camera)
			{
				float oldinputleft = inputleft;
				float oldinputright = inputright;
				float oldinputback = inputback;
				float oldinputforward = inputforward;
				inputleft = oldinputright;
				inputright = oldinputleft;
				inputback = oldinputforward;
				inputforward = oldinputback;
			}

			// if input down or input up is not pressed within the dead-zone
			if (inputback < camerainput_deadzone && inputforward < camerainput_deadzone)
			{
				static float cord_elevationStep = 0.1f * 0.014959967;

				if (*m_DisplayElevate < -cord_elevationStep)
					*m_DisplayElevate += cord_elevationStep;  // push camera up
				else if (*m_DisplayElevate > cord_elevationStep)
					*m_DisplayElevate -= cord_elevationStep;   // pull camera down
			}

			if (inputleft > camerainput_deadzone) {
				*m_DisplayRotate = *m_DisplayRotate + (inputleft * 0.014959967);
			}
			else if (inputright > camerainput_deadzone) {
				*m_DisplayRotate = *m_DisplayRotate - (inputright * 0.014959967);
			}

			if (inputback > camerainput_deadzone) {
				*m_DisplayElevate = *m_DisplayElevate - (inputback * 0.014959967);
			}
			else if (inputforward > camerainput_deadzone) {
				*m_DisplayElevate = *m_DisplayElevate + (inputforward * 0.014959967);
			}

			// if rotation is greater than 360 degrees then reset the angle (no effect)
			if (*m_DisplayRotate > (M_PI * 2))
			{
				*m_DisplayRotate = 0;
			}
			// if rotation is less than 0 then set the angle to 360 degrees (no effect)
			if (*m_DisplayRotate < 0)
			{
				*m_DisplayRotate = M_PI * 2;
			}

			// clamp elevation (approx -5.6 degrees to +22.5 degrees in radians)
			if (*m_DisplayElevate < -0.09817477f)
				*m_DisplayElevate = -0.09817477f;
			else if (*m_DisplayElevate > 0.3926991f)
				*m_DisplayElevate = 0.3926991f;

			// what the !@$& is that psedo code?
			/*
			fVar10 = this->m_DisplayRotate;
			if (fVar11 < -0.125) {
				this->m_DisplayRotate = fVar10 - (ABS(fVar11) - 0.125) * 0.014959967;
				fVar10 = this->m_DisplayRotate;
			}
			if (6.2831855 < fVar10) {
				do {
					fVar10 = fVar10 - 6.2831855;
				} while (6.2831855 < fVar10);
				this->m_DisplayRotate = fVar10;
			}
			fVar10 = this->m_DisplayRotate;
			if (fVar10 < -6.2831855) {
				do {
					fVar10 = fVar10 + 6.2831855;
				} while (fVar10 < -6.2831855);
				this->m_DisplayRotate = fVar10;
			}
			fVar11 = GetStickF__C8CGamepad10GAMEPAD_ID13GAMEPAD_STICK
			((CGamepad *)_7hamster$g_aSingletons[0x20], GAMEPAD1, STICK_RIGHT_VERT);
			if (ABS(fVar11) < 0.125) {
				if (this->m_DisplayElevate < 0.0) {
					fVar11 = 0.25;
				}
				if (0.0 < this->m_DisplayElevate) {
					fVar11 = -0.25;
				}
			}
			if (0.125 < fVar11) {
				this->m_DisplayElevate = this->m_DisplayElevate + (fVar11 - 0.125) * 0.014959967;
			}
			if (fVar11 < -0.125) {
				this->m_DisplayElevate = this->m_DisplayElevate - (ABS(fVar11) - 0.125) * 0.014959967;
				fVar10 = this->m_DisplayElevate;
			}
			else {
				fVar10 = this->m_DisplayElevate;
			}
			fVar10 = (float)((int)fVar10 * (uint)(-0.09817477 < fVar10) |
				(uint)(-0.09817477 >= fVar10) * -0x4236f025);
			MVar12 = (MAreal)((int)fVar10 * (uint)(fVar10 < 0.3926991) |
				(uint)(fVar10 >= 0.3926991) * 0.3926991);
			(this->m_GarageCam).m_EO = MVar12;
			this->m_DisplayElevate = MVar12;
			RecalculateMatrix__13cGarageCamera(&this->m_GarageCam);
			(this->m_GarageCam).m_HO = this->m_DisplayRotate;
			RecalculateMatrix__13cGarageCamera(&this->m_GarageCam);
			*/

			*m_GarageCam_m_HO = *m_DisplayRotate;
			*m_GarageCam_m_EO = *m_DisplayElevate;

			// update the camera
			// void __thiscall RecalculateMatrix__13cGarageCamera(cGarageCamera *this)
			((void(__thiscall*)(void*))0x460645)(m_GarageCam);
		}
	}
}