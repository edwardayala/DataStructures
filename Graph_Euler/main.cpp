#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
#include "stackqueue.h"

using namespace std;

// forward function declarations
void setUpGraph(Graph * & g, ifstream & inData);
bool findEulerCircuit(Graph * g, string start, string * circuit, int & num );
void printEulerCircuit(string path[], int n);

int main ()
{
	string source = "a";
	int numOfVertiecsOnEulerCircuit;                     //The number of vertices on an Euler circuit
	ifstream inData;
	inData.open("graph1.dat");
	
	Graph * g = NULL;
	setUpGraph(g, inData);

	int numVertices = g->getNumVertices();
	//The maximum total number of times the vertices on an Euler circuit could be visited (including being visited repeatedly), mv, is related to 
	//the total number of edges (|E|) in an undirected graph. Given an undirected graph of |V| vertices, the maximum total number of edeges the graph 
	//could have is me = |V|*(|V|-1)/2, that is, the cases of complete graphs.  Therefore, mv <= 2*me = |V|*(|V|-1)

	string * ec = new string[numVertices*(numVertices-1)]; //A sequence of the vertices on an Euler circuit

	cout << "\nAn Euler circuit from vertex " << source ;
	cout << (findEulerCircuit(g, source, ec, numOfVertiecsOnEulerCircuit)? " has been found." : " has not been found.") << endl;
	cout << "The circuit is: " << endl;
	printEulerCircuit(ec, numOfVertiecsOnEulerCircuit);

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
	 //cout << from <<" "<< to << " "<< weight << endl;
	 while (inData)
	 {
		 g->addEdge(from, to, weight);
		 cout << from <<" "<< to << " "<< weight << endl;
		 inData >> from >> to >> weight;
	 }
}


//find an Euler circuit from source. Return true if such a circuit exists, otherwise false.
//start is the info of starting vertex
//circuit is an array of vertices on an Euler circuit
//num is the number of vertices on an Euler circuit
bool findEulerCircuit(Graph * g, string start, string * circuit, int & num )
{
	//Note that
	//Since the graph is an undirected graph, actually there are two directed edges for each undirected edge.
	//Therefore, when an undirected edge is visited, two directed edges need to be marked as visited.
	
	num = 0;

	//Implementation here
	//...
	return (num > 1) ? true:false;
}

//Print an Euler circuit stored in array c with n vertices (strings)
void printEulerCircuit(string c[], int n)
{
	for (int i = 0; i < n; i++)
			cout << c[i] << "->";

	cout << endl;
}
