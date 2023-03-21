#pragma once
class Vector3
{
	const int x, y, z;

public:
	Vector3();
	Vector3(const int a, const int b, const int c);
	~Vector3();
	Vector3(const Vector3& original);
	void Print() const;
};

