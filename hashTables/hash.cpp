/* ************************************************************************
Name: David Boyd
Assignment: 05, Binary Search Tree
Purpose: Hash definitions file
Notes: none.
Date: 2018.11.23
      2018.11.26
Completed: 2018.11.27
************************************************************************ */
#include "main.h"
#include "hash.h"

//===================
//=== Constructor ===
//===================
HashTable::HashTable() {
    _count = 0;
    _hTable = new Dictionary *[_size];

    for (int i = 0; i < _size; ++i){
        _hTable[i] = nullptr;
    }
}

//===========
//=== Add ===
//===========
bool HashTable::add(int key, std::string data){
    int hashBucket = _hash(key);
    Dictionary *temp, *current;

    temp = new Dictionary;
    current = _hTable[hashBucket];

    temp->key = key;
    temp->data = std::move(data);
    temp->next = nullptr;
    temp->previous = nullptr;


    // If bucket is empty
    if (!current){
        _hTable[hashBucket] = temp;
    } else{

        // Traverse linked list
        while(current->next) {
            current = current->next;
        }

        // Place node at available address
        current->next = temp;
        temp->previous = current;
    } // end else

    _count++;
    return true;
}

//=============
//=== Clear ===
//=============
bool HashTable::clear(){

    if (!_hTable) { return false; }

    Dictionary *current;

    // Traverse bucket
    for (int i = 0; i < _size; ++i) {
        current = _hTable[i];
        // Traverse linked list
        while (current) {
            Dictionary *temp = current;

            current = current->next;
            delete temp;
        }
    }
    _count = 0;
    //delete _hTable;
    return true;
}

//================
//=== Contains ===
//================
bool HashTable:: contains(int key){
    int hashCode;
    Dictionary *current;
    hashCode = _hash(key);

    current = _hTable[hashCode];

    while (current != nullptr){
        if (current->key == key) {
            return true;}
        current = current -> next;
    }
    return false;
}

//================
//=== Get Data ===
//================
std::string HashTable::getData(int key) {

    Dictionary *current;
    int hashBucket = _hash(key);

    current = _hTable[hashBucket];

    // Traverse linked list
    while (current != nullptr) {
        if (current->key == key) {
            return current->data;
        }
        current = current->next;
    } // end while

    return SPACE;
}

//==============
//=== Remove ===
//==============
bool HashTable::remove(int key) {

    int hashBucket = _hash(key);
    Dictionary *current = _hTable[hashBucket];

    while (current){
        if (current->key == key){

            if (_hTable[hashBucket] == current)
                _hTable[hashBucket] = current->next;

            if (current->next)
                current->next->previous = current->previous;

            if (current->previous)
                current->previous->next = current->next;

            delete current;
            _count--;
            return true;
        } else {
            current = current->next;
        } // end else
    } // while
    return false;
}

//================
//=== Traverse ===
//================
bool HashTable:: traverse() {

    if (isEmpty()) { return false; }

    // Traverse bucket
    for (int i = 0; i < _size; ++i) {
        std::cout << "[" << i << "]";
        // Traverse linked list
        _visit(_hTable[i]);
        std::cout << std::endl;
    }
    return true;
}

//==============
//=== _Visit ===
//==============
void HashTable::_visit(Dictionary* entry){

    if (!entry){ return; }

    std::cout << " -> " << "[" << entry->key << ", " << entry->data << "]";
    _visit(entry->next);
}
