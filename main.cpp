#include "Airline.h"

int main()
{
	char c;
	do
	{
		system("cls");

		Airline al;

		int startPoint, endPoint;
		al.createGraph();

		cout << "Enter Start: ";
		cin >> startPoint;
		cout << "\nEnter Destination: ";
		cin >> endPoint;
		cout << endl;

		//resize the visited bool vector according to the number of edges that vertex has
		vector<bool> visited;
		visited.resize(al.cityGraph.size());

		//search through edges of given vertex
		al.pathTaken.emplace_back(al.cityNameVector[startPoint - 1]);
		al.depthFirstSearch(startPoint - 1, visited, endPoint - 1);

		sort(al.pathDistances.begin(), al.pathDistances.end());

		al.printShortestPath(startPoint - 1, endPoint - 1);

		
		cout << "\nWould you like to find another path? (Y/N)" << endl;
		cin >> c;
	} while (c == 'Y' || c == 'y');

		return 0;
}