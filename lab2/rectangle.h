#pragma once
#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "figure.h"
class Rectangle :
    public Figure
{
public:

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);

    Rectangle(const Rectangle&);
    double Area() override;
    Rectangle(std::istream&);
    bool operator==(const Rectangle& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
};

#endif