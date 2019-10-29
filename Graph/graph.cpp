// Name: Edward Ayala
#include "vertex.h"
#include "graph.h"

//Add an adjacent vertex pointed by en to graph
void Vertex::addAdjVertex(AdjVertex * en)
{
	if (!first)
	{
		first = en;	// if first is NULL, first = en
	}
	else
	{
		AdjVertex * n = first;	// temp-pointer
		while (n->getNext())	// while loop to find NULL vertex
		{
			n = n->getNext();
		}
		n->setNext(en);		// once n->next is NULL, set next to 'en'
	}
}

//Constructor that creates a graph with to up 100 nodes 
//(default value for the number of nodes = 100)
Graph::Graph()
{
	numVertices = 100;
	vertices = new Vertex * [ numVertices ];
	counter = 0;
}

//Constructor that creates a graph with max = nodes
Graph::Graph(int max)
{
	// create an array of pointers to the vertices in a graph
	numVertices = max;
	vertices = new Vertex * [max];
	counter = 0;
}

//Add vertex v to the graph
void Graph::addVertex(Vertex * v)
{
	
	if (counter < numVertices)
	{
		vertices[counter] = v;
		counter++;
	}
}

//Given info of source and destination nodes and weight, 
//create an edge node and then add to graph by calling function addAdjVertex
void Graph::addEdge(string from, string to, int weight)
{
	int fromIndex = getIndex( from );
	int toIndex = getIndex ( to );
	
	//Create a new edge node and add into this graph
	if (fromIndex != -1 && toIndex != -1)
	{
		AdjVertex * edgeNode = new AdjVertex(toIndex, weight);
		vertices[fromIndex]->addAdjVertex(edgeNode);
	}
}

//get the corresponding index in array vertices given vertex string name
//If there is no such a vertex, return -1.
int Graph::getIndex( string st) 
{
	int index = 0;

	while (!(st == vertices[index]->getInfo()))
		index++;
	return index;
	if (index > getNumVertices())
		return -1;
}

//Set all vertices as unvisited
void Graph::clearMarks()
{
	for (int  i = 0; i < counter; i++)
	{
		vertices[i]->clearMark();
	}
}



