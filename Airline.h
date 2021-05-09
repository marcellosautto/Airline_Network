#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class Airline
{

public:
	Airline();
	~Airline();


	bool isEmpty() const;
	void printShortestPath(int end);

	void createGraph(),
		clearGraph(),
		depthFirstTraversal(int vertex, vector<bool>& visited, int destination),
		depthFirstSearch(int vertex, int destination);

private:
	int gSize; //current num of verticies
	int numPath;
	vector<string>cityNameVector;
	vector<vector<int>>cityGraph;
	vector<vector<string>>pathsTaken;
	vector<int>pathDistances;
	


};

