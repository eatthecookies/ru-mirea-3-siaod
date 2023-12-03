#pragma once
using namespace std;
#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>


class Graph {
public:
	int vertices = 0; // количество узлов
	int edges = 0; // количество ребер

	vector <vector <int>> matrix; // матрица смежности
	Graph(int v, int e);
	void printMatrix(); 
	void graphInsert(int v1, int v2, int w);
	void eulerCycle();
	bool isEulers();

	int primsMinimalTree(vector<int>& visited, vector<int>& unvisited, vector<vector<int>>& minimalTree);


	vector<vector <int>> primsMinimalTree();
};

