#include "rhombus.h"
#include <iostream>

double Rhombus::Area()
{
	return apixes[0].DistanceTo(apixes[2])
		* apixes[1].DistanceTo(apixes[3]) / 2;
}

Rhombus::Rhombus(std::istream& inputStream)
{
	figureName = "Rhombus";
	for (int i = 0; i < 4; i++)
	{
		Point inputPoint(0, 0);
		inputStream >> inputPoint.x >> inputPoint.y;
		apixes.push_back(inputPoint);
	}
}