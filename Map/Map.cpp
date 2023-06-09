#include "Map.hpp"
#include "../Graph/Graph.hpp"
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#ifndef MAP
#define MAP

// Construtor 
Map::Map(int size_x, int size_y, vector<string> *map)
{
    this->_size_x = size_x;
    this->_size_y = size_y;
    this->_map = map;
}

// TODO: Verificar se ta certo, pelo que eu encontrei na net, vector<string> já faz destructor
Map::~Map()
{
    delete this->_map;
}

// Procura o Barco dentro do mapa
void Map::SearchBoat(int *x, int *y)
{
    for (int i = 0; i < this->_size_x; i++)
    {
        for (int j = 0; j < this->_size_y; j++)
        {
            // Procura o primeiro porto do Mapa;
            if (this->_map->at(j)[i] == '1')
            {
                // +1, pois vetores começam em 0
                *x = i + 1;
                *y = j;
                cout << "Posicao do barquinho eh " << *x << " e " << *y << endl;
                return;
            }
        }
    }
}

WeightedGraph *Map::ToGraph()
{
    int total = this->_size_x * this->_size_y;
    WeightedGraph *graph = new WeightedGraph(total);
    for (int i = 0; i < total; i++)
    {
        // Se o i não for o ultimo nodo, adiciona o próximo
        if (i+1 <= total)
            graph->InsertArc(i, i+1);
         
        // Se o i não for o primeiro nodo, adiciona o anterior
        if (i-1 >= 0)
            graph->InsertArc(i, i-1);
        
        // Se o i não for da primeira linha, adiciona o de cima
        if (i - this->_size_x >= 0)
            graph->InsertArc(i, i - this->_size_x);
        
        // Se o i não for da ultima linha, adiciona o de baixo
        if (i + this->_size_x <= total)
            graph->InsertArc(i, i + this->_size_x);
    }
    graph->printGraph();
    return graph;
}
#endif