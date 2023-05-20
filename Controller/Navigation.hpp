#ifndef  _NAVIGATION_CPP_
#define _NAVIGATION_CPP_

#include "../Barco/Barco.hpp"
#include "../Map/Map.hpp"

class Navigation
{
    private:
        Map   _map;
        Barco _barco;
    public:
        Navigation(Map map, Barco Barco);
};

#endif