#pragma once
#include "Vector4.h"
#include "..\core\Vector.h"

enum EMarkerType
{
	MARKER_PLAYER_ARROW = 2,
	MARKER_OBJECTIVE_ARROW = 3,
	MARKER_OBJECTIVE = 4,
	MARKER_COP = 5,
	MARKER_RIVAL = 6,
	MARKER_GREEN_MARKER = 7,
	MARKER_JOB_ICON_MARKER = 8,
	MARKER_SIDE_JOB_ICON_MARKER = 9,
	MARKER_SAFE_HOUSE = 10,
	MARKER_GARAGE = 11,
};

class CMarker
{
public:
	Vector4 GetPosition();
	void SetPosition(Vector4 position);
	void SetPosition(Vector position);
	float GetRotation();
	void SetRotation(float rotation);

	int GetMarkerType();
	void SetMarkerType(int type);

	// Only seems to be applied to the marker type 7
	void SetMarkerColor(int color);
	// The A is for color types maybe?
	void SetMarkerColor(char r, char g, char b, char a = 0);

	void GetMarkerColor(char& r, char& g, char& b, char& a);
	void GetMarkerColor(int& color);

	int GetRenderingPriority();
	void SetRenderingPriority(int priority);

	int GetIconType();
	void SetIconType(int type);

	int GetStringPointer();
	void SetStringPointer(int ptr);

	bool IsEnabled();
	void SetIsEnabled(bool enabled);
};

