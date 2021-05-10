#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;
class Airline
{

public:
	Airline();
	~Airline();


	bool isEmpty() const;
	void printShortestPath(int start, int end);

	void createGraph(),
		depthFirstSearch(int vertex, vector<bool>& visited, int destination),
		saveSearchPath();

	int gSize; //current num of verticies
	vector<string>cityNameVector;
	vector<vector<int>>cityGraph;
	vector<string>pathTaken;
	vector<vector<string>> allPathsTaken;
	vector<int>pathDistances;
	


};

