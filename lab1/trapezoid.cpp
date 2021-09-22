#include "trapezoid.h"
#include <iostream>
#include <cmath>

double Trapezoid::Area()
{
	// TODO override operator -
	Point vec1(0.0, 0.0), vec2(0.0, 0.0);

	vec1.x = apixes[0].x - apixes[2].x;
	vec1.y = apixes[0].y - apixes[2].y;

	vec2.x = apixes[1].x - apixes[3].x;
	vec2.y = apixes[1].y - apixes[3].y;

	double cosFi = (vec1.x * vec2.x + vec1.y * vec2.y) /
		sqrt((vec1.x * vec1.x + vec1.y * vec1.y) * (vec2.x * vec2.x + vec2.y * vec2.y));

	double sinFi = sqrt(1 - cosFi * cosFi);

	double d1 = apixes[0].DistanceTo(apixes[2]);
	double d2 = apixes[1].DistanceTo(apixes[3]);

	return d1 * d2 * sinFi * 0.5;

}

Trapezoid::Trapezoid(std::istream& inputStream)
{
	figureName = "Trapezoid";
	for (int i = 0; i < 4; i++)
	{
		Point inputPoint(0, 0);
		inputStream >> inputPoint.x >> inputPoint.y;
		apixes.push_back(inputPoint);
	}
}
