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
  Command(Action act, int amount):action{act},amount{amount}{};
};
struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    if (cmd.success)
    {
      return;
    }
    if (cmd.action == cmd.deposit)
    {
        balance += cmd.amount;
        cmd.success = true;
    }
    else 
    {
        if (balance >= cmd.amount)
        {
            balance -= cmd.amount;
            cmd.success = true;
        }
    }
  }
};

int main()
{
  Account account;
  Command cmd1(Command::deposit,100);
  account.process(cmd1);
  assert(account.balance == 100);
  Command cmd2(Command::withdraw,100);
  account.process(cmd2);
  assert(account.balance == 0);
  Command cmd3(Command::withdraw,100);
  account.process(cmd3);
  assert(account.balance == 0);
}
