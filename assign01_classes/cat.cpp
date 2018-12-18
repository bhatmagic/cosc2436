/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Cat object definitions
Notes: none
Completed: 2018.09.01
************************************************************************ */
#include "cat.h"

//===================
//=== Constructor ===
//===================
/*
 * Purpose  : Assign cat's favorite food.
 * Called by: main.cpp.
 * Calls    : setFavFood.
 * Returns  : none.
 * Notes    : none.
 */
cat::cat() {
	setFavFood("");
}

//==============================
//=== Constructor - Overload ===
//==============================
/*
 * Purpose  : Assign pet's name,age, & favorite food.
 * Called by: main.cpp.
 * Calls    : pet::setName, pet::setAge, cat::setFavFood.
 * Returns  : none.
 * Notes    : none.
 */
cat::cat(string name, int age, string favFood) {
	setName(std::move(name));
	setAge(age);
	setFavFood(std::move(favFood));
}

//=========================
//=== Get Favorite Food ===
//=========================
/*
 * Purpose  : Returns cat's favorite food.
 * Called by: meow.
 * Calls    : none.
 * Returns  : string.
 * Notes    : none.
 */
string cat::getFavFood() {
	return _favFood;
}

//============
//=== Meow ===
//============
/*
 * Purpose  : Displays message.
 * Called by: functions.cpp.
 * Calls    : pet::getName(), cat::getFavFood.
 * Returns  : string.
 * Notes    : none.
 */
string cat::meow(){
	return pet::getName() + " wants " + getFavFood();

}

//=========================
//=== Set Favorite Food ===
//=========================
/*
 * Purpose  : Sets cat's favorite food to objects favFood
 * Called by: cat::cat()
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void cat::setFavFood(string favFood) {
	(favFood.empty()) ? (this->_favFood = "food") : (this->_favFood = favFood);
}