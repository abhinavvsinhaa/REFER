#include<climits>

template<typename T>
class stackTemplate {
	T* data;
	int nextIndex;
	int capacity;
public:
	stackTemplate() {
		data = new T[4];
		nextIndex = 0;
		capacity = 4;
	}

	//insert element in the stack (push) 
	void push(T value) {
		if(nextIndex == capacity){
			T *newData = new T[2*capacity];
			
			for(int i=0; i < capacity; i++) {
				newData[i] = data[i];
			}

			capacity*= 2;
			delete [] data;
			data = newData;
			delete newData;
		}
		data[nextIndex] = value;
		nextIndex++;
	}

	//delete elements in the stack (pop)
	T pop() {
		if(nextIndex==0) {
			cout<<"Stack empty"<<endl;
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}

	//returns the no of elements(size) of stack
	int size() {
		return nextIndex;
	} 

	//checks if the stack is empty or not
	bool isEmpty() {
		if(nextIndex==0) {
			return true;
		} else {
			return false;
		}
	}

	//access the top most element 
	T top() {
		if(isEmpty()) {
			cout<<"Stack empty"<<endl;
			return 0;
		}
		return data[nextIndex-1];
	}
};