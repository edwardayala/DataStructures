#include <iostream>
#include <fstream>
#include <string>
#include "maze.h"

using namespace std;

int main()
{
	string mazeDataFile = "mazeData.txt";
	ifstream inData;
	
	//cout << "Enter a Maze data file: " << endl;
	//cin >> mazeDataFile;
	
	inData.open(mazeDataFile);
	Maze mz(inData);
	
	mz.solve();

	return 0;
}

//[1, 5]
//[0, 5]
//[0, 4]
//[0, 3]
//[1, 3]
//[1, 4]
//[2, 4]
//[2, 5]
//[3, 5]
//[4, 5]
//[4, 4]
//[3, 4]
//[3, 3]
//[4, 3]
//[4, 2]
//[4, 1]
//[4, 0]
//[3, 0]
//[3, 1]
//[2, 1]
//[2, 0]
//[1, 0]
//[0, 0]
//Press any key to continue . . .