#include <iostream>
#include "figure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"

int main()
{
    std::cout << std::fixed;
    std::cout.precision(20);
    
    std::cout << "Construct rectangle:\n";
    Figure* rectangle = new Rectangle(std::cin);
    rectangle->Print(std::cout);
    std::cout << "Area = " << rectangle->Area() << "\n";
    
    std::cout << "Construct trapezod:\n";
    Figure* trapezoid = new Trapezoid(std::cin);
    trapezoid->Print(std::cout);
    std::cout << "Area = " << trapezoid->Area() << "\n";
   
    std::cout << "Construct rhombus:\n";
    Figure* rhombus = new Rhombus(std::cin);
    rhombus->Print(std::cout);
    std::cout << "Area = " << rhombus->Area() << "\n";
}

