#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include <iostream>
#include "../Graph/Graph.hpp"
#include <string>
#include <math.h>
#include <string>
#include "../Utils/Utils.hpp"
using namespace std;

class Map
{
    private:
        vector<string> *_map;
        int _size_x;
        int _size_y;

    public:
        Map(int size_y, int size_x, vector<string> *map);
        vector<pair<int, int>> search();
        Graph *toGraph();
};

#endif