#include "Airline.h"

Airline::Airline()
{
	pathTaken.clear();
	//pathTaken.resize(1);
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
	//allPathsTaken.at(allPathsTaken.size() - 1).emplace_back(pathTaken[i]);
	//store path from start to end
	for (int i = 0; i < pathTaken.size(); i++)
		allPathsTaken.at(allPathsTaken.size() - 1).emplace_back(pathTaken[i]);

	unique(allPathsTaken.at(allPathsTaken.size() - 1).begin(), allPathsTaken.at(allPathsTaken.size() - 1).end()); //remove any overflow
	allPathsTaken.at(allPathsTaken.size() - 1).shrink_to_fit(); //shrink vector to fit

	//store the distance of this path
	pathDistances.emplace_back(allPathsTaken.at(allPathsTaken.size() - 1).size());
}

void Airline::depthFirstSearch(int vertex, int destination)
{
	//resize the visited bool vector according to the number of edges that vertex has
	vector<bool> visited;
	visited.resize(cityGraph.size());

	//search through edges of given vertex
	pathTaken.emplace_back(cityNameVector[vertex]);
	depthFirstTraversal(vertex, visited, destination);

	sort(pathDistances.begin(), pathDistances.end());

}

void Airline::depthFirstTraversal(int vertex, vector<bool>& visited, int destination)
{
	if (vertex == destination)
	{
		//cout << "A path has been found" << endl << endl;
		//pathTaken.emplace_back(cityNameVector[vertex]); //store end
		saveSearchPath(); //save the path before looking for new paths
		return;
	}

	visited[vertex] = true;

	for (int i = 0; i < cityGraph.at(vertex).size(); i++)
	{
		if (visited[cityGraph[vertex][i] - 1] == false) //if we found a vertex we havent visited, traverse to it
		{
			pathTaken.emplace_back(cityNameVector[cityGraph[vertex][i] - 1]);
			depthFirstTraversal(cityGraph[vertex][i] - 1, visited, destination);
			pathTaken.pop_back();
			visited[vertex] = false;
		}
	}


}

void Airline::printShortestPath(int start, int end)
{
	//cout << cityNameVector[start] << " ---> ";
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

void Airline::clearGraph()
{
}
