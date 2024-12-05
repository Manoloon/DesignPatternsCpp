#include <iostream>
#include <string>

#include "CRTP.hpp"
#include "Array_Backed.hpp"
#include "SumExercise.hpp"

int main()
{
	ExecuteTest();
	std::cout << " testing Array backed use \n";
	ArrayExecuteTest();
	std::cout << " Exercise \n";
	SumExecuteTest();
	return 0;
}
