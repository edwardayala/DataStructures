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

class Queue
{
public:
	Queue();
	~Queue();

	void enqueue(Book * b);
	void dequeue();
	bool isEmpty();
	void print();
private:
	Book * front;
	Book * rear; 
	int numOfBooks;   
};
