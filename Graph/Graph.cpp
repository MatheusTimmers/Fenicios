#include <iostream>
#include "Graph.hpp"
using namespace std;

Graph::Graph(Edge **edges, int size)
{
    this->_edge = edges;
    this->_size = size;
}

Edge *Graph::getEdge(int index)
{
    return this->_edge[index];
}

int Graph::dijkstra(int startIndex, int endIndex)
{
}