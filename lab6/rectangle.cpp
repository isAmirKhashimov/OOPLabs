#include "stdafx.h"
#include "rectangle.h"
#include <string>
#include "point.h"
#include <iostream>

TAllocator Rectangle::talloc(sizeof(Rectangle), 16);

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
	for (int i = 0; i < 4; i++)
	{
		apixes.push_back(Point(0,0));
	}
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

void Rectangle::Print(std::ostream& os)
{
	os << *this;
}

void Rectangle::Read(std::istream& is)
{
	is >> *this;
}

void* Rectangle::operator new(size_t size)
{
	return talloc.Allocate();
}

void Rectangle::operator delete(void* ptr)
{
	talloc.Deallocate(ptr);
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
	std::string output = "Rectangle: ";
	for (Point apix : rect.apixes)
	{
		output += apix.ToString();
	}
	outputStream << output + "\n";
	return outputStream;
}
