
#include <string>
#include <ostream>
#include <iostream>
#include <cmath>
#include "FM_points.h"

int main()
{
    auto p = FM_Points::NewCartesian(10,20);
    std::cout << "Cartesian : " << p;
    auto pPolar = FM_Points::NewPolar(10,M_PI_4);
    std::cout << "Polar : " << pPolar;
return 0;
}