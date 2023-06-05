#include "Map.hpp"
using namespace std;
Map::Map(int size_x, int size_y, vector<string> *map)
{
    this->_size_x = size_x;
    this->_size_y = size_y;
    this->_map = map;
}

void Map::SearchBoat(int *x, int *y)
{
    for (int i = 1; i < this->_size_x; i++)
    {
        for (int j = 1; j < this->_size_y; j++)
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

Graph *Map::ToGraph()
{
    int generalIndex = 0;
    int totalSize = this->_size_x * this->_size_y;
    Node nodes[totalSize];
    //     =
    // {
    //     // (x, y, w) —> aresta de `x` a `y` tendo peso `w`
    //     {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {4, 5, 1}, {5, 4, 3}
    // };

    cout << "ToGraph" << endl;
    for (int i = 0; i <= this->_size_x; i++)
    {
        for (int j = 0; j <= this->_size_y; j++)
        {

            if (generalIndex == totalSize)
            {
                break;
            }

            if (this->_map->at(i)[j] == '*')
            {
                continue;
            }

            Node edge = {};

            if (generalIndex > this->_size_x)
            {
                // atribui edge ao nodo de cima
                int topEdgeIndex = generalIndex - this->_size_x;
                edge.top = &edges[topEdgeIndex];
                edge.topWeight = 1;
            }

            if (generalIndex % this->_size_x)
            {
                // atribui edge da direita
                int rightEdgeIndex = generalIndex + 1;
                edge.right = &edges[rightEdgeIndex];
                edge.rightWeight = 1;
            }

            if ((generalIndex - 1) % this->_size_x)
            {
                // atribui edge da esquerda
                int leftEdgeIndex = generalIndex - 1;
                edge.left = &edges[leftEdgeIndex];
                edge.leftWeight = 1;
            }

            if (generalIndex < (totalSize - this->_size_x))
            {
                // atribui edge de baixo
                int bottomEdgeIndex = (generalIndex + this->_size_x);
                edge.bottom = &edges[bottomEdgeIndex];
                edge.bottomWeight = 1;
            }

            generalIndex++;
        }
        cout << endl;
    }

    return NULL;
}
