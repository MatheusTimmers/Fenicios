#ifndef _NAVIGATION_HPP_
#define _NAVIGATION_HPP_

#include "../Boat/Boat.hpp"
#include "../Map/Map.hpp"

class Navigation
{
    private:
        Map*  _map;
        Boat* _boat;
    public:
        Navigation(Map *map, Boat *Barco);
};

#endif