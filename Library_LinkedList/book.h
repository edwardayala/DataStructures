//Linked list implementation for library and books

#include <iostream>
using namespace std;

class Book
{
public:
	Book(int s);

	//Getters and setters
	int getISBN();
	Book * getNext();
	void setISBN(int s);
	void setNext(Book * b);
    void print(std::ostream & out) const;

private:
    int isbn;
    Book * next;    //Pointer to next book
};

