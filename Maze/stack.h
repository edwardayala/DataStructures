//Linked list implementation of Stack

#include <iostream>
using namespace std;

class Cell;

class Node
{
public:
	//public functions
	Node(Cell * c)
	{
		info = c;
		next = NULL;
	}

	Cell * getINFO()
	{
		return info;
	}

	Node * getNext()
	{
		return next;
	}

	void setINFO(Cell * i)
	{
		info = i;
	}

	void setNext(Node * nxt)
	{
		next = nxt;
	}

private:
	Cell *  info;
	Node * next;
};

//stack 
class Stack {
public:
	Stack(){top = NULL;}
	void push(Node * nd)
	{
		nd->setNext(top);
		top = nd;	
	}
	Cell *  pop()
	{
		Node * p = top;
		top = top->getNext();
		delete p;
		return p->getINFO();
	}
	bool isEmpty()
	{
		return (top == NULL);
	}
private:
	Node * top;
};