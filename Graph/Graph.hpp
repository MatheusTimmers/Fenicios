#ifndef WEIGHTED_QUADGRAPH_HPP
#define WEIGHTED_QUADGRAPH_HPP

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define MAX 9999999
using namespace std;

// Estrutura que representa um edge do grafo
struct Edge
{
    int source;
    int destination;
    char destinationValue;
};

class Graph
{
    private:
        vector<vector<Edge>> adjacencyList;
        int generalIndex;
        int size;

    public:
        Graph(int vertexes);
        Graph(){};

        void addEdge(int source, int destination, char destinationValue);

        vector<Edge> getEdges(int vertex);

        void printGraph();

        vector<int> shortestPath(int startVertex, int endIndex);
};

#endif // WEIGHTED_QUADGRAPH_HPP
