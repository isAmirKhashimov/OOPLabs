#pragma once
#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

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

#endif