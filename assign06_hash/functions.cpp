/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Functions definitions file 
Notes: none.
Date: 2018.11.23
      2018.11.26
Completed: 2018.11.27
************************************************************************ */
#include "functions.h"


//=========================
//=== Create Hash Table ===
//=========================
void createHashTable(HashTable* table, std::string filename) {

    std::ifstream myFile;
    int key;
    char comma;
    std::string data;

    myFile.open(filename);

    while (!myFile.eof()) {
        myFile >> key >> comma >> data;
        table->add(key, data);
    }

    myFile.close();
}

//==========================
//=== Display File Error ===
//==========================
void displayFileError(bool fileExists) {
    if (!fileExists) { std::cout<<"\nCan't find the file!\n"; }
}

//=======================
//=== Test File Exist ===
//=======================
bool test(std::string filename) {
    std::ifstream inFile(filename);
    displayFileError(!inFile.fail());
    inFile.close();
    return (!(inFile.fail()));
}
