#include "Airline.h"

Airline::Airline()
{
	pathTaken.clear();
	allPathsTaken.clear();
	gSize = 0;
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
	cityGraph.resize(row);
	cout << "ADJACENCY LIST: " << endl << endl;
	for (size_t i = 0; i < cityGraph.size(); i++)
	{
		cout << "(" << i + 1 << ") " << cityNameVector[i] << "------";
		for (size_t j = 0; j < cityGraph.at(i).size(); j++)
		{
			cout << cityGraph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "-----------------------" << endl << endl;

}

void Airline::saveSearchPath()
{
	allPathsTaken.resize(allPathsTaken.size() + 1); //make a row for a new path to be saved

	for (int i = 0; i < pathTaken.size(); i++)
		allPathsTaken.at(allPathsTaken.size() - 1).emplace_back(pathTaken[i]);

	//store the distance of this path
	pathDistances.emplace_back(allPathsTaken.at(allPathsTaken.size() - 1).size());
}

void Airline::depthFirstSearch(int vertex, vector<bool>& visited, int destination)
{
	if (vertex == destination)
	{
		saveSearchPath(); //save the path before looking for new paths
		return;
	}

	visited[vertex] = true;

	for (int i = 0; i < cityGraph.at(vertex).size(); i++)
	{
		if (visited[cityGraph[vertex][i] - 1] == false && pathTaken.size() <= cityGraph.size()) //if we found a vertex we havent visited and we arent repeatedly going over vertecies, traverse to it
		{
			pathTaken.emplace_back(cityNameVector[cityGraph[vertex][i] - 1]); //store the next city in the path
			depthFirstSearch(cityGraph[vertex][i] - 1, visited, destination); //recursively pass in the vertex that was just traversed to
			pathTaken.pop_back();
			visited[vertex] = false;
		}
	}


}

void Airline::printShortestPath(int start, int end) //prints the shortest path recorded
{
	for (int pathNum = 0; pathNum < pathDistances.size(); pathNum++)
	{
		if (pathDistances[0] == allPathsTaken.at(pathNum).size())
		{
			for (int i = 0; i < allPathsTaken.at(pathNum).size(); i++)
			{
				if (i > 0)
					cout << " ---> ";
				cout << allPathsTaken[pathNum][i];
			}
			cout << endl;
			
			break;
		}

	}
}

