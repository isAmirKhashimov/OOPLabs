#pragma once
#include "figure.h"
class Rectangle :
    public Figure
{
public:
    double Area() override;
    Rectangle(std::istream&);
};

