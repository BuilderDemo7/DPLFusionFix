#include "LifeNode_DebugText.h"

#include <sstream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <iostream>

void CLifeNode_DebugText::OnInitialise(CLifePropertyStream* propertiesStream, CLifeEventData* pOwningLifeEvent)
{
//#ifdef _DEBUG
//	printf("CLifeNode_DebugText -> OnInitialise(<%p>, <%p>)\n", propertiesStream, pOwningLifeEvent);
//#endif

	propertiesStream->GetString("Text", &szMessage);
	propertiesStream->GetWireCollection("pWireCollection", &wireCollection);

//#ifdef _DEBUG
//	printf("CLifeNode_DebugText->szMessage = %s\n", szMessage);
//	printf("CLifeNode_DebugText->wireCollection = <%p>\n", &wireCollection);
//#endif
}

void CLifeNode_DebugText::OnEnable(bool *enabled, eNodeFireWire *wireToFire)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(0 << 4) | 11); // light blue

	std::cout << "[MISSION] ";

	// Get current time
	std::time_t t = std::time(nullptr);
	std::tm lt{};
	localtime_s(&lt, &t);

	// gray timestamp
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << "[" << std::put_time(&lt, "%H:%M:%S") << "]: ";

	SetConsoleTextAttribute(hConsole,
		(0 << 4) | 7); // gray (default color)

	std::cout << this->szMessage << std::endl;

	// authorize for the next life node to be fired as 'success'
	*wireToFire = eWire_Success;
	
	// single-shot life node (enabled only once)
	//*enabled = false;
}