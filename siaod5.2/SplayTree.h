#pragma once
using namespace std;
#include <random>
#include <iostream>

struct Owner // запись в файле
{
	long long key = 0;
	char address[100];
};

struct Node
{
	long long key = 0;  // ключ
	int position;		// позиция в файле

	Node* left = nullptr;
	Node* right = nullptr;
};

struct SplayTree
{
	Node* root = nullptr;			// корень дерева
	int n;							// количество узлов дерева
};

Node* splay(Node* root, int key);
void createBinFile(ifstream& iftxt, ofstream& ofbin);
void outputBinFile(ifstream& ifbin);
void printTree1(Node* node, int level);
void createTreeFromFile(SplayTree& tree, ifstream& ifbin);
Node* splayRotations(Node* root, long long key, int& rotations);
void addNode(Node* newNode, SplayTree& tree);
void removeNode(SplayTree& tree, long long searchKey);
Node* findNode(SplayTree& tree, long long searchKey);
void insert(SplayTree& tree, Node* newNode);
Owner getOwnerFromFile(int offset, ifstream& ifbin);
void insertRotations(SplayTree& tree, Node* newNode, int& rotations);

struct Trunk
{
	Trunk* prev;
	string str;

	Trunk(Trunk* prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

void printTree(Node* root, Trunk* prev, bool isLeft);
