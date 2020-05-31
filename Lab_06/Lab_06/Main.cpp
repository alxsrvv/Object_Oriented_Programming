#include "STL_FIFO_template.h"

void main()
{
	Queue<string> q_1;

	q_1.enqueue("first");
	q_1.enqueue("second");
	q_1.enqueue("third");

	q_1.print();

	cout << "\nFront element is: " << q_1.peek() << endl;
	q_1.dequeue();
	q_1.enqueue("fourth");

	q_1.print();

	cout << "\nQueue size is " << q_1.size() << endl;
	q_1.dequeue();
	q_1.dequeue();

	q_1.print();

	q_1.delete_q();

	system("pause");

	Queue<int> q_2;
	q_2.enqueue(10);
	q_2.enqueue(100);
	q_2.print();
	cout << "\nFront element is: " << q_2.peek() << endl;
	q_2.dequeue();
	q_2.dequeue();
	q_2.dequeue();

	system("pause");
}