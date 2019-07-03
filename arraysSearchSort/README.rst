Array Search & Sort
#####################
:Author: David Boyd
:Date: Fall 2018

This program imports city and temperature data from a file into arrays. Then transposes the array and finds temperatures.

Imported FIle Information
===========================

A single csv file with city and temperature information holds 6 cities and the high, low, and average temperatures for the year::

	Boston,94,-15,65
	Chicago,92,-21,72
	Atlanta,101,10,80
	Austin,107,19,81
	Phoenix,112,23,88
	Washington,88,-10,68

Input
======

This program requires the cities file as its argument.  From the command line::

	./main cities.csv

How it Works
=============

	1. Reads the file given from the command line and places the information in TWO different arrays. One 1-dimensional array of strings (or a 2D array of characters) and one 2-dimensional array of integers.

	2. Prints out the information from the arrays showing the file was read correctly.

	3. Sorts the 2D array of temperatures in order of average temperature. Sorts the whole row (i.e. does not move just the average column alone) and also sorts the array of city names along with it. In other words, the two arrays are parallel arrays.

	4. Prints out the information from the arrays showing the sort correctly.

	5. Rotates the 2D array of temperatures so that there are 3 rows and 6 columns with the rows being high temps, low tems, average temps in that order.

	6. Prints out a list of cities and average temperatures in order. Format your output so it is “neat.”

	7. Searches for the city with the average temperature of 81 and prints the city name for that average temperature. This uses a binary search. In other words, this will pass to a binary search function the 2D array of temperatures, the size of the array, and the search value 81, and it will return the column number, which will then be used to print the city name.

This program uses proper file and program modularity (i.e. header file(s), function calls, etc.).  Each of the steps above are called to a function from main. It passes the information you need to a function, then performs that task, and returns it. In other words, the main is relatively small and just calls each function: “read file,” “print arrays,” “sort arrays,” etc.
