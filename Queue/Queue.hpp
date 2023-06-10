#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

template<typename T>
class Queue
{
    private:
        T* _queue;
        int _numItems;
        int _capacity;
        int _first;

    public:
        Queue(int numItems);
        ~Queue();

        bool IsEmpty() const;
        int  Size() const;
        void Insert(const T v);
        T Remove();

};

#endif


