#pragma once
#include <queue>
#include <iostream>
#include <string>
using namespace std;

template <class X>
class Queue
{
	queue <X> _queue;
public:
	Queue();
	~Queue();

	bool isEmpty() const;
	unsigned size() const;
	X peek() const;
	void enqueue(X new_element); // insert element
	void dequeue(); // remove element
	void delete_q();
	void print(ostream& os = cout) const;
};

template <class X>
inline Queue<X>::Queue()
{	}

template <class X>
Queue<X>::~Queue()
{
	delete_q();
}

template <class X>
bool Queue<X>::isEmpty() const
{
	return _queue.empty();
}

template <class X>
unsigned Queue<X>::size() const
{
	return _queue.size();
}

template <class X>
X Queue<X>::peek() const
{
	if (isEmpty())
		cout << "\nNo elements in queue to peek!\n";
	else
		return _queue.front();
}

template <class X>
void Queue<X>::enqueue(X new_element)
{
	_queue.push(new_element);
	cout << "\nItem '" << new_element << "' added in queue\n";
}

template <class X>
void Queue<X>::dequeue()
{
	if (isEmpty())
		cout << "\nNo elements in queue to pop!\n";
	else
	{
		cout << "\nRemoving item '" << _queue.front() << "' from queue\n";
		_queue.pop();
	}
}

template <class X>
void Queue<X>::delete_q()
{
	if (isEmpty())
		cout << "\nQueue is already empty!\n";
	else
		while (!isEmpty())
			dequeue();
}

template <class X>
void Queue<X>::print(ostream& os) const
{
	queue <X> temp_queue = _queue;
	cout << "\nThe QUEUE now:\n[ ";
	while(!temp_queue.empty())
	{
		os << temp_queue.front() << ' ';
		temp_queue.pop();
	}
	os << "]" << endl;
}