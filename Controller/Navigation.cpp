#include "Navigation.hpp"

Navigation::Navigation(WeightedGraph *graph, Boat *boat)
{
    this->_graph = graph;
    this->_boat  = boat;
}

void Navigation::Walk(int nHarbor)
{
    // Cria variaveis
    int num[this->_graph->GetnVertex()];
    int cnt = 0;
    Queue<int> *queue = new Queue<int>(this->_graph->GetnVertex());

    for (vertex v = 0; v < this->_graph->GetnVertex(); ++v)
    {
        num[v] = -1;
    }

    num[nHarbor] = cnt++; 
    queue->Insert(nHarbor); 

    while (!queue->IsEmpty()) 
    {
        vertex v = queue->Remove(); 
        for (Node* n = this->_graph->_graph->adj[v]; n != NULL; n = n->next)
        {
            if (num[n->x] == -1) 
            {
                num[n->x] = cnt++; 
                queue->Insert(n->x); 
            }
        }
    }
}