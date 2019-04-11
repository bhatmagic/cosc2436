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

    std::cout << "[No arguments given]\n";
    displayPet(myPet1);
    std::cout << "[Arguments given]\n";
    displayPet(myPet2);

    std::cout << "[No arguments given]\n";
    displayDog(&myDog1);
    std::cout << "[Arguments given]\n";
    displayDog(&myDog2);

    std::cout << "[No arguments given]\n";
    displayCat(&myCat1);
    std::cout << "[Arguments given]\n";
    displayCat(&myCat2);

    return 0;
}
