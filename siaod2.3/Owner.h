#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <fstream>
#include <cmath>

struct Titem
{
	unsigned int key = 0;
	char address[20] = "lorem-ipsum-adress";
};

struct TableItem
{
	unsigned int key = 0;
	int offset;
};

void createTable(vector<TableItem>& table, ifstream&ifbin);
void createBinFile(ifstream& iftxt, ofstream& ofbin);
void outputBinFile(ifstream& ofbin);
int binaryOptimizedSearch(vector<TableItem>& table, int key);
Titem linearSearch(ifstream& ifbin, unsigned int key);
Titem findByOffset(ifstream& ifbin, int offset);

