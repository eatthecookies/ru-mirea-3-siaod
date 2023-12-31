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

struct BTree
{
	Node* root = nullptr;			// ������ ������
	int n;							// ���������� ����� ������
};


void addNode(Node* newNode, BTree& tree);
void createBinFile(ifstream& iftxt, ofstream& ofbin);
void outputBinFile(ifstream& ifbin);

void createTreeFromFile(ifstream& ifbin, BTree& tree);
void removeNode(BTree& tree, long long searchKey);
Node* findNode(BTree& tree, long long searchKey);
Owner getOwnerFromFile(int offset, ifstream& ifbin);

void printTree1(Node* node, int level);
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
