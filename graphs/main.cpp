/* ************************************************************************
Name: David Boyd
Assignment: 07_Graphs
Purpose: Main program
Notes: n/a
Date: 2018.12.05
************************************************************************ */
#include "graphs.h"

int main(int argc, char** argv) {

    std::cout << "\n==============";
    std::cout << "\n===Graph 1 ===";
    std::cout << "\n==============";

    char start = 'a';
    int  cost1[12] = { 2, 6, 4, 5, 1, 2, 3, 4, 1, 5, 3, 4 };
    char alpha1[12][2] = { {'a', 'b'}, {'a', 'd'}, {'a', 'c'}, {'b', 'c'},
                           {'c', 'd'}, {'c', 'e'}, {'d', 'f'}, {'d', 'h'},
                           {'e', 'f'}, {'e', 'g'}, {'e', 'i'}, {'f', 'g'} };

    // Add graph's edges from figure 20-36
    graphs firstGraph;
    for (int i=0; i<12; ++i) {
        firstGraph.add_undirected_edge(alpha1[i][0], alpha1[i][1], cost1[i]);
    }

    std::cout << "\nBFS:" << SPACE;
    firstGraph.bfs(start);


    // DFS from root node a
    std::cout << "\nDFS:" << SPACE;
    bool visited[26] = { false };
    firstGraph.dfs(0, visited);

    std::cout<<std::endl;

    std::cout << "\n==============";
    std::cout << "\n===Graph 2 ===";
    std::cout << "\n==============\n";

    int graph2[15][3] = { {0, 1, 2}, {0, 2, 4}, {0, 3, 6}, {1, 2, 5}, {1, 4, 3},
                          {2, 3, 2}, {2, 4, 2}, {3, 4, 5}, {3, 5, 3}, {3, 2 ,1},
                          {4, 2, 3}, {4, 5, 5}, {4, 6, 1}, {5, 4, 1}, {6, 5, 2} };

    // Add graph's edges from figure 20-39
    graphs secondGraph;
    for (auto &i : graph2) {
        for (int j = 0; j < 3; ++j) {
            secondGraph.add_direct_edge(i[0], i[1], i[2]);
        }
    }

    // Display shortest path from given node
    secondGraph.shortest_path(1);

    return 0;
}