Pet Classes
############
:Author: David Boyd
:Date: Fall 2018
:Status: COMPLETE

This program demonstrates class inheritance through shared Pet traits.

The "pet" class that contains the following private attributes:

	- a string to hold the pet's name ( String or char[ ] )
	- an integer to hold the pet's age

The following methods:

	- public setters and getters for those attributes

A dog class inherits from the pet class and adds the following:

	- a boolean if the dog is AKC registered
	- setters and getters for that boolean
	- a constructor that requires you to set that boolean attribute upon object creation (you must use your own setter for this)
	- a public method called "bark" that when called will print the dogs name and "has barked." e.g. "Fido has barked."

A cat class that inherits from the pet class and adds the following:

	- a string to hold the cat's favorite food ( String or char[ ] )
	- a setter and getter for that string
	- a constructor that allows but does not require you to set that string attribute upon object creation (you must use your own setter for this)
	- a public method called "meow" that when called will print the cat's name and "wants" it's favorite food. e.g. "Daisy wants fish." If there is no favorite food in the object (i.e. the favorite food string is empty) then it should print "... wants food." e.g. "Daisy wants food."

Requirements

    - Procedures (functions) are placed in a file called 'functions.cpp'.
    - Place each class is in its own '.cpp' with it's own '.h'.
        - pet.cpp, pet.h
        - dog.cpp, dog.h
        - cat.cpp, cat.h
