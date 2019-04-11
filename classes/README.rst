Classes
#########################
:Author: David Boyd
:Date: Fall 2018
This program demonstrates class inheritance through shared Pet traits.


NOTE: attached to this assignment is the code for the example in class using rectangles and boxes.
Create a "pet" class that contains the following private attributes:
    - a string to hold the pet's name ( String or char[ ] )
    - an integer to hold the pet's age
Add the following methods:
    - public setters and getters for those attributes
Create a dog class that inherits from the pet class and adds the following private attribute:
    - a boolean if the dog is AKC registered
Add the following methods:
    - setters and getters for that boolean
    - a constructor that requires you to set that boolean attribute upon object creation (you must use your own setter for this)
    - a public method called "bark" that when called will print the dogs name and "has barked." e.g. "Fido has barked."
Create a cat class that inherits from the pet class and adds the following private attribute:
    - a string to hold the cat's favorite food ( String or char[ ] )
Add the following methods:
    - a setter and getter for that string
    - a constructor that allows but does not require you to set that string attribute upon object creation (you must use your own setter for this)
    - a public method called "meow" that when called will print the cat's name and "wants" it's favorite food. e.g. "Daisy wants fish." If there is no favorite food in the object (i.e. the favorite food string is empty) then it should print "... wants food." e.g. "Daisy wants food."
Create a main program that creates a dog class and a cat class and demonstrates they work completely. Your main program in this case is essentially a test program, testing your objects. You need to demonstrate you understand how to test all functionality of your objects. Anything your object can do, you need to show it can do it correctly. Anything your object can't do, you need to show it can't do it - gracefully.

Requirements
    - Conform to the Submission Guidelines.
    - Your main program is to be named 'main.cpp'.
    - If you need procedures (functions), place them in a file called 'functions.cpp'.
    - Your header for main.cpp (and functions.cpp) is to be named 'main.h'. All your general includes and other directives need to be in 'main.h'.
    - Place each class is in its own '.cpp' with it's own '.h'.
        ? pet.cpp, pet.h
        ? dog.cpp, dog.h
        ? cat.cpp, cat.h
BONUS (20 points - i.e. double your grade!): Submit this program BOTH through Blackboard as discussed here, AND through a code repository through Bit Bucket.
To do this you must initialize a git repository locally. Create an account and a repository on Bit Bucket. You MUST set your repository on Bit Bucket to private. Set your origin on your local repository. Push your code to your Bit Bucket repository. ONLY PUSH SOURCE CODE (.h, .cpp, and makefiles if you choose), not project files. Use git ignore to exclude project files.
Once your code is on Bit Bucket, email me and tell me you are ready to "turn in" your Bit Bucket repository, and I'll give you my Bit Bucket name to add me to your project.
We will go over this in class as well. So if you don't understand this now, you will have a chance to go back and do it later, but then it will only be worth 10 bonus points.
Remember, you must still submit normally through Blackboard even if you submit on Bit Bucket.

