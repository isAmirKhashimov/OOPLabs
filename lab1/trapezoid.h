#pragma once
#include "figure.h"
class Trapezoid :
    public Figure
{
public:
    double Area() override;
    Trapezoid(std::istream&);
};

