#include "tree.h"

int main()
{
	Tree bst;
	Node * start = bst.getRoot();

	Node * td = new Node(5);
	bst.insert(start, td);

	td = new Node(9);
	bst.insert(start, td);

	td = new Node(7);
	bst.insert(start, td);

	td = new Node(3);
	bst.insert(start, td);

	td = new Node(8);
	bst.insert(start, td);

	bst.print(start);

	return 0;
}