#include <iostream>
#include <string>
#include "Shapes.hpp"
#include "Exercise.hpp"

int main()
{
	// using dynamic 
	Circle circle(100);
	std::cout << circle.getName() << '\n';
	ColoredShape ColorCircle {circle,"Red"};
	std::cout << ColorCircle.getName() << '\n';
	// the problem is that if I want to change the radius of the ColorCircle I cant , because underline class 
	// Circle API isnt accesible

	// Static decorator 
	std::cout << "Static decorator :: \n"; 
	StaticColoredShape<Circle> StaticColorCircle{"Green",150};
	std::cout << StaticColorCircle.getName() << '\n';
	StaticColorCircle.Color = "Red";
	StaticColorCircle.Radius = 16;
	std::cout << StaticColorCircle.getName() << '\n';

	// Exercise
	std::cout << "Exercise decorator :: \n";
	RoseTest();
	return 0;
}
