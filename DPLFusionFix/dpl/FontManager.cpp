#include "FontManager.h"

// Since I don't know how to use this class properly yet (06/Oct/2025 03:55 AM)
// I will leave this psedo code here, you may read it but DO NOT USE
/*
  if (g_bSkippingCutscene) {
	FontSpecs_ctor((FontSpecs *)&local_48.colour.Z); // 0x46f7b6
	fontmanager = Singleton_FontManager;
	local_48.w = 0.0;
	local_48.xScale = 0.5;
	local_48.x = 0.0;
	local_48.y = 0.0;
	local_48.yScale = 1.0;
	local_48.spacing = 1.0;
	local_48.justify = (EJustify)1.0;
	GetString__C21CGenericStringManager14EGenericTextIDi
			  (Singleton_GenericStringManager,EGenericTextID_MU,3);
	unk1 = fontmanager->vtable;
	(*unk1->Print__ANSI)
			  ((int)unk1,(CViewport **)fontmanager,&local_48,(char *)piViewport,
			   (int)&local_48.colour.Z);

	------ a bit more normal code below?
	dimensions.X = 1.0;
	dimensions.Y = 1.0;
	dimensions.Z = 1.0;
	dimensions.W = 1.0;
	specs.colour.X = 1.0;
	specs.colour.Y = 1.0;
	specs.colour.Z = 1.0;
	*psVar1 = 0;
	specs.colour.W = 1.0;
	(*Singleton_FontManager->vtable->Print__ANSI)
			  (Singleton_FontManager,&dimensions,piViewport,&specs,ntext,0); // _vt$12CFontManager+0x30
  }
*/

void CFontManager::DebugPrint(CPCViewport *piView, FontSpecs *spec, char *szString)
{
#ifdef _ORIGINAL_DEBUGPRINT_CALL
	((void(__thiscall*)(CFontManager*, CPCViewport*, FontSpecs*, char*))*(int*)(GetVTableAddress() + 0x50))(this, piView, spec, szString);
#else
	((void(__stdcall*)(CFontManager*, CPCViewport*, char*, FontSpecs*))*(int*)(GetVTableAddress() + 0x50))(this, piView, szString, spec);
#endif
}

void CFontManager::Print(Vector4* dimensions, AutoPtr<CPCViewport, int> piView, FontSpecs *spec, unsigned int textID, int unk1)
{
#ifdef FM_USE_VTABLE
	((void(__thiscall*)(CFontManager*, Vector4*, AutoPtr<CPCViewport, int>, FontSpecs*, unsigned int, int))*(int*)(GetVTableAddress() + 0x34))(this, dimensions, piView, spec, textID, unk1);
#else
	((void(__thiscall*)(CFontManager*, Vector4*, AutoPtr<CPCViewport, int>, FontSpecs*, unsigned int, int))0x56DD77)(this, dimensions, piView, spec, textID, unk1);
#endif
}

void CFontManager::Print(CPCViewport* piView, FontSpecs *spec, char* szFormat, Vector4 offset)
{
	// MAv2
	Vector __return_storage_ptr__;
//#ifdef FM_USE_VTABLE
	((void(__stdcall*)(CFontManager*, Vector*, CPCViewport*, FontSpecs*, char*, Vector4))*(int*)(GetVTableAddress() + 0x30))(this, &__return_storage_ptr__, piView, spec, szFormat, offset);
//#else
	//((void(__thiscall*)(CFontManager*, Vector4*, AutoPtr<CPCViewport, int>, FontSpecs*, wchar_t*, int))0x56DEA3)(this, dimensions, piView, spec, szFormat, unk1);
//#endif
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