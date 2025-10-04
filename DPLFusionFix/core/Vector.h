#pragma once
#include <math.h>

# define M_PI           3.14159265358979323846

class Vector
{
public:
	float X, Y, Z;
	Vector(void) {}
	Vector(float a, float b, float c)
	{
		X = a;
		Y = b;
		Z = c;
	}
	float Heading(void) const { return atan2(-X, Y); }
	float Magnitude(void) const { return sqrt(X * X + Y * Y + Z * Z); }
	float MagnitudeSqr(void) const { return X * X + Y * Y + Z * Z; }
	float Magnitude2D(void) const { return sqrt(X * X + Y * Y); }
	float MagnitudeSqr2D(void) const { return X * X + Y * Y; }
	void Normalise();
	Vector Lerp(const Vector& target, float t) const {
		return Vector(
			X + t * (target.X - X),
			Y + t * (target.Y - Y),
			Z + t * (target.Z - Z)
		);
	}

	const Vector& operator+=(Vector const& right) {
		X += right.X;
		Y += right.Y;
		Z += right.Z;
		return *this;
	}

	const Vector& operator+=(float const& right) {
		X += right;
		Y += right;
		Z += right;
		return *this;
	}

	const Vector& operator-=(Vector const& right) {
		X -= right.X;
		Y -= right.Y;
		Z -= right.Z;
		return *this;
	}

	const Vector& operator*=(float right) {
		X *= right;
		Y *= right;
		Z *= right;
		return *this;
	}

	const Vector& operator/=(float right) {
		X /= right;
		Y /= right;
		Z /= right;
		return *this;
	}

	Vector operator-() const {
		return Vector(-X, -Y, -Z);
	}
};

inline Vector operator+(const Vector& left, const Vector& right)
{
	return Vector(left.X + right.X, left.Y + right.Y, left.Z + right.Z);
}

inline Vector operator-(const Vector& left, const Vector& right)
{
	return Vector(left.X - right.X, left.Y - right.Y, left.Z - right.Z);
}

inline Vector operator*(const Vector& left, float right)
{
	return Vector(left.X * right, left.Y * right, left.Z * right);
}

inline Vector operator*(float left, const Vector& right)
{
	return Vector(left * right.X, left * right.Y, left * right.Z);
}

inline Vector operator/(const Vector& left, float right)
{
	return Vector(left.X / right, left.Y / right, left.Z / right);
}

Vector CrossProduct(const Vector& v1, const Vector& v2);

float GetYAxisFromDirection(Vector direction);
void GetAxisVectorFromDirection(Vector direction, Vector& vector);
float GetDistanceBetweenPoints2D(float x1, float y1, float x2, float y2);
float GetDistanceBetweenPoints3D(float x1, float y1, float z1, float x2, float y2, float z2);