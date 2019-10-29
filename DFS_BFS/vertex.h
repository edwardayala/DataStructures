#include <iostream>
#include <string>
using namespace std;

#ifndef _VERTEX_
#define _VERTEX_

//A separate diagram is given for explanation of the following classes
class AdjVertex {
public:
	//Constructor
	AdjVertex( int index, int w ) 
	{ 
		indexOfAdjVertex = index; 
		weight = w;
		next = NULL;
	}
	
	void setNext( AdjVertex * e ) {next = e;}
	AdjVertex * getNext() { return next; }
	int getAdjIndex() {return indexOfAdjVertex; }
	int getWeight() {return weight;}

private:
	int indexOfAdjVertex;  //Index of this adjacent vertex in array vertices
	int weight;			   //weight of an edge
	AdjVertex * next;       //pointer to next adjacent vertex in linked list fashion
};

class Vertex {
public:
	//Constructor
	Vertex( string s )
	{
		info = s;
		mark = false;
		first = NULL;
	}
	
	//Getters and setters
	string getInfo() {return info;}
	AdjVertex * getFirstAdjVertex() {return first;}
	void setAdjVertex( AdjVertex * e ) {first = e;}
	void setInfo ( string s ) { info = s;}

	//Add an adjacent node
	void addAdjVertex(AdjVertex * en );

	void setMark( bool b) { mark = b; }
	bool isMarked() { return mark; }
	void clearMark () { mark = false;}

	//Print the info of an adjacent node
	void print() { cout << info << "->"; }

private:
	string info;       //Vertex info
	bool mark;         //true if this vertex has been visited or brought to stack/queue
	AdjVertex * first;  //Pointer to the first adjacent node
};

#endif




