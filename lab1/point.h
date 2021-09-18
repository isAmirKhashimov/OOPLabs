#pragma once
#include <string>

struct Point {
	double x, y;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	std::string ToString()
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}
	double DistanceTo(Point endPoint)
	{
		return sqrt((x - endPoint.x) * (x - endPoint.x)
			+ (y - endPoint.y) * (y - endPoint.y));
	}
};
