#include "Camera.h"

GameCamera* GameCamera::GetInstance()
{
    return ((GameCamera*(__cdecl*)())0x55A60A)();
}

void GameCamera::SetCameraMatrix_Hook()
{
	if (!CameraFixed) 
	{
		CameraMatrix.pos = camMatrix.pos;

		CameraMatrix.forward = camMatrix.forward;
		CameraMatrix.up = camMatrix.up;
		CameraMatrix.right = camMatrix.right;
	}
    else
    {
        camMatrix.pos = CameraMatrix.pos;

		camMatrix.forward = CameraMatrix.forward;
		camMatrix.up = CameraMatrix.up;
		camMatrix.right = CameraMatrix.right;
    }

    ((void(__thiscall*)(GameCamera*))0x55A646)(this);

}
