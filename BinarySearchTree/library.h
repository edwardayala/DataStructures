#include "book.h"

#ifndef _LIBRARY_
#define _LIBRARY_

class Library
{
public:
	//Constructor
	Library(): root(NULL) {}

	//Destructor
	~Library(){}

	//Return the number of nodes in the tree
	int lengthIs() const;

	//Return the height of the tree
	int heightIs() const;
	
	//Return the node with maximum key value in the tree
	Book * getMaxBook() const;

	//Search a node with key value of item and return search result through boolean found
	void retrieveBook(ItemType item, bool & found) const;

	//Insert a book b into the library
	void insertBook(Book * b);

	//Delete a book with isbn of item
	void deleteBook(ItemType item);

	//Print the tree in three orders
	void printInOrder() const;
	void printPreOrder() const;
	void printPostOrder() const;

private:
	Book * root;
};

#endif