/* ************************************************************************
Name: David Boyd
Assignment: 07_Graphs
Purpose: Graphs header for object
Notes: n/a
Date: 2018.12.05
************************************************************************ */

#ifndef ASSIGN07_GRAPHS_GRAPHS_H
#define ASSIGN07_GRAPHS_GRAPHS_H

#include <iostream>
#include <cstring>
#include <queue>      // used for vector
#include <utility>    // used for struct pair template::(a tuple with 2 elements)
#include <algorithm>  // used for reverse()

// Global Variables
const std::string SPACE = " ";
const std::string POINTER = "->";

class graphs{

private:

    // Initialize a graph of an adjacency matrix using pairs::(int edge, int weight)
    std::vector<std::vector<std::pair<int,int> > >_adjGraph;

    // maximum characters from 'a' to 'z'
    const int _MAX_CHAR = 26;
    const int _SIZE = _MAX_CHAR;
    const int _MAX_DISTANCE = 7;
    const int _MAX_PATH = 10000000;

public:

    graphs();

    void add_direct_edge(int, int, int);
    void add_undirected_edge(char, char, int);
    void bfs(char);  //Breadth first search
    void dfs(int,bool*); //Depth first search
    void shortest_path(int);
};
#endif //ASSIGN07_GRAPHS_GRAPHS_H
