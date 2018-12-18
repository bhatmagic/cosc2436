/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Pet object definition
Notes: none
Completed: 2018.09.01
************************************************************************ */
#include "pet.h"

//===================
//=== Constructor ===
//===================
/*
 * Purpose  : Sets pet's default name and age.
 * Called by: main.cpp.
 * Calls    : setName, setAge.
 * Returns  : none.
 * Notes    : n/a
 */
pet::pet() {
	setName("");
	setAge(0);
}

//==============================
//=== Constructor - Overload ===
//==============================
/*
 * Purpose  : Assign pet's name and age.
 * Called by: main.cpp.
 * Calls    : setName, setAge.
 * Returns  : none.
 * Notes    : Identical constructor declared with
 *          : different parameters in the same class.
 */
pet::pet(string name, int a) {
	setName(std::move(name));
	setAge(a);
}

//===================
//=== Get Age ===
//===================
/*
 * Purpose  : Returns age of pet
 * Called by: functions.cpp,
 * Calls    : none.
 * Returns  : int.
 * Notes    : none.
 */
int pet::getAge() {
	return _age;
}

//================
//=== Get Name ===
//================
/*
 * Purpose  : Returns name of pet
 * Called by: main.h.
 * Calls    : none.
 * Returns  : string.
 * Notes    : n/a
 */
string pet::getName() {
	return _name;
}

//===============
//=== Set Age ===
//===============
/*
 * Purpose  : Set's pet's age to object's private age
 * Called by: constructors[pet, cat, dog].
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void pet::setAge(int age) {
	(age > 0) ? (this->_age = age) : (this->_age = 0);
}

//================
//=== Set Name ===
//================
/*
 * Purpose  : Set's pet name to object's private name
 * Called by: constructors[pet, cat, dog].
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void pet::setName(string name) {
	(name.empty()) ? (this->_name = "No Name") : (this->_name = name);
}