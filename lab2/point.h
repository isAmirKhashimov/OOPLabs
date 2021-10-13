#pragma once
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <string>
#include <cmath>

struct Point {
	double x, y;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
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

#endif