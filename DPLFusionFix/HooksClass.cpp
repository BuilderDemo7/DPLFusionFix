#include "HooksClass.h"

bool D3DDevice_WireFrame_On = false;

void __declspec(naked) HooksClass::Before_OnEnterGarageState()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	static CLifeSystem* lfs = *(CLifeSystem**)0x70C7C4; //GetLifeSystem()
	
	// Low the ping in and ping out radius to prevent infinite loading
	lfs->m_fPingInRadius = 100;
	lfs->m_fPingOutRadius = 115;
	*(float*)(0x6414f8) = lfs->m_fPingInRadius;
	*(float*)(0x641420) = lfs->m_fPingOutRadius;

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	static int callAddr_0x4bcf65 = 0x4bcf65;
	_asm
	{
		mov ecx, [previousECX]
		call callAddr_0x4bcf65
	}

	// Jump back
	static int jumpback_0x465726 = 0x465726;
	_asm
	{
		jmp jumpback_0x465726
	}
}

void __declspec(naked) HooksClass::After_OnEnterGarageState()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	static CLifeSystem* lfs = *(CLifeSystem**)0x70C7C4; //GetLifeSystem()

	// Restore ping in and ping out radius
	lfs->m_fPingInRadius = SettingsMgr->fInstances_Spawn_Radius - 10;
	lfs->m_fPingOutRadius = SettingsMgr->fInstances_Spawn_Radius;
	*(float*)(0x6414f8) = lfs->m_fPingInRadius;
	*(float*)(0x641420) = lfs->m_fPingOutRadius;

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	_asm
	{
		mov ebx, [previousEBX]
		mov byte ptr [ebx + 0x2a8],0x1
	}

	// Jump back
	static int jumpback_0x465e37 = 0x465e37;
	_asm
	{
		jmp jumpback_0x465e37
	}
}

void __declspec(naked) HooksClass::OnCase_EMapItem_Player_CustomBlock()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	//static Vector4* plrIcon_color = (Vector4*)previousESP + 0x10;
	//plrIcon_color->X = 1.0f;
	//plrIcon_color->Y = 1.0f;
	//plrIcon_color->Z = 1.0f;
	//plrIcon_color->W = 1.0f;
	//*(int*)(previousESP + 0x94) = 0x350001; // instance.hModel = 0x350001;

	_asm
	{
		mov esp,[previousESP]

		movss dword ptr [esp+0xB0],xmm0 // R = 1
		movss dword ptr [esp+0xB4],xmm0 // G = 1
		movss dword ptr [esp+0xB8],xmm0 // B = 1
		movss dword ptr [esp+0xBC],xmm0 // A = 1

		mov dword ptr[esp + 0x94], 0x350001
	}

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	// No need! we already replaced the whole function in this case
	//_asm
	//{
	//}

	// Jump back
	static int jumpback_0x4be191 = 0x4be191;
	_asm
	{
		jmp jumpback_0x4be191
	}
}

void __declspec(naked) HooksClass::DrawMapItem_ModelCheck()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	// Fix for not having other arrow icons to have the same model
	if (*(int*)(previousEBX + 0x14) == 6)
	{
		_asm
		{
			mov dword ptr[esp + 0x94], 0x350005 // alerted cop icon
		}
	}
	else
	{
		_asm
		{
			mov dword ptr[esp + 0x94], 0x350001 // generic arrow icon
		}
	}

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	// No need... our function does it's job already
	//_asm
	//{
	//}

	// Jump back
	static int jumpback_0x4bdf9d = 0x4bdf9d;
	_asm
	{
		jmp jumpback_0x4bdf9d
	}
}

void __declspec(naked) HooksClass::ProcessCommandExtension_Frontend()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	_asm
	{
		mov esi,[previousESI]
		mov ebx,[previousEBX]
		
		push esi
		push ebx
		mov ecx,[previousEDI]

		call CState_Frontend::ProcessCommand_Development
	}
	//static CState_Frontend* extFrontendState = *(CState_Frontend**)previousECX;

	//extFrontendState->ProcessCommand_Development(*(char**)previousEBX, *(char**)previousESI);

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	static int CallAddr_0x4c411e = 0x4c411e;
	_asm
	{
		push esi
		push ebx
		mov ecx, [previousECX]
		call CallAddr_0x4c411e
	}

	// Jump back
	static int jumpback_0x4c4cc2 = 0x4c4cc2;
	_asm
	{
		jmp jumpback_0x4c4cc2
	}
}

void __declspec(naked) HooksClass::GameSimulationStep()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	OnGameStep();

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	_asm
	{
		xorps xmm0,xmm0
		movss dword ptr [eax],xmm0
	}

	// Jump back
	static int jumpback_0x45accb = 0x45accb;
	_asm
	{
		jmp jumpback_0x45accb
	}
}

