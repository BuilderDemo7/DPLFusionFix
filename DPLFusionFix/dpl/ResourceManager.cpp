#include "ResourceManager.h"

void SpoolableResourceManager::SetEntityPriority(int Package, int ID, int unk)
{
	((void(__thiscall*)(SpoolableResourceManager*, int, int, int))0x5492B8)(this, Package, ID, unk);
}

void SpoolableResourceManager::RequestEntity(int Package, int ID, Vector* pos, int priority)
{
	((void(__thiscall*)(SpoolableResourceManager*, int, int, Vector*, int))0x549284)(this, Package, ID, pos, priority);
}

void SpoolableResourceManager::ReleaseEntity(int Package, int ID, Vector *position, int priority)
{
	((void(__thiscall*)(SpoolableResourceManager*, int, int, Vector*, int))0x54929E)(this, Package, ID, position, priority);
}

bool SpoolableResourceManager::IsEntityLoaded(int Package, int ID)
{
	return ((bool(__thiscall*)(SpoolableResourceManager*, int, int))0x5481F7)(this, Package, ID);
}

bool SpoolableResourceManager::IsEntityPresent(int Package, int ID)
{
	return ((bool(__thiscall*)(SpoolableResourceManager*, int, int))0x547F5E)(this, Package, ID);
}

SpoolableResourceManager* GetResourceManager()
{
	return *(SpoolableResourceManager**)(0x70C64C);
}
