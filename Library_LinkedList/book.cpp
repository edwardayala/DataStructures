// Implementation for Library

#include "book.h"

Book::Book(int s)
{
	//Book::Book(s);
	isbn = s;
	next = NULL;
}
void Book::print(ostream & out) const 
{
  out << isbn;
}
int Book::getISBN()
{
	return isbn;
}

Book * Book::getNext()
{
	//Book * next = next;
	return next;
}

void Book::setISBN(int s)
{
	isbn = s;
}
void Book::setNext(Book * b)
{
//	Book * isbn;
	if (next == NULL)
		next = b;
	else
		next = b->next;
//	isbn = b;
}