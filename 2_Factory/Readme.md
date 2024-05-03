# Factory Pattern
Factory its a creational pattern.
This pattern is useful when the construction of object logic its too convolute, for example a hell of optional parameters not being used by all the objects that are willing to be create, and this can be achieved by using Factory Method, Factory as class or a hierarchical set of Abstract factory classes.
* The difference with Builder pattern its that this pattern handle the Whole object creation NOT just the piece of it.

## Factory Method - FM_Points
	- Using Factory method to have different construct of a single class named Points
	- Can create points on a cartesian manner or a polar manner .
## Factory Functional - Func_RobotFactory
	- Using Functional Factory to handle creation of different types of robots.
  
## Factory Assigment
You are given a class called Person . The person has two fields: id , and name .

Please implement a non-static PersonFactory that has a create_person()  method that takes a person's name.

The id  of the person should be set as a 0-based index of the object created. So, the first person the factory makes should have id=0, second id=1 and so on.
