#include "rectangle.h"
#include "point.h"
#include <iostream>

Rectangle::Rectangle(const Rectangle& other)
{
	figureName = "Rectangle";
	for (int i = 0; i < 4; i++)
	{
		apixes.push_back(other.apixes[i]);
	}
}

Rectangle::Rectangle()
{
	figureName = "Rectangle";
}

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

bool Rectangle::operator==(const Rectangle& other) const
{
	for (int i = 0; i < 4; i++)
	{
		if (apixes[i].x != other.apixes[i].x && apixes[i].y != other.apixes[i].y)
			return false;
	}
	return true;
}

std::istream& operator>>(std::istream& inputStream, Rectangle& rect)
{
	for (int i = 0; i < 4; i++)
	{
		Point inputPoint(0, 0);
		inputStream >> inputPoint.x >> inputPoint.y;
		rect.apixes.push_back(inputPoint);
	}
	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Rectangle& rect)
{
	((Figure&)rect).Print(outputStream);
	return outputStream;
}
