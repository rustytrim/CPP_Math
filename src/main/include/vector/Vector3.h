#pragma once

#include<string>

template <typename T>
struct Vector3
{

	T x, y, z;

	Vector3() : x(T()), y(T()), z(T()) {};
	Vector3(T x, T y, T z) : x(x), y(y), z(z) {};

	Vector3 operator+(const Vector3& other) const
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3& operator+=(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3 operator-(const Vector3& other) const
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	};

	Vector3& operator-=(const Vector3& other) const
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3 operator/(const Vector3& other) const
	{
		return Vector3(x / other.x, y / other.y, z / other.z);
	};

	Vector3& operator/=(const Vector3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	};

	Vector3 operator*(const Vector3& other) const
	{
		return Vector3(x * other.x, y * other.y, z * other.z);
	};

	Vector3& operator*=(const Vector3& other) const
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	};

	Vector3 operator%(const Vector3& other) const
	{
		return Vector3(x % other.x, y % other.y, z % other.z);
	};

	Vector3& operator%=(const Vector3& other) const
	{
		x %= other.x;
		y %= other.y;
		z %= other.z;
		return *this;
	};

	T Magnitude() const
	{
		return std::sqrt((x * x) + (y * y) + (z * z);
	};


	Vector3& Normalize() const
	{
		T mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
		return *this;
	};

	Vector3 Cross(const Vector3& other) const
	{
		return Vector3((y * other.z - z * other.y), (z * other.x - x * other.z), (x * other.y - y * other.x))
	};

	T Dot(const Vector3& other) const
	{
		return ((x * other.x) + (y + other.y) + (z + other.z);
	};

	std::string ToString() const
	{
		return "{ x: " + std::to_string(x) + " y: " + std::to_string(y) + " z: " + std::to_string(z) + " }";
	};
};