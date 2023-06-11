#ifndef WEIGHTED_GRAPH_HPP
#define WEIGHTED_GRAPH_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define vertex int

// Estrutura que representa uma conexão
struct Node 
{ 
   vertex x;
   Node *next; 
};

// Estrutura que representa o Grafo
struct Graph
{
    int nVertex;
    int nArc;  
    Node **adj;
};

class WeightedGraph
{
    private:
        Graph *_graph;

    public:

        WeightedGraph(int nVertex);
        ~WeightedGraph();

        void  InsertArc(vertex x, vertex y);

        int    GetnArc();
        int    GetnVertex();
        Node*  GetAdj(vertex x);

        Node* NewNode(vertex x, Node *next);
        void  printGraph();
};

#endif // WEIGHTED_GRAPH_HPP
