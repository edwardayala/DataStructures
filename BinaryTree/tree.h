#include <iostream>
using namespace std;

class Node
{
public:
	Node(int a)
	{
		info = a;
		left = NULL;
		right = NULL;
	}

	int getInfo() { return info; }
	void setInfo(int s){ s = info; }
	Node * getLeft() { return left; }
	void setLeft(Node * l){ left = l; }
	Node * getRight(){ return right; }
	void setRight(Node * r){ right = r; }
	void print(){cout << info << " ";}
private:
	int info;
	Node * left;
	Node * right;
};

class Tree
{
public:
	Tree()
	{
		root = NULL;
	}
	Node * getRoot(){ return root; }

	// Driver - insert()
	void insert(Node * nd)
	{
		insert(root, nd);
	}
	// Worker - insert()
	void insert(Node *& tree, Node * nd)
	{
		if (tree == NULL)
		{
			tree = nd;
		}
		else
		{
			if (nd->getInfo() > tree->getInfo())
			{
				Node * tr = tree->getRight();
				insert(tr, nd);
				tree->setRight(tr);
			}
			else
			{
				Node * tl = tree->getLeft();
				insert(tl, nd);
				tree->setLeft(tl);
			}
		}
	}

	// Driver - print()
	void print()
	{
		print(root);
	}
	// Worker - print()
	void print(Node * tree)			// Print left, print right, then print root
	{
		if (tree)
		{
			print(tree->getLeft());
			print(tree->getRight());
			tree->print();

		}
	}
private:
	Node * root;
};
