#pragma once
enum eNodeFireWire
{
	eWire_OldMethod_Used = -2,
	eWire_None = -1,
	eWire_Success = 0,
	eWire_Fail = 1
};

struct WireCollectionHeader
{
	unsigned int count;
};

struct WireCollection
{
	char* m_ownerName;
	void* m_owningNode;
	WireCollectionHeader* m_pWireList;
	void* m_pNodeFactory; // CLifeNodeFactory *
};