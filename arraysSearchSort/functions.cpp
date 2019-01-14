/* ************************************************************************
Name: David Boyd
Assignment: 02, Weather App
Purpose: Functions definitions
Notes: none.
Completed: 2018.09.12
************************************************************************ */
#include "main.h"

//==========================
//=== Match Temp to City ===
//==========================
/*
 * Purpose  : Matches the found temp value to its city.
 * Called by: main.cpp
 * Calls    : none.
 * Returns  : string.
 * Notes    : Returns city name.
 */
string matchTempToCity(string* cities, int position) {

    return cities[position];
}

//==========================
//=== Print City's Value ===
//==========================
/*
 * Purpose  : Displays found temp to its city.
 * Called by: main.cpp
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void printCityValue(string valueCity, bool found, int srchValue) {

    // Declare variables
    int dashSize = CITY_LEN;

    if (found == 1) {
        cout << "Search Results" << endl;
        cout << string(static_cast<unsigned long>(dashSize), '-') << endl;
        cout << srchValue << ": " << valueCity;
    }
}

//==================
//=== Print Data ===
//==================
/*
 * Purpose  : Displays stored data in arrays.
 * Called by: main.cpp
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void printData(string *cities, int numCities, int temps[][TEMP_COL]) {

    // Display column label
    cout << left << setw(CITY_LEN) << "City"
         << setw(10) << "High Temp"
         << setw(10) << " Low Temp"
         << setw(10) << " Avg Temp" << endl;
    cout << "--------------------------------------------" << endl;

    // Traverse through cities and temps
    for (int i = 0; i < numCities; i++) {
        cout << left << setw(CITY_LEN) << cities[i];
        for (int j = 0; j < TEMP_COL; j++) {
            cout << right << setw(9) << temps[i][j];
        }
        cout << endl;
    }
}

//=============================
//=== Print Transposed Data ===
//=============================
/*
 * Purpose  : Displays transposed stored data.
 * Called by: main.cpp.
 * Calls    : printTransCities, printTransTemps.
 * Returns  : none.
 * Notes    : none.
 */
void printTransData(string cities[], int numCities, int transTemps[][MAX_CITIES]) {

    // Print both cities and transposed temps array
    printTransCities(cities, numCities);
    printTransTemps(numCities, transTemps);
}

//================================
//==== Print Transposed Cities ===
//================================
/*
 * Purpose  : Displays transposed cities array.
 * Called by: printTransData.
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void printTransCities(string* cities, int numCities) {

    // Declare variables
    int dashSize = numCities * CITY_LEN;

    // Displays row of cities
    for (int i=0; i<numCities; i++) {
        cout << left << setw(CITY_LEN) << cities[i];
    }
    // Displays '-' to the length of cities
    cout << endl << string(static_cast<unsigned long>(dashSize), '-') << endl;
}
//==============================
//=== Print Transposed Temps ===
//==============================
/*
 * Purpose  : Displays transposed temps array.
 * Called by: printTransData.
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void printTransTemps(int numCities, int transTemps[][MAX_CITIES]) {

    // Iterate through column by row
    for(int i = 0; i < TEMP_COL; ++i) {
        for (int j = 0; j < numCities; ++j) {
            cout << left << setw(CITY_LEN) << transTemps[i][j];

            // Single space rows
            if (j == numCities - 1)
                cout << endl; // << endl; //double-spaced
        }
    }
}

//=================
//=== Read File ===
//=================
/*
 * Purpose  : Reads and stores data from file.
 * Called by: main.cpp
 * Calls    : none.
 * Returns  : int.
 * Notes    : Creates an array of city names,
 *          : creates a 2d array of temps (row=tempType, col=city)
 *          : Returns number of cities.
 */
int readFile(string filename, string cities[], int temps[][TEMP_COL]) {

    // Declare variables
    ifstream myFile(filename);
    string strHigh;
    string strLow;
    string strAvg;
    int row=0;

    if (!myFile.is_open()) {
        cout << "Unable to open file." << endl;
    }

        while (myFile.good() && (myFile.peek() != '\n') ) {

            // Read lines from file and assign cities to cities[]
            getline(myFile, cities[row], ',');
            getline(myFile, strHigh, ',');
            getline(myFile, strLow, ',');
            getline(myFile, strAvg, '\n');

            // Convert string to int and assign temps[] (high, low, avg)
            temps[row][0] = stoi(strHigh);
            temps[row][1] = stoi(strLow);
            temps[row][2] = stoi(strAvg);

            row++;
            }

    // Close file
    myFile.close();

    return row;
}

