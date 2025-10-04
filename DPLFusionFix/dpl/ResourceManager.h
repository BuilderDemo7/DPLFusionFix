#pragma once
#include "..\core\Vector.h"

class SpoolableResourceManager {
public:
	void SetEntityPriority(int Package, int ID, int unk);
	void ReleaseEntity(int Package, int ID, Vector *position, int priority);
	void RequestEntity(int Package, int ID, Vector* pos, int priority);
	bool IsEntityLoaded(int Package, int ID);
	bool IsEntityPresent(int Package, int ID);
};

SpoolableResourceManager* GetResourceManager();