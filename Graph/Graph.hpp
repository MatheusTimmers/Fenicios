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
   int weight; 
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
    public:
        Graph *_graph;

        WeightedGraph(int nVertex);
        ~WeightedGraph();

        void  InsertArc(vertex x, vertex y);

        //TODO: IMPLEMETAR OS GETS para ter controle de dados
        int    GetnArc();
        int    GetnVertex();

        Node* NewNode(vertex x, Node *next);
        void  AddWeight(vertex x, int weight);
        void  printGraph();
};

#endif // WEIGHTED_GRAPH_HPP
