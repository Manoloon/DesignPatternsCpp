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
  int result = 0;
};

struct Creature
{
protected:
  Game& game;
  int base_attack, base_defense;

public:
  bool is_king = false;
  Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                            base_defense(base_defense) 
  {
      game.creatures.emplace_back(this);
  }
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

  Goblin(Game &game) : Creature(game,1,1) {}
  void query(StatQuery& q, Creature* requester) override 
  {
    // goblins doesnt apply attack bonuses
    if (q.statistic == StatQuery::attack)
    {
      if (requester == this)
      {
        q.result += base_attack;
      }
    }
    // but they do apply defense bonus
    else if (q.statistic == StatQuery::defense)
    {
      if (requester == this)
      {
        q.result +=base_defense;
      }
      // but not for the king
      else if (!requester->is_king)
      {
        q.result +=1;
      }
    }
  }
};

class GoblinKing : public Goblin
{
public:
  GoblinKing(Game &game) : Goblin(game,3,3){is_king = true;}

  void query(StatQuery& q, Creature* requester) override
  {
    // defense is handle by goblin class which King is part of it 
    Goblin::query(q,requester);
    // Bonus its only granted by the king
    if(q.statistic == StatQuery::attack )
    {
      if(requester != this)
        {
          q.result += 1;
        }
    }
  }
};

void test_single_goblin()
{
  Game game;

  Goblin g1(game);
  assert(g1.get_attack() == 1);
  assert(g1.get_defense() == 1);

  std::cout << "test_single_goblin passed\n";
}

void test_two_goblins()
{
  Game game;

  Goblin g1(game);
  Goblin g2(game);

  assert(g1.get_attack() == 1);
  assert(g1.get_defense() == 2);

  assert(g2.get_attack() == 1);
  assert(g2.get_defense() == 2);

  std::cout << "test_two_goblins passed\n";
}

void test_goblin_and_king()
{
  Game game;

  Goblin g1(game);
  GoblinKing king(game);

  assert(g1.get_attack() == 2);
  assert(g1.get_defense() == 2);

  assert(king.get_attack() == 3);
  assert(king.get_defense() == 3);

  std::cout << "test_goblin_and_king passed\n";
}

void test_two_goblins_and_king()
{
  Game game;
  Goblin g1(game);
  Goblin g2(game);
  GoblinKing king(game);

  assert(g1.get_attack() == 2);
  assert(g1.get_defense() == 3);

  assert(g2.get_attack() == 2);
  assert(g2.get_defense() == 3);

  assert(king.get_attack() == 3);
  assert(king.get_defense() == 3);

  std::cout << "test_two_goblins_and_king passed\n";
}

int main()
{
  test_single_goblin();
  test_two_goblins();
  test_goblin_and_king();
  test_two_goblins_and_king();

  std::cout << "All tests passed\n";
}
