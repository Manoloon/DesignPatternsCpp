## Chain of Responsability
# 
* Old School :

* 
* 
* Exercise
Chain of Responsibility Coding Exercise
You are given a game scenario with classes Goblin  and GoblinKing . Please implement the following rules:

A goblin has base 1 attack/1 defense (1/1), a goblin king is 3/3.
When the Goblin King is in play, every other goblin gets +1 Attack.
Goblins get +1 to Defense for every other Goblin in play (a GoblinKing is a Goblin!).
Example:

Suppose you have 3 ordinary goblins in play. Each one is a 1/3 (1/1 + 0/2 defense bonus).
A goblin king comes into play. Now every ordinary goblin is a 2/4 (1/1 + 0/3 defense bonus from each other + 1/0 from goblin king)
Meanwhile, the goblin king itself is 3/6 (3/3 + 0/3 defense bonus from other goblins)
Here is an example of the kind of test that will be run on the system:

Game game;
Goblin goblin(game);
game.creatures.push_back(&goblin);
ASSERT_EQ(1, goblin.get_attack());
ASSERT_EQ(1, goblin.get_defense());
# 

