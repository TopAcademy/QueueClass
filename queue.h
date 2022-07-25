#pragma once
#include <stdexcept>
#include <iostream>

template <class T>
class Queue 
{
private:
	T* q;
	unsigned int size;
	int last;
public:
	// constructors and destructor
	Queue(int sz);
	~Queue();
	// getters
	bool is_empty();
	bool is_full();
	T get();
	friend std::ostream& operator << (std::ostream& o, const Queue& q);
	// setters
	void put(T x);
};



// constructor
// 1. Check: 1 <= size <= 1024
// 2. Allocate memory
// 3. Set last = -1
template <class T>
Queue<T>::Queue(int sz)
{
	if (sz < 1 || sz > 1024) {
		throw std::overflow_error("[!] Index overflow");
	}
	this->size = sz;
	this->last = -1;
	q = new T[size];
}

// destrucotr
template <class T>
Queue<T>::~Queue()
{
	delete[] q;
}

// getters

template <class T>
std::ostream& operator << (std::ostream& o, const Queue<T>& q)
{
	for (int i = 0; i <= q.last; i++) std::cout << q.q[i] << ' ';
	std::cout << std::endl;
}


template <class T>
bool Queue<T>::is_empty()
{
	return last == -1;
}

template <class T>
bool Queue<T>::is_full()
{
	return last == size-1;
}

// Extract last element of queue
template <class T>
T Queue<T>::get()
{
	if (is_empty()) throw std::overflow_error("Queue is empty");
	last--;
	return q[last];
}

// Put element to queue
template <class T>
void Queue<T>::put(T x)
{
	if (is_full()) throw std::overflow_error("Queue is full");
	for (int i = last; i >= 0; i--) {
		q[last + 1] = q[last];
	}
	q[0] = x;
	last++;
}
