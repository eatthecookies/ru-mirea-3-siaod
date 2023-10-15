#include "Owner.h"
#include <vector>t
#include <fstream>
#include <cmath>

void createBinFile(ifstream& iftxt, ofstream& ofbin)
{
	Owner value;

	while (!iftxt.eof())
	{
		iftxt >> value.key >> value.address;

		ofbin.write((char*)(&value), sizeof(value));
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

	while (ifbin.read((char*)&value, sizeof(value)))
	{
		string s = value.address;

		if (s != "")
			cout << value.key << " " << value.address << endl;
	}

	if (!ifbin.eof() && ifbin.fail()) {
		cout << "Ошибка чтения из файла." << endl;
	}

	ifbin.close();
}


Owner linearSearch(ifstream& ifbin, unsigned int key)
{
	int i = 0;
	Owner value;

	ifbin.read((char*)&value, sizeof(value));

	while (!ifbin.eof())
	{
		if (value.key == key)
		{
			ifbin.close();
			return value;
		}
		ifbin.read((char*)&value, sizeof(value));
	}
	
	value.key = 1;
	ifbin.close();

	return value;
}





//Owner binaryOptimizedSearch(int key)
//{
//	int c = 0;
//	vector <int> deltas;
//	int delta = 1;
//	int n = table.n;
//	int j = 0;
//	while (delta != 0)
//	{
//		delta = floor((n + pow(2, j - 1)) / (pow(2, j)));
//		deltas.push_back(delta);
//		j++;
//	}
//
//	int i = deltas[1];
//	j = 2;
//	while (true)
//	{
//		if (deltas[j] == 0)
//			return Owner(-1, "NULL");
//		else
//		{
//			if (key < table.p[i].key)
//			{
//				i = i - deltas[j];
//				j = j + 1;
//			}
//			if (key > table.p[i].key)
//			{
//				i = i + deltas[j];
//				j = j + 1;
//			}
//			if (key == table.p[i].key)
//			{
//				return table.p[i];
//			}
//		}
//	}
//}
//





