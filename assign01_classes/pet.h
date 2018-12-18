/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Header for pet object
Notes: none
Completed: 2018.09.01
************************************************************************ */
#ifndef PETS_PET_H
#define PETS_PET_H

#include <string>
using namespace std;

class pet {

protected:

    // Private variables that define a pet
    string _name;
    int _age;

public:

	// Constructors & Destructor
	pet();
	pet(string name, int age);
	// ~pet();	// Not used.

	// Getters & Setters
	int getAge();
	string getName();
	void setAge(int);
	void setName(string);
};

#endif // PETS_PET_H