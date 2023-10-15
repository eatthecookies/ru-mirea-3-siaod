#include "Owner.h"
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

void createBinFile(ifstream& iftxt, ofstream& ofbin)
{
	Owner owner;

	while (!iftxt.eof())
	{
		iftxt >> owner.key >> owner.address;

		ofbin.write((char*)(&owner), sizeof(owner));
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
	Owner owner;

	while (ifbin.read((char*)&owner, sizeof(owner)))
	{
		string s = owner.address;

		if (s != "")
			cout << owner.key << " " << owner.address << endl;
	}

	if (!ifbin.eof() && ifbin.fail()) {
		cout << "Ошибка чтения из файла." << endl;
	}

	ifbin.close();
}


Owner linearSearch(ifstream& ifbin, unsigned int key)
{
	int i = 0;
	Owner owner;

	ifbin.read((char*)&owner, sizeof(owner));

	while (!ifbin.eof())
	{
		if (owner.key == key)
		{
			ifbin.close();
			return owner;
		}
		ifbin.read((char*)&owner, sizeof(owner));
	}
	ifbin.close();
}


void createTable(vector<TableItem>& table, ifstream& ifbin)
{
	TableItem item;
	Owner owner;

	int i = 0;

	while (ifbin.read((char*)&owner, sizeof(owner)))
	{
		string s = owner.address;

		if (s != "")
		{
			item.key = owner.key;
			item.offset = i * sizeof(owner);
			table.push_back(item);
		}
		i++;
	}
	ifbin.close();
}

bool compareByKey(TableItem& a, TableItem& b)
{
	return a.key < b.key;
}

Owner findByOffset(ifstream& ifbin, int offset)
{
	Owner owner;
	ifbin.seekg(offset, ios::beg);
	ifbin.read((char*)&owner, sizeof(owner));
	return owner;
}

int binaryOptimizedSearch(vector<TableItem>& table, int key)
{
	sort(table.begin(), table.end(), compareByKey);
	vector <int> deltas;
	int delta = 1;
	int n = table.size();
	int j = 0;
	
	while (delta != 0)
	{
		delta = floor((n + pow(2, j - 1)) / (pow(2, j)));
		deltas.push_back(delta);
		j++;
	}

	int i = deltas[1];
	
	j = 2;
	
	while (true)
	{
		if (deltas[j] == 0)
			return -1;
		else
		{
			if (key < table[i].key)
			{
				i = i - deltas[j];
				j = j + 1;
			}
			if (key > table[i].key)
			{
				i = i + deltas[j];
				j = j + 1;
			}
			if (key == table[i].key)
			{
				return table[i].offset;
			}
		}
	}
}






