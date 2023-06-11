#include "Navigation.hpp"

Navigation::Navigation(WeightedGraph *graph, Boat *boat)
{
    this->_graph   = graph;
    this->_boat    = boat;
    this->_dist    = new int[this->_graph->GetnVertex()];
    this->_fathers = new vector<int>(this->_graph->GetnVertex()); 
}

// Função que procura o menor caminho entre @param START @param END
// Usando a distancia em relação a origem e uma lista de antecessores para cada vertice
void Navigation::Caronte(vertex start)
{
    // Variaveis
    const int max      = this->_graph->GetnVertex();
    queue<int> *queueR = new queue<int>;

    // Inicialização
    for (vertex v = 0; v < this->_graph->GetnVertex(); ++v) 
    {
        this->_dist[v]        = max; 
        this->_fathers->at(v) = -1;
    }
    
    this->_dist[start]        = 0; 
    this->_fathers->at(start) = start;
    queueR->push(start); 

    while (!queueR->empty()) 
    {
        vertex v = queueR->front(); 
        queueR->pop();

        // Visita todos as adjacencias de um vertice, e atribui uma distancia em relação a origem
        // Salva o pai para cada um dos vertices 
        for (Node* n = this->_graph->GetAdj(v); n != NULL; n = n->next)
        {
            vertex x = n->x; 
            if (this->_dist[x] == max) 
            {
                this->_dist[x]        = this->_dist[v] + 1; 
                this->_fathers->at(x) = v;
                queueR->push(x); 
            }
        }
    }
}