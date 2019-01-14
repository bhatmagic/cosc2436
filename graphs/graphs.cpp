/* ************************************************************************
Name: David Boyd
Assignment: 07_Graphs
Purpose: Graphs object definition
Notes: n/a
Date: 2018.12.05
************************************************************************ */

#include "graphs.h"

//===========================
//=== Add Undirected Edge ===
//===========================
void graphs::add_direct_edge(int start_node, int goal_node, int weight)
{
    // Insert directed edge between start_node and goal_node with given weight
    _adjGraph[start_node].push_back(std::make_pair(goal_node, weight));
}

//===========================
//=== Add Undirected Edge ===
//===========================
void graphs::add_undirected_edge(char node1, char node2, int weight)
{
    // Get the node as integer scale from 0 to 25
    int first_node = (node1 - 'a');
    int second_node = (node2 - 'a');

    // Insert edge between node 1 and node 2 with given weight
    _adjGraph[first_node].push_back(std::make_pair(second_node, weight));

    // Insert edge between node 2 and node 1 with given weight
    _adjGraph[second_node].push_back(std::make_pair(first_node, weight));
}

//============================
//=== Breadth First Search ===
//============================
void graphs::bfs(char root_Alpha)
{
    // Get the node as integer scale from 0 to 25
    int start = root_Alpha - 'a';

    // Boolean array to avoid multiple node visits.
    bool vis[_MAX_CHAR] = {false}; //list initializer

    // Push start node in queue
    vis[start] = true;
    std::queue<int>q;
    q.push(start);

    std::cout << root_Alpha << SPACE;

    // While unvisited nodes exist
    while (!q.empty()) {
        // Pop the node from queue
        int parent = q.front();
        q.pop();

        // For each child of this node
        for (auto &i : _adjGraph[parent]) {
            int child = i.first;

            // Check if if not visited through boolean array
            if (!vis[child]) {
                vis[child] = true; // mark it as visit
                auto current_node = static_cast<char>('a' + child);
                std::cout << POINTER << SPACE << current_node << SPACE;

                // Put next node in queue
                q.push(child);
            } // end if
        } // end for
    } // end while
}

//===================
//=== Constructor ===
//===================
graphs::graphs() {
    // Creates a vector of vector of pairs for 26 characters
    _adjGraph.vector::assign((unsigned long) _SIZE, std::vector<std::pair<int,int>>());
}

//==========================
//=== Depth First Search ===
//==========================
void graphs::dfs(int parent, bool* visit) // boolean array tracks visited nodes
{
    // Check if node has been visited
    if (visit[parent]) {
        return;
    }
    visit[parent] = true;  // Mark as visited
    auto current_node = static_cast<char>('a' + parent);
    std::cout << current_node;

    // for each child of this node
    for (auto &i : _adjGraph[parent]) {
        int child = i.first;
        // int weight = i.second;

        // Check if visited through boolean array
        if (!visit[child]) {
            std::cout << SPACE << POINTER << SPACE;

            // Recursive DFS with next node
            dfs(child, visit);
        } // end if
    } // end for
}

//=====================
//=== Shortest Path ===
//=====================
void graphs::shortest_path(int start_node) {

    // Make a Priority queue to the minimum cost every time.
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int> >, std::greater<> >pq;

    // Initialize the shortest distance to every node as big value
    int distance[_MAX_DISTANCE] = {_MAX_PATH, _MAX_PATH, _MAX_PATH, _MAX_PATH, _MAX_PATH, _MAX_PATH, _MAX_PATH};

    // Make a parent for each node as -1
    int parent_path[_MAX_DISTANCE] = { -1,-1,-1,-1,-1,-1,-1 };

    // Push the start node to priority queue
    distance[start_node] = 0;
    pq.push(std::make_pair(0, start_node));
    while (!pq.empty()) {

        // Pop the top node from Priority queue
        int parent = pq.top().second;
        int parent_cost = pq.top().first;
        pq.pop();

        // For each child of this node
        for (auto &i : _adjGraph[parent]) {
            int child = i.first;
            int child_cost = i.second;
            int total_cost = parent_cost + child_cost;

            // Check if whether's if visit the next node using this path make it shortest path
            if (distance[child] > total_cost) {
                distance[child] = total_cost;

                // Push the next node and the cost so far to Priority queue
                pq.push(std::make_pair(total_cost, child));

                // Mark the parent of this next node as it's parent
                parent_path[child] = parent;
            } // end if
        } // end for
    } // end while

    for (int current_node = 0; current_node < _MAX_DISTANCE; ++current_node) {

        // If there's no path
        if (distance[current_node] == _MAX_PATH) {
            std::cout << "\nShortest Path From Start Node" << SPACE
                      << start_node << SPACE << "To Node"  << SPACE
                      << current_node;
            std::cout << "\n\tPath does not exist\n";
        }

        // If current to equal the given node
        else if (current_node != start_node) {

            // Get the path using parent
            std::cout << "\nShortest Path From Start Node" << SPACE
                      << start_node << SPACE << "To Node"  << SPACE
                      << current_node;
            std::vector<int>path;

            // Start from the this node then recursively go to it's parent until start node
            path.push_back(current_node);
            int cur = parent_path[current_node];
            while (cur != -1) {
                path.push_back(cur);
                cur = parent_path[cur];
            }

            // Reverse the path to get the path from start node to current node
            reverse(path.begin(), path.end());

            // Display the path
            std::cout << "\n\tNode" << SPACE << start_node << SPACE;
            for (int i = 1; i < path.size(); ++i) {
                std::cout << POINTER << SPACE << "Node" << SPACE << path[i];
            }

            std::cout <<"\n\tTotal weight =" << SPACE << distance[current_node] << "\n";
        } // end else if
    } // end for
}