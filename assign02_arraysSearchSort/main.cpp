/* ************************************************************************
Name: David Boyd
Assignment: 02, Weather App
Purpose: Main source file
Notes: trans = transposed.
Completed: 2018.09.12
************************************************************************ */
#include "main.h"

int main(int argc, char** argv)
{
    // Declare variables
    string cities[MAX_CITIES];
    string valueCity;
    int temps[MAX_CITIES][TEMP_COL];
    int transTemps[TEMP_COL][MAX_CITIES];
    int numCities;
    int searchValue = 81;
    int position;
    bool found;


    // Print main parameters
    testMainParams(argc, argv);

    // Read file and return number of cities
    numCities = readFile(argv[1], cities, temps);

    // Print original file arrays
    printData(cities, numCities, temps);
    cout << endl;

    // Sort Temperatures by Averages
    sortAvg(cities, numCities, temps);

    // Print sorted file arrays
    printData(cities, numCities, temps);
    cout << endl;

    // Transpose and store data into another array.
    transposeData(numCities, temps, transTemps);

    // Print transposed cities and array
    printTransData(cities, numCities, transTemps);

    // Search for avg temp, return col position, validate search
    position = searchAvgTemp(transTemps[AVG_TEMPS], numCities, searchValue);
    found = validateSearchValue(position);

    // Init matching city and print
    valueCity = matchTempToCity(cities, position);
    cout << endl;
    printCityValue(valueCity, found, searchValue);
    cout << endl;

    return 0;
}