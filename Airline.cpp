#include "Airline.h"

Airline::Airline()
{
	

}

Airline::~Airline()
{
}

bool Airline::isEmpty() const
{
	return false;
}

void Airline::createGraph()
{
	int numVerticies = 0, row = 0, currentVertex;

	//string source = "";
	string currCity = "";

	//cout << "Enter name for network file: ";
	//cin >> source;
	ifstream inFile("NetworkFile.txt");

	while (!inFile.eof() && inFile >> currCity)
	{
		cityNameVector.emplace_back(currCity);
		inFile >> gSize;
		cityGraph.resize(cityGraph.size() + 1);

		for (size_t i = 0; i < gSize; i++)
		{
			inFile >> currentVertex;
			cityGraph.at(row).emplace_back(currentVertex);
		}

		row++;
	}

	/*for (int i = 0; i < row; i++)
	{
		cityGraph.at(i).resize(row);
	}*/

	cout << "ADJACENCY LIST: " << endl << endl;
	for (size_t i = 0; i < cityGraph.size(); i++)
	{
		cout << "(" << i+1 << ") " << cityNameVector[i] << "------";
		for (size_t j = 0; j < cityGraph.at(i).size(); j++)
		{
			cout << cityGraph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "-----------------------" << endl << endl;

}

void Airline::depthFirstSearch(int vertex, int destination)
{

	//resize the visited bool vector according to the number of edges that vertex has
	vector<bool> visited(cityGraph.size(),false);

	//search through edges of given vertex
	for (int i = 0; i < visited.size(); i++)
		if (visited[i] == false)
			depthFirstTraversal(vertex, visited, destination);
			
}

void Airline::depthFirstTraversal(int vertex, vector<bool> &visited, int destination)
{
	visited[vertex] = true;

	cout << cityNameVector[vertex] << " --------> ";

	if (vertex == destination)
	{
		cout << "END" << endl;
		exit(EXIT_SUCCESS);
	}
		
	for (int i = 0; i < cityGraph.at(vertex).size(); i++)
	{
		if (visited[cityGraph[vertex][i]-1] == false) //if we found a vertex we havent visited, traverse to it
		{
			depthFirstTraversal(cityGraph[vertex][i] - 1,  visited, destination);
		}
	}

	
	//start at vertex equal to parameter start
	//traverse an edge
	//when we traverse to a node, we must mark it as visited
	//traverse to the first edge of the vertex we just traveled to
	//continue this process until we reach a dead end
	//once we reach a dead end, recursively visit all other nodes and traverse the vertecies we havent visited

}

void Airline::printGraph(int start, int end)
{
	cout << "-------------------------------" << endl << endl;
	//cout << "Shortest Path from " << cityNameVector[start] << " to " << cityNameVector[end] << " has been found " << endl;
}

void Airline::clearGraph()
{
}
