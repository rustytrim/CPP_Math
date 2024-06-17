#pragma once

#include<string>

template <typename T>
struct Vector2
{

	T x, y;

	Vector2() : x(T()), y(T()) {};
	Vector2(T x, T y) : x(x), y(y) {};

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	};

	Vector2& operator-=(const Vector2& other) const
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 operator/(const Vector2& other) const
	{
		return Vector2(x / other.x, y / other.y);
	};

	Vector2& operator/=(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	};

	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	};

	Vector2& operator*=(const Vector2& other) const
	{
		x *= other.x;
		y *= other.y;
		return *this;
	};

	Vector2 operator%(const Vector2& other) const
	{
		return Vector2(x % other.x, y % other.y);
	};

	Vector2& operator%=(const Vector2& other) const
	{
		x %= other.x;
		y %= other.y;
		return *this;
	};

	T Magnitude() const
	{
		return std::sqrt((x * x) + (y * y));
	};


	Vector2& Normalize() const
	{
		T mag = Magnitude();
		x /= mag;
		y /= mag;
		return *this;
	};
	
	T Cross(const Vector2& other) const
	{
		return (x * other.x) - (y * other.y);
	};

	T Dot(const Vector2& other) const
	{
		return ((x * other.x) + (y + other.y));
	};

	std::string ToString() const
	{
		return "{ x: " + std::to_string(x) + " y: " + std::to_string(y) + " }";
	};
};