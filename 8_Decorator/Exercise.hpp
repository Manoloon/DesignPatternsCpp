#pragma once 
/*
Roses can be red, blue or red and blue. 
*/

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Flower
{
  virtual string str() = 0;
  virtual ~Flower()=default;
};

struct Rose : Flower
{
  string str() override {
    return "A rose";
  }
};

struct RedFlower : Flower
{
    Flower& flower;
    string color = "red";
    RedFlower()=default;
    RedFlower(Flower& _flower):flower(_flower){}

    string str() override 
    {
        ostringstream oss;
        string flowerString = flower.str();
        if(flowerString == "A rose" && !flowerString.ends_with(color))
        {
            oss << flowerString << " that is " << color;
        }
        else
        {
            oss << flowerString << " and " << color;
        }
        return oss.str();
    }
};

struct BlueFlower : Flower
{
    Flower& flower;
    string color = "blue";
    BlueFlower()=default;
    BlueFlower(Flower& _flower):flower(_flower){}
    string str() override 
    {
        ostringstream oss;
        string flowerString = flower.str();
                if(flowerString == "A rose" && !flowerString.ends_with(color))
        {
            oss << flowerString << " that is " << color;
        }
        else
        {
            oss << flowerString << " and " << color;
        }
        return oss.str();
    }
};

// template<typename T>
// concept IsAFlower = requires {is_base_of_v{Flower,T};};
// template <IsAFlower T>
// struct staticFlower : T
// {
//     string str() override
//     {
//         ostringstream oss;
//         oss << T::str()
//         return oss.str();
//     }
// };

void RoseTest()
{
    Rose       rose;
    RedFlower  red_rose{rose};
    RedFlower  red_red_rose{red_rose};
    BlueFlower blue_rose{rose};
    BlueFlower blue_red_rose{red_rose};
    RedFlower  red_blue_red_rose{blue_red_rose};
    BlueFlower red_blue_red_blue_rose{red_blue_red_rose};
    // Nested flowers with explicit Flower objects
    BlueFlower blue_rose_nested{red_rose};  // Wrap red_rose in BlueFlower
    RedFlower red_blue_red_rose_nested{RedFlower{blue_rose_nested}}; // Wrap blue_rose_nested in RedFlower

    cout << rose.str() << '\n';          // "A rose"
    cout << red_rose.str() << '\n';      // "A rose that is red"
    cout << red_red_rose.str() << '\n';  // "A rose that is red"
    cout << blue_rose.str() << '\n';     // "A rose that is blue"
    cout << blue_red_rose.str() << '\n'; // "A rose that is red and blue"
    cout << red_blue_red_rose.str() << '\n'; // "A rose that is red and blue and red"
    cout << red_blue_red_blue_rose.str() << '\n'; // "A rose that is red and blue and red and blue"
    cout << red_blue_red_rose_nested.str() << '\n'; // "A rose that is blue and red and blue and red"
}
