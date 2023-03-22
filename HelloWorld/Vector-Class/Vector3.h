#pragma once
class Vector3
{
	float x, y, z;
	friend Vector3 operator*(const float a, const Vector3& s); // scalar
	friend Vector3 operator*=(const float a, const Vector3& s);

public:
	Vector3();
	Vector3(const float a, const float b, const float c);
	~Vector3();
	Vector3(const Vector3& original);
	void Print() const;

	Vector3 operator+(const Vector3& s) const;
	Vector3 operator-(const Vector3& s)const;
	float operator*(const Vector3& s) const;  // dotproduct
	Vector3 operator*(const float a) const;   // scalar
	Vector3 operator/(const float a) const;   // divide by scalar
	Vector3 operator-() const;
	
	bool operator==(const Vector3& s) const;
	bool operator!=(const Vector3& s) const;

	Vector3& operator+=(const Vector3& s);
	Vector3& operator-=(const Vector3& s);  
	Vector3& operator*=(const Vector3& s);   
	Vector3& operator/=(float f);

	Vector3 operator=(const Vector3& s);
};
Vector3 operator*(const float a, const Vector3& s); // scalar (needs outside class because first arguement is not the class itself)
Vector3 operator*=(const float a, const Vector3& s);
