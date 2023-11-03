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
			cout << value.key << " " << left << setw(20) << value.FIO << " " << value.address << endl;
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
		if (i > 10) index++;
		i++;
	}
	
	if (index < table.length)
	{
		item.isOpen = false;
		table.values[index] = item;
		table.numClosed++;
	}

	if (((double)table.numClosed / table.length) >= 0.75) {
		cout << "Было произведено рехеширование при k = " << ((double)table.numClosed / table.length) << endl;
		rehashTable(table);
	}
}

int findValue(HashTable& table, long long key)
{
	int index = hashFunction(key, table.length);


	int i = 1;

	while (true) {
		if ((table.values[index].key == key)) {
			break;
		}
		else if (table.values[index].isOpen) {
			if (table.values[index].isDeleted) {
				index = (hashFunction(key, table.length) + i * secondHashFunction(key, table.length)) % table.length;
				if (i > 10) index++;
				i++;
			}
			else
				break;
		}
		else {
			index = (hashFunction(key, table.length) + i * secondHashFunction(key, table.length)) % table.length;
			if (i > 10) index++;
			i++;
		}
		
		
	}

	if (table.values[index].isDeleted || table.values[index].isOpen)
		return -1;
	else
		return index;
}

int deleteValue(HashTable& table, long long key)
{
	int index = findValue(table, key);

	table.values[index].isDeleted = true;
	table.values[index].isOpen = true;
	table.numClosed--;
	return 0;
}

void rehashTable(HashTable& table)
{
	table.length *= 2;

	vector <Titem> newValues;
	newValues.resize(table.length);

	for (Titem item : table.values) {
		if (!item.isDeleted) {
			int index = hashFunction(item.key, table.length);

			int i = 1;
			while (newValues[index].isOpen == false) {
				index = (hashFunction(item.key, table.length) + i * secondHashFunction(item.key, table.length)) % table.length;
				if (i > 10) index++;
				i++;
			}

			newValues[index] = item;
		}
	}

	table.values = newValues;
}

void outputTable(HashTable& table)
{
	for (int i = 0; i < table.length; i++)
	{
		if (table.values[i].key!= 0 and !table.values[i].isDeleted)
		{
			cout << left << setw(4) << i << " " << table.values[i].key << "  " << left << setw(20) << table.values[i].FIO << "  " << table.values[i].address << endl;
		}
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

	while(true)
	{
		if (ifbin.read((char*)&value, sizeof(Owner))) {
			if (value.key != item.key) {
				item.key = value.key;
				strcpy(item.FIO, value.FIO);
				strcpy(item.address, value.address);
				insertItem(item, table);
			}
		}
		else 
			break;
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
