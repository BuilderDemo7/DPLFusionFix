#include "Marker.h"

bool CMarker::IsEnabled()
{
	return (int*)(this + 0x34) == 0 ? false : true;
}

void CMarker::SetIsEnabled(bool enabled)
{
	*(int*)(this + 0x34) = (enabled ? 1 : 0);
}

Vector4 CMarker::GetPosition()
{
	Vector4* ptrVec = (Vector4*)(this + 0x38);
	return Vector4(ptrVec->X, ptrVec->Y, ptrVec->Z, ptrVec->W);
}

void CMarker::SetPosition(Vector4 position)
{
	*(Vector4*)(this + 0x38) = position;
}

void CMarker::SetPosition(Vector position)
{
	*(Vector4*)(this + 0x38) = *(new Vector4(position.X, position.Y, position.Z, 1));
}

// Returns the rotation of the marker in radians
float CMarker::GetRotation()
{
	float rot = *(float*)(this + 0x48);
	return rot;
}

void CMarker::SetRotation(float rotation)
{
	*(float*)(this + 0x48) = rotation;
}

int CMarker::GetMarkerType()
{
	return *(int*)(this + 0x4C);
}

void CMarker::SetMarkerType(int type)
{
	*(int*)(this + 0x4C) = type;
}

void CMarker::SetMarkerColor(int color)
{
	*(int*)(this + 0x58) = color;
}

void CMarker::GetMarkerColor(int& color)
{
	color = *(int*)(this + 0x58);
}

// The A is for color types maybe?
void CMarker::SetMarkerColor(char r, char g, char b, char a)
{
	*(char*)(this + 0x58) = r;
	*(char*)(this + 0x59) = g;
	*(char*)(this + 0x5A) = b;
	*(char*)(this + 0x5B) = a;
}

void CMarker::GetMarkerColor(char& r, char& g, char& b, char& a)
{
	r = *(char*)(this + 0x58);
	g = *(char*)(this + 0x59);
	b = *(char*)(this + 0x5A);
    a = *(char*)(this + 0x5B);
}

int CMarker::GetRenderingPriority()
{
	return *(int*)(this + 0x5C);
}

void CMarker::SetRenderingPriority(int priority)
{
	*(int*)(this + 0x5C) = priority;
}

int CMarker::GetIconType()
{
	return *(int*)(this + 0x54);
}

void CMarker::SetIconType(int type)
{
	*(int*)(this + 0x54) = type;
}

int CMarker::GetStringPointer()
{
	return *(int*)(this + 0x50);
}

void CMarker::SetStringPointer(int ptr)
{
	*(int*)(this + 0x50) = ptr;
}