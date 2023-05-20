#include "Boat.hpp"


Boat::Boat(int pos_x, int pos_y)
{
    this->_pos_x = pos_x;
    this->_pos_y = pos_y;
}

void Boat::move(bool orientation, bool direction) 
{
    // Direção do barco
    // True -> Vertical
    // False -> Horizontal
    // Orientaçao do Barco
    // True -> Direita/Cima
    // False - Esquerda/Baixo
    if (direction)
    {   
        if (orientation)
        {
            this->_pos_y++;
        }
        else
        {
            this->_pos_y++;  
        }
    }
    else
    {
        if (orientation)
        {
            this->_pos_x++;
        }
        else
        {
            this->_pos_x++;  
        }
    }
}