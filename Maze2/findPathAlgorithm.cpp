//Find a path from source to destination and distance. Return true if such a path exists, otherwise false.
bool findPath(Graph * g, string s, string d, int & distance, string * path )
{
	//Use either DFS or BFS search order to search the destination from the source.
	//If the destination is reached, search stops right away and print out the search path.

	//Variables needed:
    //An array variable for the parents of the vertices
    //An array variable for the distances between the vertices and their parents
    //Total distance along the path

	//Clear marks as unvisited for all vertices
	//Create a stack
	//Add the source vertex on the stack (as a stack node)
	//Mark it as visited

	//If the stack is not empty
	while(the stack is not empty)
	{
		//Pop the top node from the stack
		//When the destination is reached, backtrack the parents and store in the path.
		if ( the node popped == the destination)
		{
			//Backtrack by following the parents and adding distances

			//Reverse the path so that it lists vertices from the source to the destination
			return true;
		}

		//Find the first adjacent vertex of the vertex just popped
		while (the adjacent node is not NULL)
		{
			if (the adjacent node has not been visited yet)
			{
				//Add to the stack and mark as visited
				//Record its parent and distance to its parent into those arrays
			}
			//Get next adjacent vertex
		}
	}

	return false;  //No path has been found.
}
