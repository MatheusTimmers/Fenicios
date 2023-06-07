#include "Map.hpp"
#include "../Graph/Graph.hpp"
#include <vector>
#include <string>
using namespace std;
#ifndef MAP
#define MAP
Map::Map(int size_y, int size_x, vector<string> *map)
{

    this->_size_x = size_x - 1;
    this->_size_y = size_y - 1;
    this->_map = map;
}

void Map::SearchBoat(int *x, int *y)
{

    for (int i = 1; i < this->_map->size(); i++)
    {
        for (int j = 1; j < this->_map->at(i).size(); j++)
        {
            // Procura o primeiro porto do Mapa;
            if (this->_map->at(i)[j] == '1')
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
    int generalIndex = 0;
    int totalSize = (this->_size_x) * (this->_size_y);
    WeightedQuadgraph *graph = new WeightedQuadgraph(totalSize);

    for (int i = 0; i < this->_size_x; i++)
    {
        for (int j = 0; j < this->_size_y; j++)
        {

            string value = string(1, this->_map->at(i)[j]);
            cout << value << endl;

            int weight = 1;
            // if (this->_map->at(i)[j] == '*')
            // {
            //     continue;
            // }
            if (generalIndex == totalSize)
            {
                cout << "BREAK" << endl;
                break;
            }

            if (generalIndex > this->_size_x)
            {
                // atribui edge ao nodo de cima
                cout << "top" << endl;
                int topEdgeIndex = generalIndex - this->_size_x;
                graph->addEdge(generalIndex, topEdgeIndex, value, weight);
            }

            if (!(generalIndex % this->_size_x))
            {

                // atribui edge da direita
                cout << "right" << endl;

                int rightEdgeIndex = generalIndex + 1;
                graph->addEdge(generalIndex, rightEdgeIndex, value, weight);
            }

            if (generalIndex > this->_size_x && (generalIndex - 1) % this->_size_x)
            {

                // atribui edge da esquerda
                cout << "left" << endl;

                int leftEdgeIndex = generalIndex - 1;
                graph->addEdge(generalIndex, leftEdgeIndex, value, weight);
            }

            if (generalIndex < (totalSize - this->_size_x))
            {
                // atribui edge de baixo
                cout << "bottom" << endl;

                int bottomEdgeIndex = (generalIndex + this->_size_x);
                graph->addEdge(generalIndex, bottomEdgeIndex, value, weight);
            }

            generalIndex++;
        }
    }
    cout << "OUT" << endl;

    graph->printGraph();
    return graph;
}
#endif