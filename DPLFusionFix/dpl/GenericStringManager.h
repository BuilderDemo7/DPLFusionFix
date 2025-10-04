#pragma once
#include "EGenericTextID.h"

class CGenericStringManager
{
public:
	wchar_t* GetString(EGenericTextID eID, int index);
};

CGenericStringManager* GetGenericStringManager();