/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Header for dog object
Notes: none
Completed: 2018.09.01
************************************************************************ */
#ifndef PET_DOG_H
#define PET_DOG_H

#include "pet.h"

// Dog class inherits pet class
class dog : public pet {

private:

	//private variables that define a dog (from a pet)
	bool isAKC; // AKC stands for American Kennel Club

public:

	// Constructors & Destructor
	dog();
	dog(string, int, bool);
	// ~dog(); // Not used.

	// Methods
	string bark(); 		// displays message
	bool getIsAKC();
	void setIsAKC(bool);

};

#endif //PET_DOG_H