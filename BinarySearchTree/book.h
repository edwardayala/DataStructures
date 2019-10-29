#include <iostream>
using namespace std;

typedef int ItemType;

//Ensure class Book being included only once 
#ifndef _BOOK_
#define _BOOK_

class Book
{
public:
	//constructors. Note that initializers are used.
	Book(): leftChild(NULL), rightChild(NULL) {}
	Book( ItemType nm ) : info(nm), leftChild(NULL), rightChild(NULL) {}

	//destructor
	~Book() {}

	//public functions
	ItemType getInfo(){ return info; }
	Book * getLeftChild(){ return leftChild; }
	Book * getRightChild(){ return rightChild; }
	void setInfo(ItemType item){ info = item; }
	void setLeftChild(Book * lc){ leftChild = lc; }
	void setRightChild(Book * rc){ rightChild = rc; }
	void print() { cout << info << "->" ;}

private:
	ItemType info;
	Book * leftChild;
	Book * rightChild;
};

#endif


