#ifndef WEIGHTED_QUADGRAPH_HPP
#define WEIGHTED_QUADGRAPH_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int destination;
    int weight;
    string destinationValue;
};

// Weighted Quadgraph class
class WeightedQuadgraph
{
private:
    int numVertices;
    std::vector<std::vector<Edge>> adjacencyList;

public:
    // Constructor
    WeightedQuadgraph(int numVertices);
    WeightedQuadgraph(){};

    // Add an edge to the graph
    void addEdge(int source, int destination, string destinationValue, int weight);

    // Print the graph
    void printGraph();
};

#endif // WEIGHTED_QUADGRAPH_HPP
