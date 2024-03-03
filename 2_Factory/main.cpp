
#include <string>
#include <ostream>
#include <iostream>
#include <vector>
#include "FM_points.h"
#include "Abstract_RobotFactory.h"
#include "Factory_assigment.h"
const double PI  =3.141592653589793238463;
int main()
{
    // Factory method
    std::cout << "Cartesian : " << FM_Points::NewCartesian(10,20) << std::endl;
    std::cout << "Polar : " << FM_Points::NewPolar(10,PI) << std::endl;


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