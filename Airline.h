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


	bool run(string source);
	void printShortestPath(int start, int end);

	void createGraph(),
		printAdjList(),
		depthFirstSearch(int vertex, vector<bool>& visited, int destination),
		saveSearchPath();

	int gSize; //current num of verticies
	ifstream inFile;
	vector<string>cityNameVector;
	vector<vector<int>>cityGraph;
	vector<string>pathTaken;
	vector<vector<string>> allPathsTaken;
	vector<int>pathDistances;
	


};

