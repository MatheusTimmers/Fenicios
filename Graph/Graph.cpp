#include "Graph.hpp"
#include <iostream>
using namespace std;

// Construtor
WeightedGraph::WeightedGraph(int nVertex)
{      
    try
    {
        this->_graph = new Graph;
        this->_graph->nVertex = nVertex; 
        this->_graph->nArc = 0;

        this->_graph->adj = new Node*[nVertex];
        for (vertex v = 0; v < nVertex; v++)
        {
            this->_graph->adj[v] = NULL;
        }
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Destrutor
WeightedGraph::~WeightedGraph()
{
    for (int i = 0; i < this->_graph->nVertex; i++)
    {
        delete this->_graph->adj[i];       
    }
    delete[] this->_graph->adj;
}

// Adiciona uma ligação entre dois vertices
// TODO: Bastante custoso, se tiver bastates nodes
void WeightedGraph::InsertArc(vertex x, vertex y)
{   
    // Verifica se já estão ligados
    for (Node* n = this->_graph->adj[x]; n != NULL; n = n->next)
        if (n->x == y) return;

    this->_graph->adj[x] = NewNode(y, this->_graph->adj[x]); 
    this->_graph->nArc++;
}

void WeightedGraph::AddWeight(vertex x, int weight)
{
    _graph->adj[x]->weight = weight;
}

// Cria um novo nodo
Node* WeightedGraph::NewNode(vertex x, Node *next) 
{
    try
    {
        Node* node = new Node;
        node->x = x; 
        node->next = next;  

        return node;  
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }                       
}

// Retorna o numero de arcos
int WeightedGraph::GetnArc()
{
    return this->_graph->nArc;
}

// Retorna o numero de de vertices
int WeightedGraph::GetnVertex()
{
    return this->_graph->nVertex;
}

// Faz o Print
void WeightedGraph::printGraph()
{
    for (int i = 0; i < this->_graph->nVertex; i++)
    {
        cout << "Vertex " << i << " --> (";
        for (Node* n = this->_graph->adj[i]; n != NULL; n = n->next) 
        {
            cout << n->x;
            if (n->next != NULL) cout << ", "; 
        }
        cout << ") " << endl;
    }
}