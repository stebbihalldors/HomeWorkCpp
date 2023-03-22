#include "Vector3.h"
#include <cstdio>

Vector3::Vector3() : x{ 0 }, y{ 0 }, z{ 0 }
{
	printf("Empty Constructor made\n");
}

Vector3::Vector3(const float a, const float b, const float c) : x{a},y{b},z{c}
{
	printf("Non-Empty Constructor made: Vector3(%g,%g,%g)\n", x, y, z);
}
Vector3::~Vector3()
{
	printf("Destructor things\n");
}
Vector3::Vector3(const Vector3& original) : x{ original.x }, y{ original.y }, z{ original.z }
{
	printf("Vector(%g,%g,%g) gets copied to new instance.\n", x,y,z);
}

void Vector3::Print() const
{
	printf("Vector3(%g,%g,%g)\n", x, y, z);
}

Vector3 Vector3::operator+(const Vector3& s) const
{
	return Vector3(x + s.x, y + s.y, z + s.z);
}

Vector3 Vector3::operator-(const Vector3& s) const
{
	return Vector3(x - s.x, y - s.y, z - s.z);
}
float Vector3::operator*(const Vector3& s) const
{
	return x * s.x + y * s.y + z * s.z;
}
Vector3 Vector3::operator/(const float a) const
{
	return Vector3(x / a, y / a, z / a);
}
Vector3 Vector3::operator*(const float a) const
{
	return Vector3(x * a, y * a, z * a);
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

bool Vector3::operator==(const Vector3& s) const
{
	return (x == s.x && y == s.y && z == s.z);
}
bool Vector3::operator!=(const Vector3& s) const
{
	return !(*this == s);
}

Vector3& Vector3::operator*=(const Vector3& s)
{
	x = x * s.x;
	y = y * s.y;
	z = z * s.z;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& s)
{
	x = x + s.x;
	y = y + s.y;
	z = z + s.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& s)
{
	x = x - s.x;
	y = y - s.y;
	z = z - s.z;
	return *this;
}

Vector3& Vector3::operator/=(float f)
{
	x = x / f;
	y = y / f;
	z = z / f;
	return *this;
}

Vector3 Vector3::operator=(const Vector3& s)
{
	return Vector3(x=s.x, y=s.y,z=s.z);
}

Vector3 operator*(const float a, const Vector3& s)
{
	return Vector3(a * s.x, a * s.y, a * s.z);
}

Vector3 operator*=(const float a, const Vector3& s)
{
	return Vector3(a * s.x, a * s.y, a * s.z);
}
	