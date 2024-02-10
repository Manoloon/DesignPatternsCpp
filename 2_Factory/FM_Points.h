/*
    This is the Factory Method
*/
#include <ostream>
#include <cmath>

class FM_Points{
      FM_Points(float x,float y):x(x),y(y){}  
public:
    float x;
    float y;

    static FM_Points NewCartesian(float x, float y){
        return {x,y};
    }
    static FM_Points NewPolar(float radius, float theta){
        return {radius * cos(theta),radius * sin(theta)};
    }
    friend std::ostream &operator <<(std::ostream &os, const FM_Points& point){
            os << "x: " << point.x << " " << "y: " << point.y << std::endl;
            return os;
    } 
};
