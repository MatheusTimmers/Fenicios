#include "Map.hpp"


Map::Map(int size_x, int size_y, vector<string> *map)
{
    this->_size_x = size_x;
    this->_size_y = size_y;
    CreteMap(map);
}

void Map::SearchBoat(int *x, int *y)
{
    for(int i = 0; i < this->_size_x; i++)
    {
        for(int j = 0; j < this->_size_y; j++)
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


