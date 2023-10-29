#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Owner
{
	long long key = 0;
	char FIO[11] = "I.A.Ivanov";
	char address[20] = "lorem-ipsum-adress";
};


struct Titem
{
	long long key = 0;
	char FIO[11];
	char address[20];

	bool isOpen = false; // ������� �������� ��� ������� ������
	bool isDeleted = false;
};

struct HashTable {
	int length;		// ����� �������
	int numClosed = 0;	// ���������� �������� ������� �������
	vector <Titem> values;	// �������

	HashTable(int length);
};



void createBinFile(ifstream& iftxt, ofstream& ofbin);
void outputBinFile(ifstream& ofbin);

void outputTable(HashTable& table);
void fillTable(HashTable& table, ifstream& ofbin);

int hashFunction(long long,int);
int hashFunction2(long long, int);

void insertItem(Titem item, HashTable& Table);
int findValue(HashTable& table, int key);
int deleteValue(HashTable& table, int key);