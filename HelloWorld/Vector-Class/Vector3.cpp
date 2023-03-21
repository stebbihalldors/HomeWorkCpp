#include "Vector3.h"
#include <cstdio>

Vector3::Vector3() : x{ 0 }, y{ 0 }, z{ 0 }
{
	printf("Empty Constructor made\n");
}

Vector3::Vector3(const int a, const int b, const int c) : x{a},y{b},z{c}
{
	printf("Non-Empty Constructor made: Vector3(%d,%d,%d)\n", x, y, z);
}
Vector3::~Vector3()
{
	printf("Destructor things\n");
}
Vector3::Vector3(const Vector3& original) : x{ original.x }, y{ original.y }, z{ original.z }
{
	printf("Vector(%d,%d,%d) gets copied to new instance.\n", x,y,z);
}

void Vector3::Print() const
{
	printf("Vector3(%d,%d,%d)\n", x, y, z);
}