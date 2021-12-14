
#include <iostream>
#include <string>
using namespace std;

#define SIZE 50
template <class X>
class queue
{
    X *arr;
    int capacity; 
    int front;  
    int rear;     
    int count;    

public:
    queue(int size = SIZE);

    void dequeue();
    void enqueue(X x);
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
};
