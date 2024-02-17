/*
    This is the Factory Method
*/
#include <ostream>
#include <cmath>

class FM_Points{
      FM_Points(double x,double y):x(x),y(y){}  
public:
    double x;
    double y;

    static FM_Points NewCartesian(double x, double y){
        return {x,y};
    }
    static FM_Points NewPolar(double radius, double theta){
        return {radius * cos(theta),radius * sin(theta)};
    }
    friend std::ostream &operator <<(std::ostream &os, const FM_Points& point){
            os << "x: " << point.x << " " << "y: " << point.y << std::endl;
            return os;
    } 
};
