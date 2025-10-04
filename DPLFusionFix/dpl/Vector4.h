#pragma once

#include "..\core\Vector.h"

class Vector4 {
public:
	float X, Y, Z, W;

	Vector4();
	Vector4(float x, float y, float z, float w = 1.0f);

	void Normalise();

	Vector4* operator*(float multiplier);
	Vector4* operator*(Vector4 other);
	Vector4* operator+(Vector4 other);
	void operator*=(float multiplier);
	void operator+=(Vector4 other);
	float GetMagnitude();
	Vector4* Lerp(const Vector4* target, float t) const {
		return new Vector4(
			X + t * (target->X - X),
			Y + t * (target->Y - Y),
			Z + t * (target->Z - Z),
			W + t * (target->W - W)
		);
	};
	Vector4* Lerp(const Vector* target, float t) const {
		return new Vector4(
			X + t * (target->X - X),
			Y + t * (target->Y - Y),
			Z + t * (target->Z - Z),
			W
		);
	};
};

float GetDistanceBetweenPoints3D(Vector4 v1, Vector4 v2);