void __declspec(naked) HooksClass::GameOverlays_DrawHooked_Debug()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	_asm
	{
		mov al, byte ptr [bDebug_Display_HUD_and_Map]
		test al,al
		jnz CONTINUE_IF_SHOW_OVERLAYS
		_asm
		{
			ret // return
		}
	}

	CONTINUE_IF_SHOW_OVERLAYS:
	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	_asm
	{
		push ebp
		mov ebp, esp
		push ecx
		push ecx
	}

	// Jump back
	static int jumpback_0x4b7f3b = 0x4b7f3b;
	_asm
	{
		jmp jumpback_0x4b7f3b
	}
}

void __declspec(naked) HooksClass::OverheadMap_DrawHooked_Debug()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	_asm
	{
		mov al, byte ptr[bDebug_Display_HUD_and_Map]
		test al, al
		jnz CONTINUE_IF_SHOW_OVERHEADMAP
		_asm
		{
			ret // return
		}
	}

CONTINUE_IF_SHOW_OVERHEADMAP:
	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	_asm
	{
		push ebp
		mov ebp, esp
		and esp, 0xfffffff0
	}

	// Jump back
	static int jumpback_0x4b9ef7 = 0x4b9ef7;
	_asm
	{
		jmp jumpback_0x4b9ef7
	}
}

void __declspec(naked) HooksClass::HeapFree_Fix_Validation()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	static void* lpcMemory = *(void**)previousESI; // CRASH WITH HEAP HANDLE ALRIGHT = this var could be the problem
	static HANDLE hHeap = (HANDLE) (*(int*)0x985ad8); // If the pointer is invalid then the HeapValidate with generate a exception but doesn't crash the game
	if (HeapValidate(hHeap, 0, lpcMemory))
	{
		HeapFree(hHeap, 0, lpcMemory);
	}

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	//_asm
	//{
	//}

	// Jump back
	static int jumpback_0x5fc800 = 0x5fc800;
	_asm
	{
		jmp jumpback_0x5fc800
	}
}

void __declspec(naked) HooksClass::PS2_Glow_SFX_Settings_Patch()
{
	// Backup registers
	/*
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}
	*/

	// Code here
	*(int*)(0x976398) = 300; // "Glow pp multiply"
	*(int*)(0x9765A4) = 3;   // "Glow filter pass count"

	/*
	static int DAT_00976398 = 0x976398;
	static int DAT_009765A4 = 0x9765A4;
	_asm
	{
		mov dword ptr [DAT_00976398],0x12C
		mov dword ptr [DAT_009765A4],3
	}
	*/

	// Restore registers
	/*
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}
	*/

	// Original instruction
	//_asm
	//{
	//}

	// Jump back
	static int jumpback_0x5ecc41 = 0x5ecc41;
	_asm
	{
		jmp jumpback_0x5ecc41
	}
}

HRESULT __fastcall HooksClass::D3DDevice_EndScene_Patches(int Viewport)
{
	IDirect3DDevice9* pDevice = *(IDirect3DDevice9**)(Viewport + 0x164);

	if (D3DDevice_WireFrame_On)
	{
		pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	}
	else
	{
		pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	}

	// Alpha blending patch
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	return pDevice->EndScene();
}

void __declspec(naked) HooksClass::Custom_Load_Dev_Menu()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	LoadDevMenu();
	
	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	static int ptr_0x70c658 = *(int*)0x70c658;
	_asm
	{
		mov ecx, dword ptr [ptr_0x70c658]
		//mov ecx, dword ptr [0x70c658]
	}

	// Jump back
	static int jumpback_0x4aa07b = 0x4aa07b;
	_asm
	{
		jmp jumpback_0x4aa07b
	}
}

void __declspec(naked) HooksClass::Classic_BurnOut_Hook()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here
	if (SettingsMgr->bClassic_BurnOut)
	{
		// SVehicleManipulationPacket* packet = ebp-0x20 (in-stack);
		static SVehicleManipulationPacket* CLABUR_packet = nullptr;
		_asm
		{
			mov ecx,ebp
			sub ecx,0x20 // ebp-20
			mov dword ptr [CLABUR_packet],ecx
		}
		if (CLABUR_packet->fBurnout >= 0.1f)
		{
			if (CLABUR_packet->fThrust >= 0)
			{
				CLABUR_packet->fThrust = CLABUR_packet->fBurnout; // accelerate with burnout, but when braking this won't work of course
			}
		}
	}

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	_asm
	{
		mov ecx, dword ptr[esi+0x4]
		mov eax,[ecx]
	}

	// Jump back
	static int jumpback_0x5AF871 = 0x5AF871;
	_asm
	{
		jmp jumpback_0x5AF871
	}
}

