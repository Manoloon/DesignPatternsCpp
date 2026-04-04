#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <cassert>
/*
	Interpreter Exercise 
*/
struct ExpressionProcessor
{
  std::map<char,int> variables;
  
  int calculate(const std::string& expression)
  {
    int result = 0;
    int sign = 1; // 1 == + , -1 == - ;
    for(size_t i = 0; i < expression.size();)
    {
      //auto curr = expression[i];
      if(std::isspace(expression[i]))
      {
        ++i;
        continue;
      }
      // operators 
      if(expression[i] == '+')
      {
        sign = 1;
        ++i;
      }
      else if (expression[i] == '-')
      {
        sign = -1;
        ++i;
      }
      // numbers
      else if (std::isdigit(expression[i]))
      {
        int val = 0;
        while(i < expression.size() && std::isdigit(expression[i]))
        {
          val = val * 10 + (expression[i] - '0');
          ++i;
        }
        result += sign * val;
      }
      // handle variables
      else if (std::isalpha(expression[i]))
      {
        if(i + 1 < expression.size() && std::isalpha(expression[i+1]))
        {
          return 0;
        }
        char var = expression[i];
        if(variables.find(var) == variables.end())
        {
          return 0;
        }
        result += sign * variables[var];
        ++i;
      }
      else
      {
        return 0;
      }
    }
    return result;
  }
};

int main()
{
  ExpressionProcessor ep;
  ep.variables['x'] = 5;
  ep.variables['y'] = 3;
  assert(ep.calculate("1")== 1);
  assert (ep.calculate("1+2+3")== 6);
  assert (ep.calculate("10+x-y")== 12);
  assert(ep.calculate("x+z") == 0);       // 0 (z undefined)
  assert(ep.calculate("ab+1") == 0);      // 0 (invalid variable)
  ep.calculate("1++2");      // 0 (invalid parsing)
}
