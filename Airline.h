#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class Airline
{

public:
	Airline();
	~Airline();


	bool isEmpty() const;
	void printGraph(int start, int end);

	void createGraph(),
		clearGraph(),
		depthFirstTraversal(int vertex, vector<bool>& visited, int destination),
		depthFirstSearch(int vertex, int destination);

private:
	int gSize; //current num of verticies
	vector<string>cityNameVector;
	vector<vector<int>>cityGraph;


};

