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

	al.depthFirstSearch(startPoint-1, endPoint-1);
	al.printGraph(startPoint-1, endPoint-1);

	return 0;
}