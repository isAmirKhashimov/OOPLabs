#pragma once
#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <ostream>
#include "point.h"
#include <vector>

class Figure
{
public:
	std::vector<Point> apixes;
	std::string figureName;
	virtual size_t VertexesNumber();
	virtual double Area() = 0;
	virtual void Print(std::ostream& os) = 0;
	virtual void Read(std::istream& is) = 0;

	friend std::ostream& operator<<(std::ostream& os, Figure& p)
	{
		p.Print(os);
		return os;
	}

	friend std::istream& operator >> (std::istream& is, Figure& p)
	{
		p.Read(is);
		return is;
	}
};

#endif
