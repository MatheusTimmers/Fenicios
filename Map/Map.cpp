#include "Map.hpp"
#include "../Graph/Graph.hpp"
#include <vector>
#include <math.h>
#include <string>

using namespace std;
#ifndef MAP
#define MAP
Map::Map(int size_y, int size_x, vector<string> *map)
{

    this->_size_x = size_x;
    this->_size_y = size_y;
    this->_map = map;
}

void Map::SearchBoat(int *x, int *y)
{

    for (int j = 1; j < this->_map->size(); j++)
    {
        for (int i = 1; i < this->_map->at(j).size(); i++)
        {
            // Procura o primeiro porto do Mapa;
            if (this->_map->at(j)[i] == '1')
            {
                *x = i;
                *y = j;
                cout << "Posicao do barquinho eh " << *x << " e " << *y << endl;
                return;
            }
        }
    }
}

WeightedQuadgraph *Map::ToGraph()
{
    WeightedQuadgraph *graph = new WeightedQuadgraph(this->_size_x, this->_size_y);

    for (int y = 1; y <= this->_size_y; y++)
    {
        for (int x = 0; x < this->_size_x; x++)
        {
            // cout << this->_size_y << " X " << this->_size_x << endl;
            // cout << y << " X " << x << endl;
            // cout << this->_map->at(y) << endl;

            char value = this->_map->at(y)[x];
            if (value == '\0')
            {
                cout << "break" << endl;
                break;
            }

            char valueTop = this->_map->at(y - 1)[x];

            char valueBottom = y == this->_size_y ? '\0' : this->_map->at(y + 1)[x];

            char valueLeft = this->_map->at(y)[x - 1];

            char valueRight = this->_map->at(y)[x + 1];

            Dot source;
            source.x = x;
            // - 1 para que o seja salvo no grafo a partir do index 0 não 1
            source.y = y - 1;

            if (y > 1 && valueTop != '\0')
            {
                // atribui edge ao nodo de cima
                int weight = valueTop == '*' ? INFINITY : 1;
                // cout << "top" << endl;
                value = this->_map->at(y - 1)[x];
                Dot destination;
                destination.x = x;
                destination.y = y - 2;
                graph->addEdge(source, destination, value, weight);
            }

            if (valueRight != '\0')
            {
                // atribui edge da direita
                // cout << "right " << x << endl;
                int weight = valueRight == '*' ? INFINITY : 1;
                value = this->_map->at(y)[x + 1];
                Dot destination;
                destination.x = x + 1;
                destination.y = y - 1;
                graph->addEdge(source, destination, value, weight);
            }

            if (valueLeft != '\0')
            {
                // atribui edge da esquerda
                // cout << "left" << endl;
                value = this->_map->at(y)[x - 1];
                int weight = valueLeft == '*' ? INFINITY : 1;
                Dot destination;
                destination.x = x - 1;
                destination.y = y - 1;
                graph->addEdge(source, destination, value, weight);
            }

            if (valueBottom != '\0')
            {
                // atribui edge de baixo
                // cout << "bottom" << endl;
                value = this->_map->at(y + 1)[x];
                int weight = valueBottom == '*' ? INFINITY : 1;
                Dot destination;
                destination.x = x;
                destination.y = y;
                graph->addEdge(source, destination, value, weight);
            }
        }
    }
    graph->printGraph();
    return graph;
}
#endif