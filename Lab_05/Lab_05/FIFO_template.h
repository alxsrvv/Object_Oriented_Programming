#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <class X>
class Queue
{
	X* _arr; 			// array of elements
	unsigned _capacity; // maximum capacity of the queue
	unsigned _first;  	// number of front element in the queue
	unsigned _last;   	// number of rear element in the queue
	unsigned _length;  	// current size of the queue

public:
	Queue(unsigned size);
	~Queue();

	bool isEmpty() const;
	bool isFull() const;
	unsigned size() const;
	X peek() const;
	void enqueue(X new_element); // insert element
	void dequeue(); // remove element
	void delete_q();
	void print(ostream& os = cout) const;
};

template <class X>
Queue<X>::Queue(unsigned size) :
	_capacity(size), _first(0), _last(-1), _length(0)// constructor to initialize queue
{
	_arr = new X[size];
}

template <class X>
Queue<X>::~Queue() // destructor to delete queue
{
	delete_q();
}

template <class X>
bool Queue<X>::isEmpty() const 
{
	return (size() == 0);
}

template <class X>
bool Queue<X>::isFull() const
{
	return (size() == _capacity);
}

template <class X>
unsigned Queue<X>::size() const // current size of the queue
{
	return _length;
}

template <class X>
X Queue<X>::peek() const // return front element in the queue
{
	if (isEmpty())
	{
		cout << "\nUnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return _arr[_first];
}

template <class X>
void Queue<X>::enqueue(X new_element) // add an item to the queue
{
	// check for queue overflow
	if (isFull())
	{
		cout << "\nOverFlow of queue\nProgram stopped\n";
		exit(EXIT_FAILURE);
	}

	_last = (_last + 1) % _capacity;
	_arr[_last] = new_element;
	_length++;

	cout << "\nItem '" << new_element << "' added in queue\n";
}

template <class X>
void Queue<X>::dequeue() // remove front element from the queue
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "\nUnderFlow of queue\nProgram stopped\n";
		exit(EXIT_FAILURE);
	}

	cout << "\nRemoving item '" << _arr[_first] << "' from queue\n";
	_first = (_first + 1) % _capacity;
	_length--;
}

template <class X>
void Queue<X>::delete_q() // delete all elements
{
	if (isEmpty())
		cout << "\nQueue is already empty!\n";
	else
	{
		while (_length != 0)
			Queue<X>::dequeue();
		cout << "\nQueue is empty now!\n";
	}
}

template <class X>
void Queue<X>::print(ostream& os) const // show all elements
{
	cout << "\nThe QUEUE now:\n[ ";
	for (unsigned i = 0; i < _length; ++i)
		os << _arr[(_first + i) % _capacity] << ' ';
	os << "]" << endl;
}