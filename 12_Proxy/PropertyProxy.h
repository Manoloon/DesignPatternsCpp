#pragma once
#include <iostream>

template<typename T> struct Property
{
    T value;
    Property(T Value)
    {
        *this = value;
    }
    // assignment 
    T operator=(T new_value)
    {
        return value = new_value;
    }
    
    operator T()
    {
        return value;
    }
};

class Creature
{
    Property<int> Strength{10};
    Property<float> HealingPower{3.5f};

    public: 
    int GetStrength() const {return Strength.value;}
    void SetStrength(int new_val) {Strength.value = new_val;}
};

void test()
{
    Creature C;
    int s = C.GetStrength();
    std::cout << "Creature Strength : " << s << std::endl; 
    C.SetStrength(300);
    std::cout << "Creature new Strength : " << C.GetStrength() << std::endl; 
}