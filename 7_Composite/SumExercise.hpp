#pragma once
/*
Consider the code presented below. The sum()  function takes a vector of pointers 
to either SingleValue or ManyValues instances and adds up all their elements together.

Please complete the implementation so that the sum()  
function starts to operate correctly. This may involve giving the classes a 
common interface, among other things.

Here is an example of how the function might be used:

    SingleValue single_value{ 1 };
    ManyValues other_values;
    other_values.add(2);
    other_values.add(3);
    sum({ &single_value, &other_values }); // returns 6
*/
#include <vector>
#include <numeric>
#include <iostream>

struct ContainsIntegers
{
    virtual std::vector<int> getValues() const = 0;
    virtual ~ContainsIntegers() = default;
};

struct SingleValue : ContainsIntegers
{
    int locValue;
    SingleValue(int value):locValue(value){}

    std::vector<int> getValues() const override { return {locValue}; }
};

struct ManyValues : std::vector<SingleValue>, ContainsIntegers
{
    std::vector<int> locValues;
    void add(int value)
    {
        locValues.emplace_back(value);
    }

    std::vector<int> getValues() const override 
    {
        return locValues;
    }
};

int sum(const std::vector<ContainsIntegers*> items)
{
   int result = 0;
   for(const auto& item : items)
   {
    for(int val : item->getValues())
    {
        result += val;
    }
   }
   return result;
}

void SumExecuteTest()
{
    SingleValue single_value{ 1 };
    ManyValues other_values;
    other_values.add(2);
    other_values.add(3);
    int result = sum({ &single_value, &other_values }); // returns 6
    std::cout << "Result of Sum " << result << '\n';
    
}