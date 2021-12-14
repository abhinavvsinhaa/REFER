#pragma once

// using namespace std;

template <class T>
class Array
{
public:
    Array();
    Array(unsigned int size);
    Array(unsigned int size, const T &initial);
    Array(const Array<T> &v);
    ~Array();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    T &front();
    T &back();
    void push_back(const T &value);
    void pop_back();

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    T &operator[](unsigned int index);
    Array<T> &operator=(const Array<T> &);
    void clear();

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T *buffer;
};
