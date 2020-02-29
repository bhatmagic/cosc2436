/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Main source file
Notes: none.
Date: 2020.02.28 - Changed output for better readability
      2018.11.26
      2018.11.23
Completed: 2018.11.27
************************************************************************ */
#include "main.h"
#include "hash.h"
#include "functions.h"

int main(int argc, char **argv) {

    // ===
    // === Validate arguments
    // ===
    if (argc != 2) {
        std::cout << "[*] Hash Table" << std::endl;
        std::cout << "[*] Usage:    : argv[1] <data.csv>" << std::endl;
        return 0;
    }
    // Initialize dataFile from argv[1]
    std::string dataFile = argv[1];
    // Check if file exists
    if (!test(dataFile)) { return 0; }

    // ===
    // === Create hash object & table
    // ===
    std::cout << "Creating Object and Table" << std::endl;
    std::cout << "=========================" << std::endl;
    HashTable hashObj;
    std::cout << "Created hash object" << std::endl;
    createHashTable(&hashObj, dataFile);
    std::cout << "Created hash table with " << dataFile << std::endl;

    // ===
    // === [TEST] Traversing Hash Table
    // ===
    std::cout << std::endl;
    std::cout << "[TEST] Traverse Method" << std::endl;
    std::cout << "======================" << std::endl;
    // Traverse table
    std::cout << "obj.traverse()" << std::endl;
    std::cout << "----------------------" << std::endl;
    hashObj.traverse();
    // Print accessors
    std::cout << "----------------------" << std::endl;
    std::cout << "obj.getNumberOfEntries(): "
              << hashObj.getNumberOfEntries() << std::endl;
    std::cout << "obj.isEmpty()   : ";
    hashObj.isEmpty() ? std::cout << "Yes\n" : std::cout << "No\n";
    std::cout << "obj.getData(131): " << hashObj.getData(131) << std::endl;
    std::cout << "obj.getData(117): " << hashObj.getData(117) << std::endl;

    // ===
    // === [TEST] Contains method with a set of keys
    // ===
    int testKeysArr[] = {100, 108, 117, 129, 157, 205, 155, 131, 156,
                         195, 115, 208, 132, 1, 2, 3, 4, 5, 6};
    std::cout << std::endl;
    std::cout << "[TEST] Contains Method" << std::endl;
    std::cout << "======================" << std::endl;
    // Print keys in testKeysArr
    std::cout << "obj.contains(KEY) : ";
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        std::cout << std::setw(3) << testKeysArr[i] << SPACE;
    };
    std::cout << std::endl;
    // Print yes/no based off return from contains method
    std::cout << "Boolean Return    : ";
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        hashObj.contains(testKeysArr[i]) ?
            std::cout << std::setw(3) << "Yes" << SPACE
            : std::cout << std::setw(3) << "No" << SPACE;
    };
    std::cout<<std::endl;

    // ===
    // === [TEST] Removing nodes
    // ===
    std::cout << std::endl;
    std::cout << "[TEST] Remove Method" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "obj.remove(117): ";
    // Remove random nodes
    hashObj.remove(117) ? std::cout << "Removed\n"
                        : std::cout << "No existing key\n";
    std::cout << "obj.remove(195): ";
    hashObj.remove(195) ? std::cout << "Removed\n"
                        : std::cout << "No existing key\n";
    std::cout<<"obj.remove(54) : ";
    hashObj.remove(54) ? std::cout << "Removed\n"
                       : std::cout << "No existing key\n";
    std::cout << "obj.remove(6)  : ";
    hashObj.remove(6) ? std::cout << "Removed\n"
                      : std::cout << "No existing key\n";
    // Traverse table
    std::cout << "----------------------" << std::endl;
    std::cout << "obj.traverse()" << std::endl;
    hashObj.traverse();
    // Print accessors
    std::cout << "----------------------" << std::endl;
    std::cout << "obj.getNumberOfEntries(): "
              << hashObj.getNumberOfEntries() << std::endl;
    std::cout << "obj.isEmpty()   : ";
    hashObj.isEmpty() ? std::cout << "Yes\n" : std::cout << "No\n";
    std::cout << "obj.getData(131): " << hashObj.getData(131) << std::endl;
    std::cout << "obj.getData(117): " << hashObj.getData(117) << std::endl;

    // ===
    // === [TEST] Clear hash object
    // ===
    std::cout << std::endl;
    std::cout << "[TEST] Clear Method" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "obj.clear(): ";
    hashObj.clear() ? std::cout << "cleared\n" : std::cout << "NOT cleared.\n";
    // Print accessors
    std::cout << "-------------------" << std::endl;
    std::cout << "obj.getNumberOfEntries(): "
              << hashObj.getNumberOfEntries() << std::endl;
    std::cout << "obj.isEmpty()   : ";
    hashObj.isEmpty() ? std::cout << "Yes\n" : std::cout << "No\n";
    std::cout << "obj.getData(131): " << hashObj.getData(131) << std::endl;
    std::cout << "obj.getData(117): " << hashObj.getData(117) << std::endl;
    std::cout << "obj.traverse()  : ";
    hashObj.traverse() ? std::cout << "Shouldn't Be Here\n"
                         : std::cout << "No existing table\n";

    // ===
    // === End Program
    // ===
    std::cout << std::endl;
    std::cout<<"This is the end of the program." << std::endl;
    return 0;
}

