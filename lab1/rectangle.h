#pragma once
#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "figure.h"
class Rectangle :
    public Figure
{
public:
    double Area() override;
    Rectangle(std::istream&);
};

#endif