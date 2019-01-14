/* ************************************************************************
Name: David Boyd
Assignment: 02, Weather App
Purpose: Header for main
Notes: This program reads data from a file into a series of arrays then
     : transposes them.
Completed: 2018.09.12
************************************************************************ */
#ifndef WEATHERDATA_MAIN_H
#define WEATHERDATA_MAIN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>

using namespace std;

// Global variables
const int MAX_CITIES = 32;  // max length of array
const int TEMP_COL = 3;
const int CITY_LEN = 15;    // max length of string city name
const int AVG_TEMPS = 2;    // column used for average temps

// Prototypes
string matchTempToCity(string*, int);
void printCityValue  (string, bool, int);
void printData       (string*, int, int[][TEMP_COL]);
void printTransCities(string*, int );
void printTransData  (string*, int, int[][MAX_CITIES]);
void printTransTemps (int, int[][MAX_CITIES]);
int readFile         (string, string*, int[][TEMP_COL]);
void sortAvg         (string*, int, int[][TEMP_COL]);
void testMainParams  (int, char**);   // Learner's note: char** == char* argv[]
void transposeData   (int, int[][TEMP_COL], int[][MAX_CITIES]);
int  searchAvgTemp   (int*, int, int);
bool validateSearchValue(int);

#endif //WEATHERDATA_MAIN_H