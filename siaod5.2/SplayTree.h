#pragma once
using namespace std;
#include <random>
#include <iostream>

struct Owner // ������ � �����
{
	long long key = 0;
	char address[100];
};

struct Node
{
	long long key = 0;  // ����
	int position;		// ������� � �����

	Node* left = nullptr;
	Node* right = nullptr;
};

struct SplayTree
{
	Node* root = nullptr;			// ������ ������
	int n;							// ���������� ����� ������
};


void createBinFile(ifstream& iftxt, ofstream& ofbin);
void outputBinFile(ifstream& ifbin);

void createTreeFromFile(SplayTree& tree, ifstream& ifbin);

void addNode(Node* newNode, SplayTree& tree);
void removeNode(SplayTree& tree, long long searchKey);
Node* findNode(SplayTree& tree, long long searchKey);


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
