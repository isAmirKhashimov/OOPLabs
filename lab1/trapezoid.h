#pragma once
#ifndef TRAPEZOID_H_INCLUDED
#define TRAPEZOID_H_INCLUDED

#include "figure.h"
class Trapezoid :
    public Figure
{
public:
    double Area() override;
    Trapezoid(std::istream&);
};


#endif 