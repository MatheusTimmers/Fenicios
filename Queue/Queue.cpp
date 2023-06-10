#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(int numItems)
{
    this->_queue    = new T[numItems];
    this->_capacity = numItems;
    this->_numItems = 0;
    this->_first    = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    for (int i = 0; i < this->_numItems; i++)
    {
        delete[] this->_queue[i];
    }
    delete this->_queue;
}

template<typename T>
bool Queue<T>::IsEmpty() const
{
    return this->numItems == 0;
}

template<typename T>
int Queue<T>::Size() const
{
    return this->_capacity;
}

template<typename T>
void Queue<T>::Insert(const T value) 
{
    if (++this->numItems < this->_capacity)
    {
        this->_queue[this->numItems] = value;
    }
}

template<typename T>
T Queue<T>::Remove() 
{
    T temp = this._queue[this->_first]; 
    this->_numItems--;
    this->first++;

    return temp;
}