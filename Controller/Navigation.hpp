#ifndef _NAVIGATION_HPP_
#define _NAVIGATION_HPP_

#include "../Boat/Boat.hpp"
#include "../Map/Map.hpp"
#include <queue>
#include <algorithm>

class Navigation
{
    private:
        WeightedGraph*  _graph;
        Boat*           _boat;
        int*            _dist;
        vector<vertex>* _fathers;

    public:
        Navigation(WeightedGraph *graph, Boat *boat);
        void Caronte(vertex start);

        int             GetDist(vertex i)   { return this->_dist[i]; };
        vertex          GetParent(vertex i) { return this->_fathers->at(i); };
        int*            GetDist()           { return this->_dist; };
        vector<vertex>* GetParent() { return this->_fathers; };

};

#endif