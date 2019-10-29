// Implementation for Library

#include "library.h"

//Default constructor. There is no book initially
Library::Library()
{
}

//Copy constructor
//Clone all the books in the existing library rhs and make a new library
Library::Library(const Library & rhs)
{
	first = NULL;
    numOfBooks = 0;

	//Clone all the books in the existing library rhs and make a new library
	//Using insertBook(Book * b) might be easy. For example,
	
	// Book * p = rhs.first;
	// while (p != NULL)
	// {
		// 
		// 
		// 
	// }
}

//Delete all books and make this library empty
Library::~Library()
{
	//You already have makeEmpty() function. Does it help here?
}

void Library::printLibrary()
{
  Book * p = first;
  
  while(p != NULL)
  {
	  cout << p->getISBN() << endl;
	  p = p->getNext();
  }
}


//Delete all books and make this library empty
void Library::makeEmpty()
{
	//You already have deleteBook(int s) function. Does it help here?
}