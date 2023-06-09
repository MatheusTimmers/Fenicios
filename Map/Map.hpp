#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include <iostream>
#include "../Graph/Graph.hpp"
#include <string>
using namespace std;

struct Pixel
{
    bool isWater;
    Pixel **pixels;
};

class Map
{
private:
    vector<string> *_map;
    int _size_x;
    int _size_y;

public:
    Map(int size_x, int size_y, vector<string> *map);
    ~Map();
    void SearchBoat(int *x, int *y);
    void CreateMap(vector<string> *map);
    WeightedGraph *ToGraph();
};

#endif