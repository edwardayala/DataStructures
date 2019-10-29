#include <string>
using namespace std;

//Node used for stack and queue only
class Node
{
public:
	Node (string f) {info = f; next = NULL;}
	string getInfo() {return info;}
	Node * getNext() { return next;}

	void setInfo(int f) {info = f;}
	void setNext(Node * nd) {next = nd;}
private:
	string info;      //Store the info of a vertex
	Node * next;	  //Pointer to next node in linked list.
};

//Stack. FILO.
//Linked list implementation
class Stack {
public:
	Stack(){top = NULL;}
	void push(Node * nd);
	string pop();
	bool isEmpty();
private:
   Node * top;   //Pointer to the top node
};

//Queue. FIFO
//Linked list implementation
class Queue {
public:
	Queue() {front = NULL; rear = NULL;}
	void enqueue(Node * nd);
	string dequeue();
	bool isEmpty();
private:
   Node * front;    //Pointer to the front node
   Node * rear;     //Pointer to the rear node
};

