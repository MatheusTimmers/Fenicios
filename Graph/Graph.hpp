#ifndef WEIGHTED_QUADGRAPH_HPP
#define WEIGHTED_QUADGRAPH_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Dot
{
    int x, y;
};

// Structure to represent an edge in the graph
struct Edge
{
    Dot destination;
    int weight;
    char destinationValue;
};

// Weighted Quadgraph class
class WeightedQuadgraph
{
    private:
        int x;
        int y;

        vector<vector<vector<Edge>>> adjacencyList;

    public:
        // Constructor
        WeightedQuadgraph(int x, int y);
        WeightedQuadgraph(){};

        // Add an edge to the graph
        void addEdge(Dot source, Dot destination, char destinationValue, int weight);

    vector<Edge> getEdges(int x, int y);
    // Print the graph
    void printGraph();
};

#endif // WEIGHTED_QUADGRAPH_HPP
