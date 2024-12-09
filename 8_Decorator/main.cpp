#include <iostream>
#include <string>
#include "Shapes.hpp"

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
	StaticColoredShape<circle> StaticColorCircle{"Green",50};
	std::cout << StaticColorCircle.getName() << '\n';
	
	return 0;
}
