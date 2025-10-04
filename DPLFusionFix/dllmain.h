#pragma once
//#define _SHOW_WINDOW_ON_CREATE

#include <iostream>

static float g_fPedDensityBaseNoPingInRadius;
static float g_fPedDensitySubtractionNoPingInRadius;
static float g_fPedDensityDensityMultiplier;

HWND CreateCustomWindow(HINSTANCE hamsterModule, DWORD zero);

void WriteAt(unsigned int address, const char* buffer, size_t size);
void WriteAt(unsigned int address, int integer);
