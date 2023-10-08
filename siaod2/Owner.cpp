#include "Owner.h"
#include <vector>
#include <cmath>

Owner binaryOptimizedSearch(Table& table, int key)
{
	int c = 0;
	vector <int> deltas;
	int delta = 1;
	int n = table.n;
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
			return Owner(-1, "NULL");
		else
		{
			if (key < table.p[i].key)
			{
				i = i - deltas[j];
				j = j + 1;
			}
			if (key > table.p[i].key)
			{
				i = i + deltas[j];
				j = j + 1;
			}
			if (key == table.p[i].key)
			{
				return table.p[i];
			}
		}
	}
}

Owner linearSearch(Table& table, int key)
{
	int i = 0;
	while (i <= table.n)
	{
		if (key == table.p[i].key)
			return table.p[i];
		else
			i += 1;
	}
	return Owner(-1, "NULL");
}

Owner barrierSearch(Table& table, int key)
{
	table.p[table.n - 1].key = key;

	int i = 0;

	while (table.p[i].key != key)
		i++;

	if (i <= table.n)
		return table.p[i];
	else
		return Owner(-1, "NULL");
}


void createTable(Table& table, int n)
{
	table.n = n;
	table.p = new Owner[n];
	for (int i = 0; i < n; i++)
	{
		table.p[i].key = i;
		table.p[i].address = "lorem ipsum information";
	}
}


void createTableBS(Table& table, int n)
{
	table.n = n + 1;
	table.p = new Owner[n];

	for (int i = 0; i < n; i++)
	{
		table.p[i].key = i;
		table.p[i].address = "lorem ipsum information";
	}
}


void printTable(Table& table)
{
	for (int i = 0; i < table.n; i++)
	{
		cout << table.p[i].key << " " << table.p[i].address;
		cout << endl;
	}

}

Owner::Owner()
{
}

Owner::Owner(int key, string address) : key(key), address(address)
{
}
