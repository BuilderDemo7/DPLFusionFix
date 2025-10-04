#pragma once
#include "..\core\Matrix.h"

static bool CameraFixed;
static Matrix CameraMatrix;

class GameCamera {
public:
	Matrix camMatrix;
	static GameCamera* GetInstance();
	void SetCameraMatrix_Hook();
};

