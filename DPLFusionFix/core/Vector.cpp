#include "Vector.h"

inline float RecipSqrt(float x, float y) { return x / sqrt(y); }
inline float RecipSqrt(float x) { return RecipSqrt(1.0f, x); }

void Vector::Normalise()
{
	float sq = MagnitudeSqr();
	if (sq > 0.0f) {
		float invsqrt = RecipSqrt(sq);
		X *= invsqrt;
		Y *= invsqrt;
		Z *= invsqrt;
	}
	else
		X = 1.0f;
}

Vector CrossProduct(const Vector& v1, const Vector& v2)
{
	return Vector(v1.Y * v2.Z - v1.Z * v2.Y, v1.Z * v2.X - v1.X * v2.Z, v1.X * v2.Y - v1.Y * v2.X);
}

// Returns the Y axis (in radians) facing a specific vector
float GetYAxisFromDirection(Vector direction)
{
	return atan2(direction.X, direction.Y);
}

// Returns a vector with X Y Z axis in radians indicating the direction 
void GetAxisVectorFromDirection(Vector direction, Vector& vector)
{
	float x = atan2(direction.Y, GetDistanceBetweenPoints2D(0, 0, direction.X, direction.Z));
	while (x > M_PI*2)
	{
		x = x - M_PI*2;
	}
	vector.X = x;
	vector.Y = GetYAxisFromDirection(direction);
	vector.Z = 0;
}

float GetDistanceBetweenPoints2D(float x1, float y1, float x2, float y2)
{
	float dist = pow((x2 - x1) * pow(x2 - x1, 2) + (y2 - y1) * pow(y2 - y1, 2), 0.5f);
	if (dist < 0)
		dist = 0;
	return dist;
}

float GetDistanceBetweenPoints3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	float dz = z2 - z1;
	float dist = sqrt(dx * dx + dy * dy + dz * dz);
	if (dist < 0)
		dist = 0;
	return dist;
}