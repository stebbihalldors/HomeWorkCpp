#pragma once
class Vector3
{
	const float x, y, z;
	friend Vector3 operator*(const float a, const Vector3& s); // scalar

public:
	Vector3();
	Vector3(const float a, const float b, const float c);
	~Vector3();
	Vector3(const Vector3& original);
	void Print() const;

	Vector3 operator+(const Vector3& s);
	Vector3 operator-(const Vector3& s);
	float operator*(const Vector3& s);  // dotproduct
	Vector3 operator*(const float a);   // scalar
	Vector3 operator/(const float a);   // divide by scalar
	bool operator==(const Vector3& s);
	bool operator!=(const Vector3& s);
	Vector3 operator-();
};
Vector3 operator*(const float a, const Vector3& s); // scalar (needs outside class because first arguement is not the class itself)
