# Decorator Pattern

## Dynamic

	Make used of inheritance but cant access underline classes , example : shape , circle , coloredCircle : The API will be from Shape but cant access circle API.
	Can be use at runtime.
   
## Static
	
	Can access API from underline classes by using two features of C++ : Mixing Inheritance and Perfect forwarding.
	By using template and concept we perfect forwarding args from each class that is part of the inheritance for the new object.
	The downside is that this technique could lead for larger binaries because of the generation of new classes via Templates.

## Functional