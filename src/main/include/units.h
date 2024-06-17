#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace units
{
	struct base
	{
	protected:
		double value;

	public:
		base(double v = 0.0) : value(v) {}

		base operator+(const base& other)
		{
			return base(value + other.value);
		}

		base& operator+=(const base& other)
		{
			value += other.value;
			return *this;
		}

		base operator-(const base& other)
		{
			return base(value - other.value);
		}

		base& operator-=(const base& other)
		{
			value -= other.value;
			return *this;
		}

		base operator*(const base& other)
		{
			return base(value * other.value);
		}

		base& operator*=(const base& other)
		{
			value *= other.value;
			return *this;
		}

		base operator/(const base& other)
		{
			return base(value / other.value);
		}

		base& operator/=(const base& other)
		{
			value /= other.value;
			return *this;
		}

		base operator%(base& other)
		{
			return base(std::fmod(value, other.value));
		}

		base& operator%=(const base& other)
		{
			value = std::fmod(value, other.value);
			return *this;
		}

		double Value() const
		{
			return value;
		}

		void Clamp(double min, double max)
		{
			value = std::fmax(min, std::fmin(value, max));
		}
	};

	struct degrees;

	struct radians : base
	{
		using base::base;

		radians(degrees& other);

		void Normalize()
		{
			value = std::fmod(value, 2 * M_PI);
			if (value < 0)
				value += 2 * M_PI;
		}

		radians operator+(const degrees& other);
		radians& operator+=(const degrees& other);
		radians operator-(const degrees& other);
		radians& operator-=(const degrees& other);
		radians operator*(const degrees& other);
		radians& operator*=(const degrees& other);
		radians operator/(const degrees& other);
		radians& operator/=(const degrees& other);
		radians operator%(const degrees& other);
		radians& operator %=(const degrees& other);
	};

	struct degrees : base
	{
		using base::base;

		degrees(radians& other);

		void Normalize()
		{
			value = std::fmod(value, 360);
			if (value < 0)
				value += 360;
		}

		degrees operator+(const radians& other);
		degrees& operator+=(const radians& other);
		degrees operator-(const radians& other);
		degrees& operator-=(const radians& other);
		degrees operator*(const radians& other);
		degrees& operator*=(const radians& other);
		degrees operator/(const radians& other);
		degrees& operator/=(const radians& other);
		degrees operator%(const radians& other);
		degrees& operator %=(const radians& other);
	};

	radians::radians(degrees& other)
	{
		value = other.Value() * (M_PI / 180);
	}

	radians radians::operator+(const degrees& other)
	{
		return radians(value + (other.Value() * (M_PI / 180)));
	}

	radians& radians::operator+=(const degrees& other)
	{
		value += other.Value() * (M_PI / 180);
		return *this;
	}
	
	radians radians::operator-(const degrees& other)
	{
		return radians(value - (other.Value() * (M_PI / 180)));
	}

	radians& radians::operator-=(const degrees& other)
	{
		value -= other.Value() * (M_PI / 180);
		return *this;
	}
	
	radians radians::operator*(const degrees& other)
	{
		return radians(value * (other.Value() * (M_PI / 180)));
	}

	radians& radians::operator*= (const degrees & other)
	{
		value *= other.Value() * (M_PI / 180);
		return *this;
	}
	
	radians radians::operator/(const degrees& other)
	{
		return radians(value / (other.Value() * (M_PI / 180)));
	}

	radians& radians::operator/= (const degrees& other)
	{
		value /= other.Value() * (M_PI / 180);
		return *this;
	}
	
	radians radians::operator%(const degrees& other)
	{
		return radians(std::fmod(value, (other.Value() * (M_PI / 180))));
	}

	radians& radians::operator%= (const degrees& other)
	{
		value = std::fmod(value, other.Value() * (M_PI / 180));
		return *this;
	}

	degrees::degrees(radians& other)
	{
		value = other.Value() * (180 / M_PI);
	}

	degrees degrees::operator+(const radians& other)
	{
		return degrees(value + (other.Value() * (180 / M_PI)));
	}

	degrees& degrees::operator+=(const radians& other)
	{
		value += other.Value() * (180 / M_PI);
		return *this;
	}
	
	degrees degrees::operator-(const radians& other)
	{
		return degrees(value - (other.Value() * (180 / M_PI)));
	}

	degrees& degrees::operator-=(const radians& other)
	{
		value -= other.Value() * (180 / M_PI);
		return *this;
	}
	
	degrees degrees::operator*(const radians& other)
	{
		return degrees(value * (other.Value() * (180 / M_PI)));
	}

	degrees& degrees::operator*=(const radians& other)
	{
		value *= other.Value() * (180 / M_PI);
		return *this;
	}
	
	degrees degrees::operator/(const radians& other)
	{
		return degrees(value / (other.Value() * (180 / M_PI)));
	}

	degrees& degrees::operator/=(const radians& other)
	{
		value /= other.Value() * (180 / M_PI);
		return *this;
	}
	
	degrees degrees::operator%(const radians& other)
	{
		return degrees(std::fmod(value, (other.Value() * (180 / M_PI))));
	}

	degrees& degrees::operator%=(const radians& other)
	{
		value = std::fmod(value, other.Value() * (180 / M_PI));
		return *this;
	}
}