//============================
//=== Search Average Temps ===
//============================
/*
 * Purpose  : Searches temps array for value.
 * Called by: printTransData.
 * Calls    : none.
 * Returns  : int.
 * Notes    : Binary search and returns position[index].
 */
int searchAvgTemp(int *transTemps, int numCities, int value) {

    // Declare variables
    int first = 0,
            last  = numCities -1,
            middle,
            position = -1;
    bool found = false;

    // Binary search for item in tranTemp[AVG_TEMPS]
    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (transTemps[middle] == value) {
            found = true;
            position = middle;
        } else if (transTemps[middle] > value) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }

    return position;
}

//=====================
//=== Sort Averages ===
//=====================
/*
 * Purpose  : Sorts city and temps by ascending average temps order.
 * Called by: main.cpp.
 * Calls    : none.
 * Returns  : none.
 * Notes    : Traverses through cities' row, assigns each data a temporary var,
 *          : then compares avg temp to next row's avg temp, and swaps accordingly.
 */
void sortAvg(string cities[], int numCities, int temps[][TEMP_COL]) {

    bool   madeAswap;
    string transCity;
    int    transHigh,
           transLow,
           transAvg,
           highCol = 0,
           lowCol  = 1,
           avgCol  = 2;

    do // while swap == true;
    {   madeAswap = false;
        for (int row = 0; row < (numCities-1); row++)
        {
            if (temps[row][avgCol] > temps[row + 1][avgCol]) {

                // Assign temporary variables
                transCity = cities[row];
                transHigh = temps[row][highCol];
                transLow  = temps[row][lowCol];
                transAvg  = temps[row][avgCol];

                // Swap the contents of cities[row] and cities[row +1]
                // Swap the contents of temp[row][col] and temp[row + 1][col]
                cities[row] = cities[row + 1];
                temps[row][highCol] = temps[row+1][avgCol];
                temps[row][lowCol] = temps[row+1][lowCol];
                temps[row][avgCol] = temps[row + 1][avgCol];

                // Set new row minimum
                cities[row + 1] = transCity;
                temps[row + 1][highCol] = transHigh;
                temps[row + 1][lowCol] = transLow;
                temps[row + 1][avgCol] = transAvg;

                madeAswap = true;
            }
        }
    } while (madeAswap); // Loop again if a swap occurred.
}

//==============================
//=== Test Main's Parameters ===
//==============================
/*
 * Purpose  : Display's command line's parameters from terminal
 * Called by: main.cpp
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void testMainParams(int argc, char* argv[]) {

    // Test main parameters
    cout << "============================" << endl;
    // Print the name of the executable
    cout << "The executable's name is: " << argv[0] << endl;

    // print parameters of executable
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            printf("Parameter %d = %s\n", i, argv[i]);
        }
    }
    cout << "============================\n" << endl;
}

//======================
//=== Transpose Data ===
//======================
/*
 * Purpose  : Transpose original temps into another array.
 * Called by: main.cpp.
 * Calls    : none.
 * Returns  : none.
 * Notes    : none.
 */
void transposeData(int numCities, int temps[][TEMP_COL],  int transTemps[][MAX_CITIES])
{
    // Finding transpose of matrix cities[][] and storing it in array transTemps[][].
    for (int i = 0; i < numCities; ++i)
        for (int j = 0; j < TEMP_COL; ++j) {
            transTemps[j][i] = temps[i][j];
        }
}

//=============================
//=== Validate Search Value ===
//=============================
/*
 * Purpose  : Validates if value was found.
 * Called by: main.cpp.
 * Calls    : none.
 * Returns  : bool.
 * Notes    : If false, display error.
 */
bool validateSearchValue(int position) {

    bool found = true;

    // Print !found error
    if (position == -1) {
        cout << "Temperature not found.";
        found = false;
    }

    return found;
}

