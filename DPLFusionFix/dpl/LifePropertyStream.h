#pragma once
#include "WireCollection.h"

class CLifePropertyStream
{
public:
	bool GetWireCollection(char *pszName, WireCollection *property);
	bool GetString(char *pszName, char **property);
};