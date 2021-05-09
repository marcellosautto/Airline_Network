#include "Airline.h"

int main()
{
	//create graph and store in vector
	//



	Airline al;

	int startPoint, endPoint;
	al.createGraph();

	cout << "Enter Start: ";
	cin >> startPoint;
	cout << "\nEnter Destination: ";
	cin >> endPoint;
	cout << endl;

	al.depthFirstSearch(startPoint-1, endPoint-1);
	al.printShortestPath(endPoint -1);

	return 0;
}