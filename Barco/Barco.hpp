

class Barco
{
    private:
        int _pos_x;
        int _pos_y;
        int _fuel;
    public:
        Barco(int pos_x, int pos_y);
        void move(bool orientation, bool direction);
};
