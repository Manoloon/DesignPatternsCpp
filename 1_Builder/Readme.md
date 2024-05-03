# Design Pattern : BUILDER
Builder is a creational pattern where the objects are constructed putting component together from the root to top.
Avoiding object have a huge custom constructor.
So , this pattern is handy when piecewise objects construction is complicated, using an API to achieved this in a brief and clearly expressed manner.

# Builder Coding Exercise
## You are asked to implement the Builder design pattern for rendering simple chunks of code.
Sample use of the builder you are asked to create:

    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;

The expected output of the above code is:

    class Person
    {
      string name;
      int age;
    };

Please observe the same placement of curly braces and use two-space indentation.
