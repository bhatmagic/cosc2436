/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Main definitions; displays pet object's values
Notes: none
Completed: 2018.09.01
************************************************************************ */
#include "main.h"

void displayPet(pet &myPet) {

	cout << "Pet Name: " << myPet.getName() << endl;
	cout << "Pet Age : " << myPet.getAge() << endl;
	cout << endl;
}

void displayDog(dog *myDog) {

	cout << "Dog Name: " << myDog->getName() << endl;
	cout << "Dog Age : " << myDog->getAge() << endl;
	cout << "AKC Reg : " <<
						 ( (myDog->getIsAKC()) ? ("Yes"):("No") )
						 << endl;
	cout << "Dog Bark: " << myDog->bark() << endl;
	cout << endl;
}

void displayCat(cat *myCat) {

	cout << "Cat Name: " << myCat->getName() << endl;
	cout << "Cat Age : " << myCat->getAge() << endl;
	cout << "Fav Food: " << myCat->meow() << endl;
	cout << endl;
}