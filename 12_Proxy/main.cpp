#include <iostream>
#include <string>
#include <vector>
/*
	Proxy Exercise 
*/
class Person
{
  friend class ResponsiblePerson;
  int age;
public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age=age; }

  std::string drink() const { return "drinking"; }
  std::string drive() const { return "driving"; }
  std::string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
    ResponsiblePerson(const Person &person) : person(person) {}
    // todo
private:
    Person person;
};
int main()
{
	return 0;
}