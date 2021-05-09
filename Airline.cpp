#include "Airline.h"

Airline::Airline()
{
	pathsTaken.clear();
	pathsTaken.resize(1);
	numPath = 0;
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

	sort(pathDistances.begin(), pathDistances.end());
			
}

void Airline::depthFirstTraversal(int vertex, vector<bool> &visited, int destination)
{
	if (vertex == destination)
	{
		//cout << "Destination Found" << endl;
		pathsTaken.resize(pathsTaken.size() + 1); //create another row
		//pathsTaken.at(numPath).emplace_back(cityNameVector[vertex]); //put destination in path vector
		pathDistances.emplace_back(pathsTaken.at(numPath).size()); //store the distance of this path
		numPath++;
		return;
	}

	visited[vertex] = true;
		
	for (int i = 0; i < cityGraph.at(vertex).size(); i++)
	{
		if (visited[cityGraph[vertex][i]-1] == false) //if we found a vertex we havent visited, traverse to it
		{
			pathsTaken.at(numPath).emplace_back(cityNameVector[vertex]);
			depthFirstTraversal(cityGraph[vertex][i] - 1, visited, destination);
		}
	}

}

void Airline::printShortestPath(int end)
{
	for (int pathNum = 0; pathNum < pathDistances.size(); pathNum++)
	{
		if (pathDistances[0] == pathsTaken.at(pathNum).size())
		{
			for (int i = 0; i < pathsTaken.at(pathNum).size(); i++)
				cout << pathsTaken[pathNum][i] << " ---> ";
			cout << cityNameVector[end] << endl;
			return;
		}
	}
}

void Airline::clearGraph()
{
}
