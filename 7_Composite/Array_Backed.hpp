#pragma once
/*
Array_backed 
*/
#include <array>
#include <numeric>
#include <algorithm>
#include <iostream>
struct Enemy
{
    enum Stats{strength,intelligence,magic,dexterity,count};
    std::array<int,count> Stats;

    public:
    int getStrength() const {return Stats[strength];}
    void setStrength(int value) {Stats[strength] = value;}
    int getIntelligence() const {return Stats[intelligence];}
    void setIntelligence(int value) {Stats[intelligence] = value;}
    int getMagic() const {return Stats[magic];}
    void setMagic(int value) { Stats[magic] = value;}
    int getDexterity() const {return Stats[dexterity];}
    void setDexterity(int value) {Stats[dexterity]=value;}

    int sum() const 
    {
        return std::accumulate(Stats.begin(), Stats.end(),0);
    }

    double avg() const 
    {
        return sum() / (double)count;
    }

    int max() const 
    {
        return *std::max_element(Stats.begin(),Stats.end());
    }
};

void ArrayExecuteTest()
{
    Enemy Paladin;
    Paladin.setStrength(9);
    Paladin.setDexterity(7);
    Paladin.setIntelligence(9);
    Paladin.setMagic(4);
    std::cout << "The Paladin has average stats of "
                << Paladin.avg()
                << " and a max stat of "
                << Paladin.max()
                << '\n';
}