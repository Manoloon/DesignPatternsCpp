#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
    int count =0;
public:
  Person create_person(const string& name)
  {
    Person p;
    p.name = name;
    p.id = count++;
    return p;
  }
};