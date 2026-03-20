#include <iostream>
#include <vector>
#include <cassert>
/*
	command Exercise 
*/
struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    // todo
  }
};

int main()
{

}
