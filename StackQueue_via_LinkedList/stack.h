//Linked list implementation of Stack

#include <iostream>
using namespace std;

class Cell;

class Node
{
public:
	//public functions
private:
	Cell *  info;
	Node * next;
};

//stack 
class Stack {
public:
	Stack(){top = NULL;}
	void push(Node * nd);
	Cell *  pop();
	bool isEmpty();
private:
	Node * top;
};