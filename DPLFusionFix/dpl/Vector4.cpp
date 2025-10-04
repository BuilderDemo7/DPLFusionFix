#include "Vector4.h"
#include <iostream>
#include <cmath>

Vector4::Vector4()
{
	X = Y = Z = W = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	X = x;
	Y = y;
	Z = z;
	W = w;
}

Vector4* Vector4::operator*(float multiplier)
{
	X = X * multiplier;
	Y = Y * multiplier;
	Z = Z * multiplier;
	W = W * multiplier;
	return this;
}

void Vector4::operator*=(float multiplier)
{
	X = X * multiplier;
	Y = Y * multiplier;
	Z = Z * multiplier;
	W = W * multiplier;
}

Vector4* Vector4::operator*(Vector4 other)
{
	X = X * other.X;
	Y = Y * other.Y;
	Z = Z * other.Z;
	W = W * other.W;
	return this;
}

Vector4* Vector4::operator+(Vector4 other)
{
	X = X + other.X;
	Y = Y + other.Y;
	Z = Z + other.Z;
	W = W + other.W;
	return this;
}

void Vector4::operator+=(Vector4 other)
{
	X = X + other.X;
	Y = Y + other.Y;
	Z = Z + other.Z;
	W = W + other.W;
}

float Vector4::GetMagnitude()
{
	return sqrt((X*X) + (Y*Y) + (Z*Z));
}

void Vector4::Normalise()
{
	if (X > 1)
		X = 1;
	if (X < -1)
		X = -1;

	if (Y > 1)
		Y = 1;
	if (Y < -1)
		Y = -1;

	if (Z > 1)
		Z = 1;
	if (Z < -1)
		Z = -1;
}

float GetDistanceBetweenPoints3D(Vector4 v1, Vector4 v2)
{
	float x1 = v1.X;
	float y1 = v1.Y;
	float z1 = v1.Z;
	float x2 = v2.X;
	float y2 = v2.Y;
	float z2 = v2.Z;
	float dist = pow((x2 - x1) * pow(x2 - x1, 2) + (y2 - y1) * pow(y2 - y1, 2) + (z2 - z1) * (z2 - z1), 0.5f);
	if (dist < 0)
		dist = 0;
	return dist;
}
