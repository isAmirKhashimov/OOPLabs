#pragma once
#ifndef RHOMBUS_H_INCLUDED
#define RHOMBUS_H_INCLUDED

#include "figure.h"
class Rhombus :
    public Figure
{
public:
    double Area() override;
    Rhombus(std::istream&);
};

#endif