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
	int position;
	bool isOpen = true; // признак открытой для вставки ячейки
	bool isDeleted = false;
};

struct HashTable {
	int length;		// длина таблицы
	int numClosed = 0;	// количество закрытых адресов таблицы
	vector <Titem> values;	// таблица

	HashTable(int length, ofstream& ofbin);
};



void createBinFile(ifstream& iftxt, ofstream& ofbin);
void outputBinFile(ifstream& ofbin);

void outputTable(HashTable& table);
void fillTable(HashTable& table, ifstream& ifbin, ofstream& ofbin);

int hashFunction(long long, int);
int secondHashFunction(long long, int);

void insertItem(Titem item, HashTable& Table, ofstream& ofbin);
int findValue(HashTable& table, long long key);
int deleteValue(HashTable& table, long long key, ifstream& ifbin);
void rehashTable(HashTable& table);