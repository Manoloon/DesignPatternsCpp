
#include <string>
#include <ostream>
#include <iostream>
#include <vector>
#include <cmath>
#include "FM_points.h"
#include "Abstract_RobotFactory.h"
#include "Factory_assigment.h"

int main()
{
    // Factory method
    auto p = FM_Points::NewCartesian(10,20);
    std::cout << "Cartesian : " << p;
    auto pPolar = FM_Points::NewPolar(10,M_PI_4);
    std::cout << "Polar : " << pPolar;

    // Abstract Factory
    
    // assigment 
    std::vector<std::string> names{"Pablo","Angie","Dulcinea","Priscilla"};
    PersonFactory PF;
    for(auto n : names){  
        auto p = PF.create_person(n);
        std::cout << p.name << " id: " << p.id << std::endl;
    }
return 0;
}