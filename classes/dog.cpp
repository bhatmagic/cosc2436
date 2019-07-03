/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Dog object definitions
Notes: none
Completed: 2018.09.01
************************************************************************ */
#include "dog.h"

//===================
//=== Constructor ===
//===================
/*
 * Purpose  : Assign dog's AKC registration
 * Called by: main.cpp.
 * Calls    : setIsAKC.
 * Returns  : none.
 * Notes    : none.
 */
dog::dog() {
    setIsAKC(false);
}

//==============================
//=== Constructor - Overload ===
//==============================
/*
 * Purpose  : Assign pet's name, age, & AKC.
 * Called by: main.cpp.
 * Calls    : pet::setName, pet::setAge, dog::setIsAKC.
 * Returns  : none.
 * Notes    : none.
 */
dog::dog(string name, int age, bool akc) {
    //use your own setters!
    setName(std::move(name));
    setAge(age);
    setIsAKC(akc);
}

//============
//=== Bark ===
//============
/*
 * Purpose  : Displays message.
 * Called by: functions.cpp.
 * Calls    : pet::getName().
 * Returns  : string.
 * Notes    : none.
 */
string dog::bark() {
    return (pet::getName() + " has barked.");
}

//==================
//=== Get Is AKC ===
//==================
/*
 * Purpose  : Returns dog's AKC registration.
 * Called by: functions.cpp.
 * Calls    : none.
 * Returns  : bool.
 * Notes    : none.
 */
bool dog::getIsAKC() {
    return (isAKC);
}

//=========================
//=== Set Favorite Food ===
//=========================
/*
 * Purpose  : Sets dog's AKC to object's private
 * Called by: dog::dog()
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void dog::setIsAKC(bool akc) {
    this->isAKC = akc;
}
