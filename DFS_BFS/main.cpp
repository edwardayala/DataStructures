#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
#include "stackqueue.h"

using namespace std;

// forward function declarations
void setUpGraph(Graph * & g, ifstream & inData);
void DFS(Graph * g, string source);
void BFS(Graph * g, string source);
bool findPath(Graph * g, string source, string destination, int & distance, string * path );
void printPath(string path[], int n);

int main ()
{
	string source = "Austin";
	string dest = "Washington";
	ifstream inData;
	inData.open("graph.dat");
	
	Graph * g = NULL;
	setUpGraph(g, inData);

	cout << "\nThe result of DFS visit of the graph starting from vertex " << source << ":" << endl;
    DFS(g, "Austin");
	cout << endl;
	
	cout << "\nThe result of BFS visit of the graph starting from vertex " << source << ":" << endl;
	BFS(g, "Austin");
	cout << endl;

	int dist; //Distance from vertex s to y
	int numVertices = g->getNumVertices();
	string * p = new string[numVertices]; //A path from source to destination

	cout << "\nA path from vertex " << source << " to vertex " << dest << ": " << endl;
	cout << (findPath(g, source, dest, dist, p)? "has been found." : "has not been found.") << endl;
	cout << "The path is ";
	printPath(p, numVertices);
	cout << " and distance is " << dist << endl;

	return 0;
}

//Set up a graph. The graph data is stored in a file pointed by input file stream "inData"
void setUpGraph(Graph * & g, ifstream & inData)
{
	//Input data format
	//An integer (The number of vertices)
	//A list of strings for the info of the vertices
	//Source Destination Weight for each edge

	//Example:
	//7
	//Atlanta Austin Chicago Dallas Denver Houston Washington
	//Atlanta Washington 800
	//Austin Dallas 260
	//Austin Houston 180
	//Chicago Denver 900
	//Dallas Chicago 540
	//Dallas Denver 810
	//Denver Atlanta 1200
	//Houston Atlanta 950 

	//The number of vertices in the graph
	int numVertices;

	inData >> numVertices;
	cout << "The number of vertices is " << numVertices << endl;
	g = new Graph( numVertices );

	//Add vertices into the graph
	cout << "The vertices are: " << endl;
	 for ( int i = 0; i < numVertices; i++ )
	 {
		 string info;
		 inData >> info;
		 cout << info << endl;
		 Vertex * v = new Vertex (info);
		 g->addVertex(v);
	 }

	 string from, to;
	 int weight;

	cout << "The edges are: " << endl;
	 inData >> from >> to >> weight;
	 while (inData)
	 {
		 g->addEdge(from, to, weight);
		 cout << from <<" "<< to << " "<< weight << endl;
		 inData >> from >> to >> weight;
	 }
}

//depth first search. The function prints out the visit order of vertices
void DFS(Graph * g, string source)
{	
	//Clear the marks for all vertices
	g->clearMarks();
	
}

//breadth first search. The function prints out the visit order of vertices
void BFS(Graph * g, string source)
{
	//Clear the marks for all vertices
	g->clearMarks();
	
}

//find a path from source to destination and distance. Return true if such a path exists, otherwise false.
//You may use either DFS or BFS visit order to find a path from source to destination.
bool findPath(Graph * g, string source, string destination, int & distance, string * path )
{

}

//Print a path from source to destination
void printPath(string path[], int n)
{

}
