
#include <iostream>
#include <string>

using namespace std;
#define SIZE 5

template <class T> class Stack {

public:

	Stack();

	void push(T k);

	T pop();

	T topElement();

	bool isFull();

	bool isEmpty();

private:
	int top;
	T st[SIZE];
};

