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
  bool is_king = false;
  int get_attack()
  {
    StatQuery q{StatQuery::attack,0};
    for(auto c : game.creatures)
    {
      c->query(q,this);
    }
    std::cout << " Attack : " << q.result << std::endl;
    return q.result;
  }

  int get_defense()
  {
    StatQuery q{StatQuery::defense,0};
    for(auto c: game.creatures)
    {
      c->query(q,this);
    }
    std::cout << " Defense : " << q.result << std::endl;
    return q.result;
  }
  virtual void query(StatQuery& q, Creature* requester) = 0;
};


class Goblin : public Creature
{
public:
  Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

  Goblin(Game &game) : Creature(game, 1, 1) {}
  void query(StatQuery& q, Creature* requester) override 
  {
    if (q.statistic == StatQuery::attack)
    {
      q.result = base_attack;
      if (requester != this && requester->is_king)
      {
        q.result += 1;
      }
    }
    else if (q.statistic == StatQuery::defense)
    {
      if (requester == this)
      {
        q.result +=base_defense;
      }
      else
      {
        q.result +=1;
      }
    }
  }
};

class GoblinKing : public Goblin
{
public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) {is_king = true;}

  void query(StatQuery& q, Creature* requester) override
  {
    if(q.statistic == StatQuery::attack )
    {
      if(requester == this)
        {
          q.result += base_attack;
        }
      if (requester != this && !requester->is_king)
      {
        q.result +=1;
      }
    }
    else if (q.statistic == StatQuery::defense)
    {
      if (requester == this)
      {
        q.result += base_defense; 
      }
    }
  }
};


int main()
{
Game game;
Goblin goblin(game);
GoblinKing king(game);
game.creatures.emplace_back(&goblin);
assert(goblin.get_attack() == 1);
assert(goblin.get_defense() == 1);
game.creatures.emplace_back(&goblin);
assert(goblin.get_attack() == 1);
assert(goblin.get_defense() == 2);
game.creatures.emplace_back(&king);
assert(goblin.get_attack() == 2);
assert(goblin.get_defense() == 3);
assert(king.get_attack() == 3);
assert(king.get_defense() == 3);
	return 0;
}