#pragma once
using namespace std;
#include <random>
#include <iostream>





class IBBT
{
private:
	struct Node
	{
		char data;
		Node* left;
		Node* right;
	};

	Node* root;
	int n;

public:
	IBBT(int n);
	void createtree(Node*& root, int n);
	void print();
	void printTree(Node* node, int level);

	char maxLeftNode();

	int findPathLength(Node* node, char targetValue, int currentDepth);
	int getShortestPathLengthToValue(char targetValue);

	char findMaxLeafValue(Node* node);

	char getMaxLeafValue();
};
