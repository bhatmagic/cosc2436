/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Main source file
Notes: none.
Date: 2018.11.23
      2018.11.26
Completed: 2018.11.27
************************************************************************ */
#include "main.h"
#include "hash.h"
#include "functions.h"

int main(int argc, char **argv) {

    // Check argument count
    if (argc != 2) {
        std::cout << "[*] Hash Table" << std::endl;
        std::cout << "[*] Usage:    : argv[2] <data.csv>" << std::endl;
        return 0;
    }

    // initialize dataFile to filename
    std::string dataFile = argv[1];

    // Check if file exists
    if (!test(dataFile)) { return 0; }

    // create hash object & table
    std::cout<<"\nCreating Object\n";
    HashTable hashObj;
    std::cout<<"createHashTable\n";
    createHashTable(&hashObj, dataFile);
    std::cout<<"HashTable created\n";

    std::cout<<"traverse():\n";
    hashObj.traverse();
    std::cout << "getNumberOfEntries:"
              << SPACE << hashObj.getNumberOfEntries() << std::endl;
    std::cout<<"isEmpty():"<<SPACE;
    hashObj.isEmpty() ? std::cout<<"Yes\n" : std::cout<<"No\n";

    // display array, contains
    int arr[] = {100, 108, 117, 129, 157, 205, 155, 131, 156,
                 195, 115, 208, 132, 1, 2, 3, 4, 5, 6};
    std::cout<<"\ncontains(arr[]):\n----------------------------------\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        std::cout<<std::setw(3)<<arr[i]<<SPACE;};
    std::cout<<std::endl;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashObj.contains(arr[i]) ? std::cout<<std::setw(3)<<"Yes"<<SPACE
                                 : std::cout<<std::setw(3)<<"No"<<SPACE;}
    std::cout<<std::endl;

    // Remove nodes
    std::cout<<"\nremove(117):"<<SPACE;
    hashObj.remove(117) ? std::cout<<"Yes\n" : std::cout<<"Nope\n";
    std::cout<<"remove(54):"<<SPACE;
    hashObj.remove(54) ? std::cout<<"Yes\n" : std::cout<<"Nope\n";
    std::cout<<"remove(195):"<<SPACE;
    hashObj.remove(195) ? std::cout<<"Yes\n" : std::cout<<"Nope\n";
    std::cout<<"remove(6):"<<SPACE;
    hashObj.remove(6) ? std::cout<<"Yes\n" : std::cout<<"Nope\n";
    hashObj.traverse();
    std::cout << "getNumberOfEntries:"
              << SPACE << hashObj.getNumberOfEntries() << std::endl;


    std::cout<<"getData(131):" << SPACE << hashObj.getData(131);

    std::cout<<std::endl;
    std::cout<<"clear():"<<SPACE;
    hashObj.clear() ? std::cout<<"Yes.\n" : std::cout<<"NOT cleared.\n";

    std::cout << "getNumberOfEntries: "
              << hashObj.getNumberOfEntries() << std::endl;

    std::cout<<"traverse(): <post-clear>"<<SPACE;
    hashObj.traverse() ? std::cout<<"Fu duq?\n" : std::cout<<"Nope\n";



    std::cout<<"This is the end of the program." << std::endl;
    return 0;
}
