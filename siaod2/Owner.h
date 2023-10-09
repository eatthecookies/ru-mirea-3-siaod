#pragma once
#include <iostream>
#include <string>
using namespace std;



struct Owner
{
	unsigned int key = 0;
	string address = "lorem-ipsum-adress";
};


void createBinFile(ifstream& iftxt, ofstream& ofbin);
void readBinFile(ifstream& ofbin);
void outputBinFile(ifstream& ofbin);
Owner binaryOptimizedSearch(int key);
Owner linearSearch(ifstream& ifbin, unsigned int key);



