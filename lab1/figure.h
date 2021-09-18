#pragma once
#include <ostream>
#include "point.h"
#include <vector>

class Figure
{
protected:
	std::vector<Point> apixes;
	std::string figureName;
public:
	virtual size_t VertexesNumber();
	virtual double Area() = 0;
	virtual void Print(std::ostream& os);
};

