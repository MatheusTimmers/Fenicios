#include "Map.hpp"
#include "../Graph/Graph.hpp"
#include "../Dot/Dot.hpp"
#include <vector>
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

void Map::CreateMap(vector<string> *map)
{
}

WeightedQuadgraph *Map::ToGraph()
{
    WeightedQuadgraph *graph = new WeightedQuadgraph(this->_size_x, this->_size_y);

    for (int y = 1; y < this->_size_y; y++)
    {
        for (int x = 0; x < this->_size_x; x++)
        {

            string value = string(1, this->_map->at(y)[x]);
            cout << value << endl;

            Dot source;
            source.x = x;
            source.y = y;

            int weight = 1;
            // if (this->_map->at(y)[x] == '*')
            // {
            //     continue;
            // }

            if (y > 1)
            {
                // atribui edge ao nodo de cima
                cout << "top" << endl;
                value = string(1, this->_map->at(y - 1)[x]);
                Dot destination;
                destination.x = x;
                destination.y = y - 1;
                graph->addEdge(source, destination, value, weight);
            }

            if (x + 1 < this->_size_x)
            {
                // atribui edge da direita
                cout << "right " << x << endl;

                value = string(1, this->_map->at(y)[x + 1]);
                Dot destination;
                destination.x = x + 1;
                destination.y = y;
                graph->addEdge(source, destination, value, weight);
            }

            if (x > 0)
            {
                // atribui edge da esquerda
                cout << "left" << endl;
                value = string(1, this->_map->at(y)[x - 1]);
                Dot destination;
                destination.x = x - 1;
                destination.y = y;
                graph->addEdge(source, destination, value, weight);
            }

            if (y < this->_size_y)
            {
                // atribui edge de baixo
                cout << "bottom" << endl;
                value = string(1, this->_map->at(y + 1)[x]);
                Dot destination;
                destination.x = x;
                destination.y = y + 1;
                graph->addEdge(source, destination, value, weight);
            }
        }
    }
    // cout << "OUT" << endl;

    graph->printGraph();
    return graph;
}
#endif