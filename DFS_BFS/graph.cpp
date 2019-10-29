#include "vertex.h"
#include "graph.h"

//Add an adjacent vertex pointed by en to graph
void Vertex::addAdjVertex(AdjVertex * en)
{

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

}

//Add vertex v to the graph 
void Graph::addVertex(Vertex * v)
{

}

//Given info of source and destination nodes and weight, 
//create an edge node and then add to graph by calling function addAdjVertex
void Graph::addEdge(string from, string to, int weight)
{
	int fromIndex = getIndex( from );
	int toIndex = getIndex ( to );
	
	//Create a new edge node and add into this graph

}

//get the corresponding index in array vertices given vertex string name
//If there is no such a vertex, return -1.
int Graph::getIndex( string st) {
	

}

//Set all vertices as unvisited
void Graph::clearMarks()
{

}



