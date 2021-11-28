#pragma once
#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "figure.h"
class Rectangle :
    public Figure
{
public:

    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);

    Rectangle(const Rectangle&);
    Rectangle();
    double Area() override;
    Rectangle(std::istream&);
    bool operator==(const Rectangle& other) const;
};

#endif