void __declspec(naked) HooksClass::Turn_Signal_Feature()
{
	// Backup registers
	static unsigned int previousEAX = 0;
	static unsigned int previousEBX = 0;
	static unsigned int previousECX = 0;
	static unsigned int previousEDX = 0;
	static unsigned int previousEDI = 0;
	static unsigned int previousEBP = 0;
	static unsigned int previousESI = 0;
	static unsigned int previousESP = 0;

	_asm
	{
		mov[previousEAX], eax
		mov[previousEBX], ebx
		mov[previousECX], ecx
		mov[previousEDX], edx
		mov[previousEDI], edi
		mov[previousEBP], ebp
		mov[previousESP], esp
		mov[previousESI], esi
	}

	// Code here

	// esi = this
	// those are from 0 fields or unused fields
	
	// better not use fields you don't know because they will crash the game
	//static int* whichOnesAreOn = (int*)(previousESI + 0x20C);
	//static float* turnSignalSwitchTime = (float*)(previousESI + 0x210);
	//static bool* turnSignalLightOn = (bool*)(previousESI + 0x214);
	static int whichOnesAreOn = 0;
	static float turnSignalSwitchTime = 0;
	static bool turnSignalLightOn = 0;

	static float input_signalLeft;
	static float input_signalRight;
	static float input_prev_signalLeft;
	static float input_prev_signalRight;
	static CCharacter* driverbeh_character = NULL;
	static CVehicle* driverbeh_vehicle = NULL;
	static float stepTime = 0.008333f;

	if (SettingsMgr->bPlayer_Can_Use_Turn_Signal)
	{
		// FrontendInputManager->MenuLeft & MenuRight
		input_prev_signalLeft = input_signalLeft;
		input_prev_signalRight = input_signalRight;
		input_signalLeft = *(float*)((*(int*)0x70c6f4) + 0x34);
		input_signalRight = *(float*)((*(int*)0x70c6f4) + 0x40);

		// check for each input if they're pressed once
		if (input_signalLeft != 0 && input_prev_signalLeft != input_signalLeft)
		{
			if (whichOnesAreOn == 1)
				whichOnesAreOn = 0;
			else
				whichOnesAreOn = 1;
		}
		if (input_signalRight != 0 && input_prev_signalRight != input_signalRight)
		{
			if (whichOnesAreOn == 2)
				whichOnesAreOn = 0;
			else
				whichOnesAreOn = 2;
		}

		// DEBUG DEBUG DEBUG!!!!!!!!!
		//*whichOnesAreOn = 1;

		driverbeh_character = *(CCharacter**)(previousESI + 0x2C4);
		driverbeh_vehicle = driverbeh_character->GetVehicle();

		turnSignalSwitchTime += stepTime;
		if (turnSignalSwitchTime > 0.3f)
		{
			turnSignalSwitchTime = 0;
			turnSignalLightOn = !turnSignalLightOn;
		}

		if (driverbeh_vehicle != NULL)
		{
			driverbeh_vehicle->ActivateLamp(PST_FLINDICATOR, false, false); // front-left
			driverbeh_vehicle->ActivateLamp(PST_FRINDICATOR, false, false); // front-right
			driverbeh_vehicle->ActivateLamp(PST_BLINDICATOR, false, false); // back-left
			driverbeh_vehicle->ActivateLamp(PST_BRINDICATOR, false, false); // back-right

			if (whichOnesAreOn > 0)
			{
				if (whichOnesAreOn == 1)
				{
					// left
					driverbeh_vehicle->ActivateLamp(PST_FLINDICATOR, turnSignalLightOn, true); // front-left
					driverbeh_vehicle->ActivateLamp(PST_BLINDICATOR, turnSignalLightOn, true); // back-left
				}
				else if (whichOnesAreOn == 2)
				{
					// right
					driverbeh_vehicle->ActivateLamp(PST_FRINDICATOR, turnSignalLightOn, true); // front-right
					driverbeh_vehicle->ActivateLamp(PST_BRINDICATOR, turnSignalLightOn, true); // back-right
				}
			}
		}
	}

	// Restore registers
	__asm
	{
		mov eax, [previousEAX]
		mov ebx, [previousEBX]
		mov ecx, [previousECX]
		mov edx, [previousEDX]
		mov edi, [previousEDI]
		mov esp, [previousESP]
		mov ebp, [previousEBP]

		mov esi, [previousESI]
	}

	// Original instruction
	static int ptr_0x70c7e0 = *(int*)0x70c7e0;
	_asm
	{
		mov ecx, dword ptr[ptr_0x70c7e0]
		//mov ecx, dword ptr [0x70c658]
	}

	// Jump back
	static int jumpback_0x49f98c = 0x49f98c;
	_asm
	{
		jmp jumpback_0x49f98c
	}
}