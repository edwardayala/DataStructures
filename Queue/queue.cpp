#include "queue.h"

Queue::Queue()
{
	numOfBooks = 0;
	front = NULL;
	rear = NULL;
}

Queue::~Queue()
{}


void Queue::enqueue(Book * b)
{
	rear->setNext(b);
	rear = b;
	numOfBooks++;
}

void Queue::pop()
{
	Book * p = front;
	front = front->getNext();
	delete p;
	numOfBooks--;
}

bool Queue::isEmpty()
{
	return numOfBooks == 0;
}

void Queue::print()
{
	Book * p = front;
	while (p != NULL)
	{
		cout << p->getISBN() << " ";
		p = p->getNext();
	}
}
