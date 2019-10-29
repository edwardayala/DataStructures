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

	int getInfo()
	{
		return info;
	}
	Node * getLeft()
	{
		return left;
	}
	Node * getRight()
	{
		return right;
	}
	void setLeft(Node * p)
	{
		left = p;
	}

	void setRight(Node * p)
	{
		right = p;
	}
	void print()
	{
		cout << info << " ";
	}
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
	Node * getRoot()
	{
		return root;
	}

	void insert(Node * & tree, Node * nd)
	{
		if (tree == NULL)
		{
			tree = nd;
		}
		else
		{
			if (nd->getInfo() > tree->getInfo())
			{
				Node * p = tree->getRight();
				insert(p, nd);
				tree->setRight(p);
			}
			else
			{
				Node * p = tree->getLeft();
				insert(p, nd);
				tree->setLeft(p);
			}
		}
	}

	void print(Node * tree)
	{
		if (tree)
		{
			print(tree->getLeft());
			tree->print();
			print(tree->getRight());
		}
	}
private:
	Node * root;
};
