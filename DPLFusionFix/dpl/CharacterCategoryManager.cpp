#include "CharacterCategoryManager.h"

CCharacterCategoryManager* GetCCM()
{
    return *(CCharacterCategoryManager**)0x70C6E4;
}

void CCharacterCategoryManager::SetEra(ECCMEra Era)
{
    ((void(__thiscall*)(CCharacterCategoryManager*, ECCMEra))0x4F3454)(this, Era);
}

ECCMEra CCharacterCategoryManager::GetEra()
{
    return ((ECCMEra(__thiscall*)(CCharacterCategoryManager*))0x4F2E9A)(this);
}

void CCharacterCategoryManager::SetPlayerAvatar(int ID)
{
    ((void(__thiscall*)(CCharacterCategoryManager*,int))0x4F31F5)(this, ID);
}

// 004F3215 - ECharacterType GetPlayerAvatar__C25CCharacterCategoryManager(CCharacterCategoryManager *this);
// 004F32A9 - void WhatToNominate__25CCharacterCategoryManagerRbT1(CCharacterCategoryManager *this,bool *bNominateCopsRef,bool *bNominatePedsRef);
// 004F32CE - void NowUnregisteringData__25CCharacterCategoryManagerUs14ESpoolPriorityUs(CCharacterCategoryManager *this,uint16_t pendingLoadEntryID,ESpoolPriority pendingLoadPriority,uint16_t nominatedEntryID);
// 004F3375 - void CancelNominatedRelease__25CCharacterCategoryManagerUs14ESpoolPriorityUs(CCharacterCategoryManager *this,uint16_t pendingLoadEntryID,ESpoolPriority pendingLoadPriority,uint16_t nominatedEntryID);
// 004F33AE - void SetEntityPriority__25CCharacterCategoryManagerUs14ESpoolPriority(CCharacterCategoryManager *this,uint16_t entryID,ESpoolPriority priority);
// 004F33C1 - void ResetPreferredCycle__25CCharacterCategoryManager(CCharacterCategoryManager *this);