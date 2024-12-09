#pragma once 
#include <string>
#include <sstream>
#include <concepts>
#include <type_traits>

struct Shape 
{
    virtual std::string getName() const = 0;
};

struct ColoredShape : Shape
{
    Shape& LocShape;
    std::string Color;
    
    ColoredShape(Shape& shape,const std::string& color):LocShape(shape),Color(color){}

    std::string getName() const override 
    {
        std::ostringstream oss;
        oss << LocShape.getName() << " with color " << Color;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape& LocShape;
    float Transparency = 100;
    TransparentShape(Shape& shape,float transparency):LocShape(shape),Transparency(transparency)
    {}

    std::string getName() const override 
    {
        std::ostringstream oss;
        float factor = (Transparency / 255) * 100;
        oss <<  LocShape.getName() << "has transparency of " << factor << "%";
        return oss.str();
    }
};

struct Circle : Shape
{
    float Radius;
    Circle()=default;
    Circle(float radius):Radius(radius){};
    
    std::string getName() const override 
    {
        std::ostringstream oss;
        oss << "I am a Circle of radius " << Radius;
        return oss.str();
    }
};

/*
    Static Decorator using Mixing Inheritance and Perfect forwarding
*/
template<typename T>
concept IsAShape = requires {std::is_base_of_v<Shape,T>;};

template<IsAShape T>
struct StaticColoredShape : T
{
    std::string Color;
    template<typename... Args>
    StaticColoredShape(const std::string& color,Args...args):
        T(std::forward<Args>(args)...),Color{color}{}
    
    std::string getName() const override 
    {
        std::ostringstream oss;
        oss << T::getName() << " and my color is " << Color;
        return oss.str();
    }
};