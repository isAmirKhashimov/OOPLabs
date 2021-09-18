#pragma once
#include "figure.h"
class Rhombus :
    public Figure
{
public:
    double Area() override;
    Rhombus(std::istream&);
};

