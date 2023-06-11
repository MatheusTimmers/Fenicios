#ifndef _BOAT_HPP_
#define _BOAT_HPP_

class Boat
{
    private:
        int _pos_x;
        int _pos_y;
        int _fuel;
    public:
        Boat(int pos_x, int pos_y);
        void move(bool orientation, bool direction);
};


#endif