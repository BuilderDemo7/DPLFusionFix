#pragma once

#define FOV_TO_FINAL(X) ((X) * 0.017453292f )
#define FINAL_TO_FOV(X) ((X) / 0.017453292f )

static bool AdjustableFOV = false;
static float ViewportFOV = 70;

class CPCViewport {
public:
	void SetFOV(float FOV);

	void SetWidth(float width);
	void SetHeight(float height);

	void SetFOVHooked(float FOV);
};

CPCViewport* GetSimulationViewport();
CPCViewport* GetGenericViewport();