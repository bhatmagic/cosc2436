/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Header for main
Notes: none
Completed: 2018.09.01
************************************************************************ */
#ifndef PETS_MAIN_H
#define PETS_MAIN_H

#include <iostream>
#include <string>
#include "pet.h"
#include "dog.h"
#include "cat.h"

using namespace std;

// function prototypes
void displayPet(pet&);
void displayDog(dog*);
void displayCat(cat*);

#endif //PET_MAIN_H
