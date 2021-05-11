#include "Airline.h"

int main()
{

	string source = "";
	cout << "Enter name for network file: ";
	cin >> source;

	Airline* al = new Airline();

	while (al->run(source)) //driver
		al = new Airline();

	return 0;
}