#define _CRT_SECURE_NO_WARNINGS
#include "Owner.h"
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

void createBinFile(ifstream& iftxt, ofstream& ofbin)
{
	Titem owner;
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
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	Titem item;

	while (ifbin.read((char*)&item, sizeof(Titem)))
	{
		string s = item.address;

		if (s != "")
			cout << item.key << " " << item.FIO << " " << item.address << endl;
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

void insertItem(Titem item, HashTable& table, ofstream& ofbin)
{
	int index = hashFunction(item.key, table.length);

	int i = 1;

	while (table.values[index].isOpen == false) {
		index = (hashFunction(item.key, table.length) + i * secondHashFunction(item.key, table.length)) % table.length;
		i++;
	}

	if (index < table.length)
	{
		item.isOpen = false;
		ofbin.write((char*)(&item), sizeof(Titem));
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
				i++;
			}
			else
				break;
		}
		else {
			index = (hashFunction(key, table.length) + i * secondHashFunction(key, table.length)) % table.length;
			i++;
		}
	}

	if (table.values[index].isDeleted || table.values[index].isOpen)
		return -1;
	else
		return table.values[index].position;
}

int deleteValue(HashTable& table, long long key, ifstream& ifbin)
{
	int index = findValue(table, key);
	ofstream ofbin("temp.bin", ios::binary);
	for (int i = 0; i < table.length; i++) {
		if (table.values[i].key != key) {
			ofbin.write((char*)(&table.values[i]), sizeof(Titem));
		}
	}
	ofbin.close();
	ifbin.close();

	//remove("table.bin");
	//if (rename("temp.bin", "table.bin") != 0) cout << "Ошибка при переименовании файла.";
	
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
		if (table.values[i].key != 0 and !table.values[i].isDeleted)
		{
			cout << left << setw(4) << i << " " << table.values[i].key << "  " << table.values[i].FIO << "  " << table.values[i].address << endl;
		}
	}

}

void fillTable(HashTable& table, ifstream& ifbin, ofstream& ofbin)
{
	if (!ifbin.is_open()) {
		cout << "Не удалось открыть файл: " << endl;
		return;
	}

	if (!ofbin.is_open()) {
		cout << "Не удалось открыть файл: " << endl;
		return;
	}

	Owner value;
	Titem item;
	int c = 0;

	while (true)
	{
		if (ifbin.read((char*)&value, sizeof(Owner))) {
			if (value.key != item.key) {
				item.key = value.key;
				item.position = c * sizeof(Titem);
				strcpy(item.FIO, value.FIO);
				strcpy(item.address, value.address);
				insertItem(item, table, ofbin);
				c++;
			}
		}
		else
			break;
	}


	if (!ifbin.eof() && ifbin.fail()) {
		cout << "Ошибка чтения из файла." << endl;
	}
	ofbin.close();
	ifbin.close();
}

HashTable::HashTable(int length, ofstream& ofbin) {
	this->length = length;
	values.resize(length);
}
