#include "maze.h"
#include "stack.h"

Maze::Maze(ifstream & in)
{
	int rEntry, cEntry;
	int rExit, cExit;

	int d;
	
	//Read rows and columns of this maze
	in >> rows >> cols;
	
	//Create a 2D array of pointers to cells
	cells = new Cell ** [rows];
	
	for (int i = 0; i < rows; i++)
		cells[i] = new Cell * [cols];

	//Read entry and exit cell coordinates
	in >> rEntry >> cEntry;
	in >> rExit >> cExit;

	//Create cell objects for this maze as reading goes
	//Don't forget assigning the entry and exit cells

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			//Implementation here
			in >> d;
			cells[i][j] = new Cell(i, j, d);
		}
		entryCell = cells[rEntry][cEntry];
		exitCell = cells[rExit][cExit];
}

//Solve the maze
void Maze::solve()
{
	bool north, east, south, west; //Which of four doors are open
	bool solved = false;		   //The maze has not been solved yet
	Stack st;					//Create a Stack object
	
	//Algorithm is below:

	//Push entry cell on the stack
	Node * nd = new Node(entryCell);
	st.push(nd);
	
	//Start searching the exit cell. A loop start here.
	while(!st.isEmpty())
	{
		//Take the top node out of the stack
		Cell * c = st.pop();
		//If it is the exit cell, the maze has been solved and stop!
		if (c == Maze::exitCell)
		{
			solved = true;
			break;
		}
		//Otherwise, push all reachable neighbors of the cell on the stack
		//You may need this: Decode which doors are open to neighbor cells using bit-wise AND operation
        north = (c->getOpenDoors() & 0x01) != 0; 
		east =  (c->getOpenDoors() & 0x02) != 0;
		south = (c->getOpenDoors() & 0x04) != 0;
		west =  (c->getOpenDoors() & 0x08) != 0;

		if (north)
		{
			Cell * neighbor = cells[c->getCoordinate().getX() - 1][c->getCoordinate().getY()];
			if (!neighbor->isVisited())
			{
				Node * nd = new Node(neighbor);
				st.push(nd);
				neighbor->setParent(c);
			}
			c->setVisited();
		}
		if (east)
		{
			Cell * neighbor = cells[c->getCoordinate().getX()][c->getCoordinate().getY() + 1];
			if (!neighbor->isVisited())
			{
				Node * nd = new Node(neighbor);
				st.push(nd);
				neighbor->setParent(c);
			}
			c->setVisited();
		}
		if (south)
		{
			Cell * neighbor = cells[c->getCoordinate().getX() + 1][c->getCoordinate().getY()];
			if (!neighbor->isVisited())
			{
				Node * nd = new Node(neighbor);
				st.push(nd);
				neighbor->setParent(c);
			}
			c->setVisited();
		}
		if (west)
		{
			Cell * neighbor = cells[c->getCoordinate().getX()][c->getCoordinate().getY() - 1];
			if (!neighbor->isVisited())
			{
				Node * nd = new Node(neighbor);
				st.push(nd);
				neighbor->setParent(c);
			}
			c->setVisited();
		}
		

	}//End of loop

	if (solved)
		printDirections();

	//If variable "solved" is true, the maze was solved.
	//Print out the path backward starting from the exit cell to entry cell 
	//by backtracking parent of each cell on the path.

	//Otherwise, print out a message that says "The maze cannot be solved.
}



Cell::Cell(int x, int y, int d) : coord(x, y) //An initializer is needed here
{
	openDoors = d;
	visited = false;
	parent = NULL;
}
