#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Cell;

//Coordinate for cell
class Coordinate
{
public:
	Coordinate(int x, int y) {_x = x; _y=y;}
	int getX() {return _x;}
	int getY() {return _y;}
private:
	int _x;
	int _y;
};

//Maze
class Maze
{
public:
	Maze(ifstream & in);
	void solve();
	void printDirections(); //Print out the coordinates of the cells on the path starting the exit cell.
	
private:
	int rows;				//The number of rows of this maze
	int cols;				//The number of columns of this maze
	Cell * entryCell;		//Entry Cell of this maze
	Cell * exitCell;		//Exit Cell of this maze
	Cell *** cells;			//2 dimensional array of pointers to cells
};

//Cell
class Cell
{
public:
	Cell(int x, int y, int doors);
	Coordinate getCoordinate();
	void setVisited();				//Set visited as true
	void setParent(Cell * p);
	Cell * getParent();
	bool isVisited();				//Return true if visited is true
	int getOpenDoors();
private:
	bool visited;		//0 -- not been visited; 1 -- been visited
	Cell * parent;		//The cell from which this cell is reached
	int openDoors;      //coding value 0..15 based on the bits of the open doors of this cell 
	Coordinate coord;	//Coordinate of this cell
};

