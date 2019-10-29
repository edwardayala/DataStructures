// Name: Edward Ayala
#include "vertex.h"

#ifndef _GRAPH_
#define _GRAPH_

class Graph
{
public:
  Graph();
  Graph(int max);
  ~Graph(){}

  void addVertex(Vertex * );
  void addEdge(string from, string to, int weight);
  int  getNumVertices() {return counter;}
  int  getIndex( string st);
  Vertex * getVertex(int index) { return vertices[index]; }
  Vertex * getVertex(string st) 
  { 
	  int index = getIndex(st);
	  return vertices[index];
  }
  void clearMarks();

private:
  int numVertices;				//number of vertices declared
  Vertex ** vertices;		//array of pointers to vertices
  int counter;					//number of vertices added into this graph at a point of time
};

#endif