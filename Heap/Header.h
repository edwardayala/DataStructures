#include <iostream>

using namespace std;

class Tree
{
public:
	int getInfo(){ return info; }
	void setInfo(int s){ info = s; }
	Tree * getLeftChild(){ return left; }
	void setLeftChild(Tree * l){ left = l; }
	Tree * getRightChild(){ return right; }
	void setRightChild(Tree * r){ right = r; }
private:
	int info;
	Tree * left;
	Tree * right;
};

class Heap
{
	void reHeapUp(int root, int bottom);
	void reHeapDown(int root, int bottom);
	Tree * elements;
	int numOfElements;
};

void reHeapUp(int root, int bottom)
{
	int parent;
	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom])
		{
			swap(elements[parent], elements[bottom]);
			reHeapUp(root, parent);
		}
	}
}

void reHeapDown(int root, int bottom)
{
	int maxChild, rightChild, leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild])
		{
			swap(elements[root], elements[maxChild]);
			reHeapDown(maxChild, bottom);
		}
	}
}

class priorityQ
{
public:
	priorityQ(int max);
	~priorityQ();
	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	void enqueue(Heap h);
	void dequeue(Heap & h);
	int getLength(){ return length; }
	void setLength(int n){ length = n; }
	int getMax(){ return maxItems; }
	void setMax(int s){ maxItems = s; }
	Heap getHeap(){ return heap; }
	void setHeap(Heap s){ heap = s; }
private:
	int length;
	Heap heap;
	int maxItems;
};

priorityQ::priorityQ(int max)
{
	//maxItems = max;
	priorityQ * hpq = new priorityQ(max);
	hpq->setMax(max);
	heap.elements = new Heap[max];
	heap.setLength(0);
}
