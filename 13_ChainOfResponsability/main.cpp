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
  public:
  ResponsiblePerson(const Person &person) : person(person){}
  int get_age() const {return person.age;}
  void set_age(int age) { person.set_age(age);}
  std::string drink()
  {
    if (person.age < 18)
    {
      return "too young";
    }
    return person.drink();
  }
  std::string drive()
  {
    if (person.age < 16)
    {
      return "too young";
    }
    return person.drive();
  }
  std::string drink_and_drive()
  {
    return "dead";
  }
private:
    Person person;
};
int main()
{
  Person person1(16);
  ResponsiblePerson rp(person1);
  std::string dr = rp.drive();
	return 0;
}