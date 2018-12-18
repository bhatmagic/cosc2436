/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Main definitions
Notes: This program demonstrates the basic use of class and inheritance.
Completed: 2018.09.01
************************************************************************ */
#include "main.h"

int main() {

    // Tester variables
    string name = "Guts";
    int age = 7;
    bool isAKC = true;
    string catFood = "Fish";

    //creates a pet object with no parameters
    pet myPet1;
    //creates a pet object with name and _age
    pet myPet2("Goldie", age);

    //creates a dog object with no parameters
    dog myDog1;
    //creates a dog object with name, _age and AKC registration
    dog myDog2(name, age, isAKC);

    //creates a cat object with no parameters
    cat myCat1;
    //creates a cat object with name, _age, and favorite food
    cat myCat2("貓貓", age, catFood);

    displayPet(myPet1);
    displayPet(myPet2);

    displayDog(&myDog1);
    displayDog(&myDog2);

    displayCat(&myCat1);
    displayCat(&myCat2);

    return 0;
}
