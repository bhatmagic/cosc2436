Hash Table
##########
:Author: David Boyd
:Date: Fall 2018

**hashTable** demonstrates a dictionary object using a hash map data structure
with a doubly chained list to prevent collisions.

Summary
=======

Dictionary Object
-----------------

The Dictionary object contains a hash table (an array of pointers to the
structs)

The dictionary object implements the following standard methods:

	- isEmpty(): boolean
	- getNumberOfEntries(): integer
	- add(searchKey: KeyType, newValue: ValueType): boolean
	- remove(targetKey: KeyType): boolean
	- clear():void
	- getValue(targetKey: KeyType): ValueType
	- contains(targetKey: KeyType): boolean
	- traverse(visit(value: ValueType): void): void

Structs
-------

The structs are created *outside* the object and a pointer to the struct is
passed into the Dictionary for storage in the Hash Table.  Note: this is a
different definition than shown in the bullet points above.

Entries
-------

The **id** is passed in to locate the position for the existence of an entry
when you want to retrieve, delete, or test in the hash table.

Design
------

	- The hash table array is set to be size 19
	- Implements the modulo method as a hashing function

Test
----

	- The object is instantiated, reads in data.csv, and adds all the entries
	  into the table when the program starts.
	- main.cpp demonstrates all hash table funtionality including collisions.
	- Demonstrates deletion of an entry in a location of a previous attempted
	  collision.
	- Demonstrates the full funtionality of the program and all the methods.

How to Run
==========

Running using UNIX-base CLI:

.. code-block :: Bash

	# compile program
	g++ -o main *.cpp

	# csv file parameter required
	./main data.csv

