#include "FontManager.h"

void CFontManager::Print(Vector4* dimensions, AutoPtr<CPCViewport, int> piView, FontSpecs *spec, unsigned int textID, int unk1)
{
#ifdef FM_USE_VTABLE
	((void(__thiscall*)(CFontManager*, Vector4*, AutoPtr<CPCViewport, int>, FontSpecs*, unsigned int, int))*(int*)(GetVTableAddress() + 0x34))(this, dimensions, piView, spec, textID, unk1);
#else
	((void(__thiscall*)(CFontManager*, Vector4*, AutoPtr<CPCViewport, int>, FontSpecs*, unsigned int, int))0x56DD77)(this, dimensions, piView, spec, textID, unk1);
#endif
}

void CFontManager::Print(Vector4* dimensions, AutoPtr<CPCViewport, int> piView, FontSpecs *spec, wchar_t* szFormat, int unk1)
{
#ifdef FM_USE_VTABLE
	((void(__thiscall*)(CFontManager*, Vector4*, AutoPtr<CPCViewport, int>, FontSpecs*, wchar_t*, int))*(int*)(GetVTableAddress() + 0x30))(this, dimensions, piView, spec, szFormat, unk1);
#else
	((void(__thiscall*)(CFontManager*, Vector4*, AutoPtr<CPCViewport, int>, FontSpecs*, wchar_t*, int))0x56DEA3)(this, dimensions, piView, spec, szFormat, unk1);
#endif
}

void CFontManager::PrintFast(Vector4* dimensions, CPCViewport* piView, FontSpecs *spec, unsigned int textID, int unk1)
{
	AutoPtr<CPCViewport, int> ptr;
	ptr.m_pPointer = piView;
	Print(dimensions, ptr, spec, textID, unk1);
}

void CFontManager::PrintFast(Vector4* dimensions, CPCViewport* piView, FontSpecs *spec, wchar_t* szFormat, int unk1)
{
	AutoPtr<CPCViewport, int> ptr;
	ptr.m_pPointer = piView;
	Print(dimensions, ptr, spec, szFormat, unk1);
}

void CFontManager::Print(Vector4* dimensions, AutoPtr<CPCViewport, int> piView, FontSpecs *spec, const wchar_t* szFormat, int unk1)
{
	Print(dimensions, piView, spec, (wchar_t*)szFormat, unk1);
}

void CFontManager::Print(Vector4* dimensions, CPCViewport* piView, FontSpecs *spec, const wchar_t* szFormat, int unk1)
{
	AutoPtr<CPCViewport, int> ptr;
	ptr.m_pPointer = piView;
	Print(dimensions, ptr, spec, (wchar_t*)szFormat, unk1);
}

int CFontManager::GetVTableAddress()
{
	return *(int*)(this);
}

CFontManager* GetFontManager()
{
	return (CFontManager*)(*(int*)(0x70C540));
}