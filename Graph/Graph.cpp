#include "Graph.hpp"
#include <iostream>
using namespace std;

// Constructor
WeightedQuadgraph::WeightedQuadgraph(int x, int y)
{
    this->x = x;
    this->y = y;

    this->adjacencyList.resize(y);

    for (int i = 0; i < y; i++)
    {
        this->adjacencyList.at(i).resize(x);
    }
}

// Add an edge to the graph
void WeightedQuadgraph::addEdge(Dot source, Dot destination, char destinationValue, int weight)
{
    //cout << "addEdge(" << source.x << ", " << source.y << ", " << destination.x << ", " << destination.y << ", " << destinationValue << ", " << weight << ")" << endl;
    Edge edge = {destination, weight, destinationValue};
    adjacencyList[source.y][source.x].push_back(edge);
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
    for (int i = 0; i < this->y; i++)
    {
        for (int j = 0; j < this->x; j++)
        {
            cout << "Vertex " << i << " x " << j << " --> ";

            for (const Edge &edge : this->adjacencyList.at(i).at(j))
            {
                cout << "(" << edge.destination.x << ", " << edge.destination.y << ", " << edge.weight << ", " << edge.destinationValue << ") ";

                cout << endl;
            }
            cout << endl;
        }
    }
}