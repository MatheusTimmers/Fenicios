#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include <iostream>
#include <math.h>
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
    bool  IsWater(int x);
    void CreateMap(vector<string> *map);

    int GetSizeX() { return _size_x; };
    int GetSizeY() { return _size_y; };
    WeightedGraph *ToGraph();
};

#endif