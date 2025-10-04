#include "Viewport.h"

CPCViewport* GetSimulationViewport()
{
	return *(CPCViewport**)0x71C390;
}

CPCViewport* GetGenericViewport()
{
	return *(CPCViewport**)0x70C718;
}

void CPCViewport::SetFOV(float FOV)
{
	*(float*)((int)this + 0x50C) = FOV;
}

void CPCViewport::SetWidth(float width)
{
	*(float*)((int)this + 0x504) = width;
}

void CPCViewport::SetHeight(float height)
{
	*(float*)((int)this + 0x508) = height;
}

void CPCViewport::SetFOVHooked(float FOV)
{
	if (!AdjustableFOV)
	{
		ViewportFOV = FINAL_TO_FOV(FOV);
		SetFOV(FOV);
	}
	else
	{
		SetFOV(FOV_TO_FINAL(ViewportFOV));
	}

}
