#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T> *next;
};

template<typename T>
class Queue {
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void enqueue(T val) {
		Node<T> *newNode = new Node<T>;
		newNode -> data = val;
		newNode -> next = NULL;

		if(head == NULL) {
			head = newNode;
			head -> next = NULL;
			tail = head;
			size++;
		} else {
			tail -> next = newNode;
			tail = newNode;
			size++;
		}
	}

	void dequeue() {
		Node<T> *temp = head;
		head = head -> next;
		delete temp;
		size--;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		if(size==0) {
			return true;
		}
		return false;
	}

	T front() {
		return head -> data;
	}

	void print() {
		Node<T> *temp = head;
		while(temp!=NULL) {
			cout << temp -> data << " ";
			temp = temp -> next;
		}
	}
};