#include <iostream>
#include <vector>
#include <typeinfo>
#include <cassert>
/*
	Responsability Exercise 
*/
struct Creature;
struct Game
{
  std::vector<Creature*> creatures;
  
};

struct StatQuery
{
  enum Statistic { attack, defense } statistic;
  int result;
};

struct Creature
{
protected:
  Game& game;

  int base_attack, base_defense;

public:
  Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                            base_defense(base_defense) {}
  virtual int get_attack() = 0;
  virtual int get_defense() = 0;
};

class Goblin : public Creature
{
public:
  Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

  Goblin(Game &game) : Creature(game, 1, 1) {}

  int get_attack() override {
    for (const auto& creature : game.creatures)
    {
      if (typeid(*creature) != typeid(Goblin))
      {
        base_attack +=1;
      }
    }
    return base_attack;
  }

  int get_defense() override {
    for (const auto& creature : game.creatures)
    {
      if(creature != this)
      {
         base_defense +=1;
      }
    }
    return base_defense;
  }
};

class GoblinKing : public Goblin
{
public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) {}

  int get_attack() override 
  {
    return base_attack;
  }
  int get_defense() override 
  {
    for (const auto& creature : game.creatures)
    {
      if (typeid(*creature) != typeid(GoblinKing))
      {
        base_defense +=1;
      }
    }
    return base_defense;
  }
};


int main()
{
Game game;
Goblin goblin(game);
game.creatures.push_back(&goblin);

assert(goblin.get_attack() == 1);
assert(goblin.get_defense() == 1);
	return 0;
}