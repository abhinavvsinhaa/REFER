#include "array.h"

// Your code goes here ...
template <class T>
Array<T>::Array()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template <class T>
Array<T>::Array(const Array<T> &v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
}

template <class T>
Array<T>::Array(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template <class T>
Array<T>::Array(unsigned int size, const T &initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
    // T();
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &v)
{
    delete[] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template <class T>
T &Array<T>::front()
{
    return buffer[0];
}

template <class T>
T &Array<T>::back()
{
    return buffer[my_size - 1];
}

template <class T>
void Array<T>::push_back(const T &v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity + 5);
    buffer[my_size++] = v;
}

template <class T>
void Array<T>::pop_back()
{
    my_size--;
}

template <class T>
void Array<T>::reserve(unsigned int capacity)
{
    if (buffer == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }
    T *Newbuffer = new T[capacity];
    // assert(Newbuffer);
    unsigned int l_Size = capacity < my_size ? capacity : my_size;
    // copy (buffer, buffer + l_Size, Newbuffer);

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

template <class T>
unsigned int Array<T>::size() const //
{
    return my_size;
}

template <class T>
void Array<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
    return buffer[index];
}

template <class T>
unsigned int Array<T>::capacity() const
{
    return my_capacity;
}

template <class T>
Array<T>::~Array()
{
    delete[] buffer;
}
template <class T>
void Array<T>::clear()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}