/* ************************************************************************
Name: David Boyd
Assignment: 01, PetClass
Purpose: Header for cat object
Notes: none
Completed: 2018.09.01
************************************************************************ */
#ifndef PET_CAT_H
#define PET_CAT_H

#include "pet.h"

// Cat inheritance from pet
class cat : public pet {

private:

    //private variables that define a cat from just a pet
    string _favFood;

public:

    // Constructors & Destructor
    cat();
    cat(string, int, string);
    //~cat();   // Not used

    // Methods
    string getFavFood();
    string meow();   // Displays string
    void setFavFood(string);

};

#endif //PET_CAT_H
