#ifndef WEIGHTED_QUADGRAPH_HPP
#define WEIGHTED_QUADGRAPH_HPP

#include <iostream>
#include <vector>
#include <string>
#include "../Dot/Dot.hpp"
using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    Dot destination;
    int weight;
    string destinationValue;
};

// Weighted Quadgraph class
class WeightedQuadgraph
{
private:
    int x;
    int y;

    std::vector<std::vector<std::vector<Edge>>> adjacencyList;

public:
    // Constructor
    WeightedQuadgraph(int x, int y);
    WeightedQuadgraph(){};

    // Add an edge to the graph
    void addEdge(Dot source, Dot destination, string destinationValue, int weight);

    vector<Edge> getEdges(int x, int y);
    // Print the graph
    void printGraph();
};

#endif // WEIGHTED_QUADGRAPH_HPP
