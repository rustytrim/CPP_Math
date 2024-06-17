#include <iostream>
#include <units.h>
#include <vector/Vector3.h>

int main()
{
	Vector3<units::degrees> v(0.0, 0.0, 0.0);
	v.x = 90;
	v.y = 45;
	v.z = 25;

	units::degrees yuh = 90;
	units::radians hm = 1;

	yuh = yuh + hm;
}