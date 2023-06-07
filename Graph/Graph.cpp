#include "Graph.hpp"
#include <iostream>
using namespace std;

// Constructor
WeightedQuadgraph::WeightedQuadgraph(int numVertices)
{
    cout << "numVertices = " << numVertices << endl;
    this->numVertices = numVertices;
    adjacencyList.resize(numVertices);
}

// Add an edge to the graph
void WeightedQuadgraph::addEdge(int source, int destination, string destinationValue, int weight)
{
    cout << "addEdge(" << source << ", " << destination << ", " << weight << ")" << endl;
    Edge edge = {destination, weight, destinationValue};
    adjacencyList[source].push_back(edge);
    cout << "added" << endl;
}

// Print the graph
void WeightedQuadgraph::printGraph()
{
    cout << "PRINT" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        std::cout << "Vertex " << i << " --> ";
        for (const Edge &edge : adjacencyList[i])
        {
            std::cout << "(" << edge.destination << ", " << edge.weight << ", " << edge.destinationValue << ") ";
        }
        std::cout << std::endl;
    }
}