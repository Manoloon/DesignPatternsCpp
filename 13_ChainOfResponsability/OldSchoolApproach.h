#pragma once 
#include <string>
#include <ostream>
class Enemy
{
    public:
    std::string Name;
    int Attack, Defense;

    friend ostream& operator<<(ostream& os, const Enemy& enemy)
    {
        os << "Enemy: " << enemy.Name << " attack: " << enemy.Attack << " defense: " << enemy.Defense;
        return os;
    }
};

class Modifier
{
    Modifier* next{nullptr};
    protected:
        Enemy& enemy;

    public:
    Modifier(Enemy& enemy):enemy(enemy){}

    void add(Modifier* mod)
    {
        if(next) next->add(mod);
        else next = mod;
    }
    virtual void handle()
    {
        if(next)
            next->handle();
    }
};

class DoubleAttackMod : public Modifier
{
    public:
    void handle() override
    {
        enemy.Attack *=2;
        Modifier::handle();
    }
};

class NoBonusMod : public Modifier
{
    public:
    void handle() override{};
};

void test()
{
    Enemy goblin{"Goblin",1,1};
    Modifier root{goblin};
    NoBonusMod NoBonusM{goblin};
    DoubleAttackMod DAMod{goblin};

    root.add(&NoBonusM);
    root.add(&DAMod);
    root.handle();
}