//POINT.CPP
#include "point.h"

#include <cmath>
#include <string>


Point::Point() : x(0.0), y(0.0) {}

Point::Point(double xv, double yv) : x(xv), y(yv) {}

Point::Point(std::istream& is) {
	is >> x >> y;
}

double Point::DistanceTo(Point& other) {
	double dx = (other.x - x);
	double dy = (other.y - y);
	return std::sqrt(dx * dx + dy * dy);
}

std::string Point::ToString()
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Point& Point::operator=(const Point& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

bool Point::operator==(const Point& other)
{
	return x == other.x && y == other.y;
}

std::istream& operator>>(std::istream& is, Point& p) {
	is >> p.x >> p.y;
	return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
