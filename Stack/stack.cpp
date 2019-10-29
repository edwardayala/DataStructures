#include "stack.h"

Stack::Stack()
{
	numOfBooks = 0;
	top = NULL;
}

Stack::~Stack()
{}


void Stack::push(Book * b)
{
	b->setNext(top);   //b->next = top;
	top = b;
	numOfBooks++;
}

void Stack::pop()
{
	Book * p = top;
	top = top->getNext();
	delete p;
	numOfBooks--;
}

bool Stack::isEmpty()
{
	return numOfBooks == 0;
}

void Stack::print()
{
	Book * p = top;
	while (p != NULL)
	{
		cout << p->getISBN() << " ";
		p = p->getNext();
	}
}