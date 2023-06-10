#include "Map.hpp"
#include "../Graph/Graph.hpp"
#include <vector>
#include <math.h>
#include <string>
#include "../Utils/Utils.hpp"
using namespace std;
#ifndef MAP
#define MAP
Map::Map(int size_y, int size_x, vector<string> *map)
{

    this->_size_x = size_x;
    this->_size_y = size_y;
    this->_map = map;
}

// number, index
vector<pair<int, int>> Map::search()
{

    int generalIndex = 0;
    // number, index
    vector<pair<int, int>> q;

    for (int j = 1; j < this->_map->size(); j++)
    {
        for (int i = 0; i < this->_map->at(j).size(); i++)
        {
            int number = atoi(string(1, this->_map->at(j)[i]).c_str());
            if (number)
            {
                cout << "adding number " << number << " index " << generalIndex << endl;
                q.push_back(make_pair(number, generalIndex));
            }
            generalIndex++;
        }
    }

    quickSort(q, 0, (q.size() - 1));

    return q;
}

Graph *Map::ToGraph()
{
    Graph *graph = new Graph(this->_size_x * this->_size_y);

    int generalIndex = -1;
    for (int y = 1; y <= this->_size_y; y++)
    {
        for (int x = 0; x < this->_size_x; x++)
        {
            // cout << this->_size_y << " X " << this->_size_x << endl;
            // cout << "general index " << generalIndex << endl;
            //  cout << this->_map->at(y) << endl;
            generalIndex++;

            char value = this->_map->at(y)[x];
            if (value == '\0')
            {

                break;
            }

            if (value == '*')
            {
                continue;
            }

            char valueBottom = y == this->_size_y ? '\0' : this->_map->at(y + 1)[x];
            char valueRight = this->_map->at(y)[x + 1];
            char valueTop = this->_map->at(y - 1)[x];
            char valueLeft = this->_map->at(y)[x - 1];

            if (valueRight != '\0' && valueRight != '*')
            {
                // atribui edge da direita
                // std::cout << "right " << x << endl;

                graph->addEdge(generalIndex, (generalIndex + 1), valueRight);
            }

            if (valueLeft != '\0' && valueLeft != '*')
            {
                // atribui edge da direita
                // std::cout << "right " << x << endl;

                graph->addEdge(generalIndex, (generalIndex - 1), valueLeft);
            }

            if (valueBottom != '\0' && valueBottom != '*')
            {
                // atribui edge de baixoc
                // cout << "bottom" << endl;

                graph->addEdge(generalIndex, generalIndex + this->_size_x, valueBottom);
            }

            if (y > 1 && valueTop != '\0' && valueTop != '*')
            {
                // atribui edge de baixoc
                // cout << "bottom" << endl;

                graph->addEdge(generalIndex, generalIndex - this->_size_x, valueTop);
            }
        }
    }

    return graph;
}
#endif