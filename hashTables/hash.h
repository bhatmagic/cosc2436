/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Hash definitions file
Notes: none.
Date: 2018.11.23
      2018.11.26
Completed: 2018.11.27
************************************************************************ */
#ifndef HASHME29_HASH_H
#define HASHME29_HASH_H

#include "main.h"

/* Dictionary Node */
struct Dictionary {
    int key;
    std::string data;
    Dictionary* next;
    Dictionary* previous;
};

/* Class HashTable Declaration */
class HashTable {

private:

    Dictionary **_hTable;
    int _size = TABLE_SIZE;
    int _count;

    void _visit (Dictionary*);
    int _hash(int key) { return (key % _size); };

public:

    HashTable();
    ~HashTable() { delete _hTable; };

    bool add(int, std::string);
    bool clear();
    bool contains (int);
    int getNumberOfEntries() { return _count; };
    std::string getData(int);
    bool isEmpty() { return _count == 0; };
    bool remove(int);
    bool traverse();
};
#endif //HASHME29_HASH_H
