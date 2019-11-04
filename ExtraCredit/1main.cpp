// Name: Edward Ayala
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
	/*Depth-First Search uses Stack
	*	Psuedocode:
	* Starting at the start node
	* start(startNode) - check to see if startNode = searchNode
	* end (searchNode) - end if searchNode is found, saving the path with setMark()
	* using do-while loop
	* push(startNode)
	* do
	*	{ pop()
	*	  if (poppedNode == searchNode){return found;}
	*	  else{ move to next node and repeat until found }
	*	  save the path using push(all - AdjacentNodes)
	*	  repeat in while loop until stack is empty using boolean isEmpty()
	* while(!isEmpty());
	*/
	string from, to;
	Vertex * fVertex;
	Vertex * tVertex;
	int tIndex;
	AdjVertex * adjVertex;
	Stack st;
	g->clearMarks();
	Node * nSource = new Node(source);
	st.push(nSource);
	while (!st.isEmpty())
	{
		from = st.pop();
		fVertex = g->getVertex(from);
		if (!fVertex->isMarked())
		{
			cout << from << " ";
			fVertex->setMark(true);

			adjVertex = fVertex->getFirstAdjVertex();
			while (adjVertex != NULL)
			{
				tIndex = adjVertex->getAdjIndex();
				tVertex = g->getVertex(tIndex);
				if (!tVertex->isMarked())
				{
					Node * dNode = new Node(to);
					to = tVertex->getInfo();
					st.push(dNode);
				}
				adjVertex = adjVertex->getNext();
			}
		}
	}

}


//breadth first search. The function prints out the visit order of vertices
void BFS(Graph * g, string source)
{
	/*Breadth-First Search uses Queue
	*	Psuedocode:
	* Starting at the start node
	* start(startNode) - check to see if startNode = searchNode
	* end (searchNode) - end if searchNode is found, saving the path with setMark()
	* using do-while loop
	* do
	*	{ dequeue() 
	*	  if (dequeuedNode == searchNode){return found;}
	*	  else{ move to next node and repeat until found }
	*	  save the path using enqueue(all - AdjacentNodes)
	*	  repeat in while loop until queue is empty using boolean isEmpty()
	* while(!isEmpty());
	*/

	string from, to;
	Vertex * fVertex;
	Vertex * tVertex;
	int tIndex;
	AdjVertex * adjVertex;
	Queue qu;
	g->clearMarks();
	Node * nSource = new Node(source);
	qu.enqueue(nSource);
	while (!qu.isEmpty())
	{
		from = qu.dequeue();
		fVertex = g->getVertex(from);
		if (!fVertex->isMarked())
		{
			cout << from << " ";
			fVertex->setMark(true);

			adjVertex = fVertex->getFirstAdjVertex();
			while (adjVertex != NULL)
			{
				tIndex = adjVertex->getAdjIndex();
				tVertex = g->getVertex(tIndex);
				if (!tVertex->isMarked())
				{
					Node * dNode = new Node(to);
					to = tVertex->getInfo();
					qu.enqueue(dNode);
				}
				adjVertex = adjVertex->getNext();
			}
		}
	}

}


//find a path from source to destination and distance. Return true if such a path exists, otherwise false.
//You may use either DFS or BFS visit order to find a path from source to destination.
bool findPath(Graph * g, string source, string destination, int & distance, string * path )
{
	Vertex * fVertex;		// vertex pointer for source 
	Vertex * tVertex;		// vertex pointer for destination
	int fIndex, tIndex;		// index of source and destination
	string from, to;		// source, destination
	int numVert = g->getNumVertices();
	distance = 0;
	AdjVertex * adjVertex;

	// Create dynamic array for parents vertice and distance using numOfVertices
	int * vParent = new int[numVert];
	int * vDistance = new int[numVert];

	// initialize vParent and vDistance
	for (int i = 0; i < numVert; i++)
	{
		vDistance[i] = 0;
		vParent[i] = -1;
	}
	
	g->clearMarks();

	Stack st;
	Node * nSource = new Node(source);
	st.push(nSource);

	while (!st.isEmpty())
	{
		from = st.pop();
		fVertex = g->getVertex(from);
		fIndex = g->getIndex(from);
		if (from == destination)
		{
			Stack stPath;
			fIndex = g->getIndex(from);
			while (vParent[fIndex] != -1)
			{
				Node * pNode = new Node(from);
				fVertex = g->getVertex(fIndex);
				from = fVertex->getInfo();				
				stPath.push(pNode);
				distance += vDistance[fIndex];
				fIndex = vParent[fIndex];
			}

			path[0] = source;
			int destinationIndex = 1;
			while (!stPath.isEmpty)
			{
				from = stPath.pop();
				path[destinationIndex] = from;
					destinationIndex++;
			}
			return true;
		}

		adjVertex = fVertex->getFirstAdjVertex();
		while (adjVertex)
		{
			int destinationIndex = adjVertex->getAdjIndex();
			tVertex = g->getVertex(destinationIndex);
			if (!tVertex->isMarked())
			{
				to = tVertex->getInfo();
				st.push(new Node(to));
				vParent[destinationIndex] = fIndex;
				vDistance[destinationIndex] = adjVertex->getWeight();
			}
			adjVertex = adjVertex->getNext();
		}
	}

	return false;
}

//Print a path from source to destination
void printPath(string path[], int n)
{
	for (int i = 0; i < n && path[i] != ""; i++)
		cout << path[i] << endl;
}
