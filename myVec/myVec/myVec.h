#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class myVector
{
    public:
        // constructor
        myVector();
        myVector(int);
        // getter
        int size();
        // push
        void push_back(T);
        // pop
        T pop_back();

    private:
        int _size;
        T* _data;
        void copy(T*, T*, int size);
};

template<class T>
myVector<T>::myVector()
{
    this->_size = 0;
    this->_data = NULL;
}

template<class T>
myVector<T>::myVector(int size)
{
    this->_size = size;
    this->_data = new T[size];
}


// getter
template<class T>
int myVector<T>::size()
{
    return this->_size;
}

// copy
template<class T>
void myVector<T>::copy(T* data, T* c_data,int size)
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = c_data[i];
    }
}

// push
template<class T>
void myVector<T>::push_back(T data)
{
    T* old_data = this->_data;
    this->_data = new T[this->_size + 1];
    copy(this->_data, old_data, this->_size);
    this->_data[this->_size++] = data;
    delete[] old_data;
}

// pop
template<class T>
T myVector<T>::pop_back()
{
    T* old_data = this->_data;
    T popData = this->_data[this->_size - 1];
    this->_data = new T[this->_size - 1];
    copy(this->_data, old_data, this->_size -1);
    this->_size--;
    delete[] old_data;
    return popData;
}

