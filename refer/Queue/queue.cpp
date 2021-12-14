#include"queue.h"

template <class T>
queue<T>::queue(int size)
{
   
    front = 0;
    rear = -1;
    count = 0;
    arr = new T[size];
    capacity = size;
    
}

template <class T> 
bool queue<T>::isEmpty() { 
    return (size() == 0); 
}

template <class T> 
bool queue<T>::isFull() { 
    return (size() == capacity); 
}

template <class T>
void queue<T>::enqueue(T item)
{
    if (isFull())
    {
        cout << "Overflow"<<endl;
        return ;
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}


template <class T>
void queue<T>::dequeue()
{
        if (isEmpty())
    {
        cout << "Underflow"<<endl;
        return ;
    }

    cout << "Removing " << arr[front] << endl;

    front = (front + 1) % capacity;
    count--;
}

template <class T>
int queue<T>::size() {
    return count;
}

template <class T>
T queue<T>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow"<<endl;
        return NULL ;
    }
    return arr[front];
}
