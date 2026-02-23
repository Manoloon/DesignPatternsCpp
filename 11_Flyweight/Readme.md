## FlyWeight
# Flyweight Coding Exercise
* You are given a class called Sentence , which takes a string such as "hello world". You need to provide an interface such that the indexer (operator [] ) returns a WordToken  that can be used to capitalize a particular word in the sentence.

* Typical use would be something like:

Sentence sentence("hello world");
sentence[1].capitalize = true;
cout << sentence.str(); // prints "hello WORLD"


