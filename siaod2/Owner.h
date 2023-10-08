#pragma once
#include <iostream>
#include <string>
using namespace std;



struct Owner
{
	int key = 0;
	string address = " ";
	Owner();
	Owner(int key, string address);
};

struct Table
{
	int n = 0;
	Owner* p = nullptr;
};

Owner binaryOptimizedSearch(Table& table, int key);
Owner linearSearch(Table& table, int key);
Owner barrierSearch(Table& table, int key);

void createTable(Table& table, int n);
void createTableBS(Table& table, int n);

void printTable(Table& table);
