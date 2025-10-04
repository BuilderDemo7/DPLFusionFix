#pragma once
#include "utils/MemoryMgr.h"

using namespace Memory::VP;

void WriteAt(unsigned int address, const char* buffer, size_t size);
void WriteAt(unsigned int address, int integer);

void WritePointerAt(unsigned int address, intptr_t ptr);