#define _CRT_SECURE_NO_WARNINGS
#include "Owner.h"
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

void createBinFile(ifstream& iftxt, ofstream& ofbin)
{
	Owner owner;
	int key;
	while (!iftxt.eof())
	{
		iftxt >> owner.key;
		iftxt >> owner.FIO >> owner.address;
		ofbin.write((char*)(&owner), sizeof(Owner));
	}
	ofbin.close();
	iftxt.close();
}


void outputBinFile(ifstream& ifbin)
{
	if (!ifbin.is_open()) {
		cout << "Не удалось открыть файл: " << endl;
		return;
	}
	Owner value;

	while (ifbin.read((char*)&value, sizeof(Owner)))
	{
		string s = value.address;

		if (s != "")
			cout << value.key << " " << value.FIO << " " << value.address << endl;
	}

	if (!ifbin.eof() && ifbin.fail()) {
		cout << "Ошибка чтения из файла." << endl;
	}

	ifbin.close();
}

 

int hashFunction(long long key, int length)
{
	return key % length;
}

int secondHashFunction(long long key, int length)
{
	return 1 + (key % (length - 1));
}

void insertItem(Titem item, HashTable& table)
{
	int index = hashFunction(item.key, table.length);
	
	int i = 1;
	while (table.values[index].isOpen == false){
		index = (hashFunction(item.key, table.length) + i * secondHashFunction(item.key, table.length)) % table.length ;
		i++;
	}
	
	if (index < table.length)
	{
		table.values[index] = item;
		table.numClosed++;
	}
}

int findValue(HashTable& table, int key)
{
	int index = hashFunction(key, table.length);


	int i = 1;
	while (!table.values[index].isDeleted && !table.values[index].isOpen && (table.values[index].key != key))
	{
		index = (hashFunction(key, table.length) + i * secondHashFunction(key, table.length)) % table.length;
		i++;
	}

	if (table.values[index].isDeleted && table.values[index].isOpen)
		return -1;
	else
		return index;
}

int deleteValue(HashTable& table, int key)
{
	int index = findValue(table, key);

	table.values[index].isDeleted = true;
	table.values[index].isOpen = true;
	table.numClosed--;
	return 0;
}

void rehashTable(HashTable& table, int key)
{


}

void outputTable(HashTable& table)
{
	for (int i = 0; i < table.length; i++)
	{
		cout << left<< setw(4)  << i << " " << table.values[i].key << "  " << table.values[i].FIO << "  " << table.values[i].address << endl;
	}

}

void fillTable(HashTable& table, ifstream& ifbin)
{
	if (!ifbin.is_open()) {
		cout << "Не удалось открыть файл: " << endl;
		return;
	}
	Owner value;
	Titem item;

	for (int i = 0; i < table.length; i++)
	{
		if (ifbin.read((char*)&value, sizeof(Owner))) {
			item.key = value.key;
			item.isOpen = false;
			strcpy(item.FIO, value.FIO);
			strcpy(item.address, value.address);
			insertItem(item, table);
		}
		
	}


	if (!ifbin.eof() && ifbin.fail()) {
		cout << "Ошибка чтения из файла." << endl;
	}

	ifbin.close();
}

HashTable::HashTable(int length) {
	this->length = length;
	values.resize(length);
}
