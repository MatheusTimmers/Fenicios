#ifndef _NAVIGATION_HPP_
#define _NAVIGATION_HPP_

#include "../Boat/Boat.hpp"
#include "../Map/Map.hpp"
#include "../Queue/Queue.hpp"

class Navigation
{
    private:
        WeightedGraph* _graph;
        Boat*          _boat;
    public:
        Navigation(WeightedGraph *graph, Boat *boat);
        void Walk(int nHarbor);
};

#endif