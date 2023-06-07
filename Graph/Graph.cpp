#include "Graph.hpp"
#include <iostream>
using namespace std;

// Constructor
WeightedQuadgraph::WeightedQuadgraph(int x, int y)
{
    this->x = x;
    this->y = y;

    this->adjacencyList.resize(y);
    cout << "DONE" << endl;

    for (int i = 0; i < y; i++)
    {
        this->adjacencyList.at(i).resize(x);
    }
    cout << "DONE" << endl;
}

// Add an edge to the graph
void WeightedQuadgraph::addEdge(Dot source, Dot destination, string destinationValue, int weight)
{
    cout << "addEdge(" << source.x << ", " << source.y << ", " << destination.x << ", " << destination.y << ", " << destinationValue << ", " << weight << ")" << endl;
    Edge edge = {destination, weight, destinationValue};
    cout << adjacencyList.size() << endl;
    adjacencyList[source.y][source.x].push_back(edge);
    cout << "added" << endl;
}

vector<Edge> WeightedQuadgraph::getEdges(int x, int y)
{
    if (x < this->adjacencyList.size() && y < this->adjacencyList.at(x).size())
    {
        return this->adjacencyList.at(x).at(y);
    }
    return vector<Edge>();
}

// Print the graph
void WeightedQuadgraph::printGraph()
{
    cout << "PRINT" << endl;

    for (int i = 0; i < this->y; i++)
    {
        for (int j = 0; j < this->x; j++)
        {
            std::cout << "Vertex " << i << " x " << j << " --> ";

            for (const Edge &edge : this->adjacencyList.at(i).at(j))
            {
                std::cout << "(" << edge.destination.x << ", " << edge.destination.y << ", " << edge.weight << ", " << edge.destinationValue << ") ";

                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
}