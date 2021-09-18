#include "rectangle.h"
#include "point.h"
#include <iostream>


double Rectangle::Area()
{
	return apixes[0].DistanceTo(apixes[1])
		* apixes[1].DistanceTo(apixes[2]);
}

Rectangle::Rectangle(std::istream& inputStream)
{
	figureName = "Rectangle";
	for (int i = 0; i < 4; i++)
	{
		Point inputPoint(0, 0);
		inputStream >> inputPoint.x >> inputPoint.y;
		apixes.push_back(inputPoint);
	}

}
