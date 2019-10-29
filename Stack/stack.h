#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class Book
{
public:
	Book(int s)
	{
		isbn = s;
		next = NULL;
	}

	int getISBN()
	{
		return isbn;
	}

	Book * getNext()
	{
		return next;
	}

	void setISBN(int s)
	{
		isbn = s;
	}

	void setNext(Book * nt)
	{
		next = nt;
	}
private:
	int isbn;
	Book * next;
};

class Stack
{
public:
	Stack();
	~Stack();

	void push(Book * b);
	void pop();
	bool isEmpty();
	void print();
private:
	Book * top; 
	int numOfBooks;   
};