#pragma once
#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "figure.h"
#include "tallocator.h"
class Rectangle :
    public Figure
{
private:
	static TAllocator talloc;
public:

    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);

    Rectangle(const Rectangle&);
    Rectangle();
    double Area() override;
    Rectangle(std::istream&);
    bool operator==(const Rectangle& other) const;
	void Print(std::ostream& os);
	void Read(std::istream& is);
	void* operator new(size_t size);
	void operator delete(void* ptr);
};

#endif