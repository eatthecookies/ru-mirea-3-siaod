#include <iostream>
#include "Owner.h"
#include <chrono>
#include <fstream>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


int main()
{
    setlocale(LC_ALL, "Russian");

    //100
    ofstream oftxt1("test100.txt");
    
    if (!oftxt1.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    for (int i = 0; i < 100; i++)
    {
        Owner value;
        value.key = rand() % 999999999 + 1000000000;
        oftxt1 << value.key << " " << value.address << endl;
    }
    oftxt1.close();

    ofstream ofbin1("test100.bin", ios::binary);
    ifstream iftxt1("test100.txt");

    if (ofbin1.is_open() && iftxt1.is_open())
    {
        createBinFile(iftxt1, ofbin1);
    }
    
    
    //1000 

    ofstream oftxt2("test1000.txt");

    if (!oftxt2.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    for (int i = 0; i < 1000; i++)
    {
        Owner value;
        value.key = rand() % 999999999 + 1000000000;
        oftxt2 << value.key << " " << value.address << endl;
    }
    oftxt2.close();


    ofstream ofbin2("test1000.bin", ios::binary);
    ifstream iftxt2("test1000.txt");

    if (ofbin2.is_open() && iftxt2.is_open())
    {
        createBinFile(iftxt2, ofbin2);
    }


    // 10 000 

    ofstream oftxt3("test10000.txt");

    if (!oftxt3.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    for (int i = 0; i < 10000; i++)
    {
        Owner value;
        value.key = rand() % 999999999 + 1000000000;
        oftxt3 << value.key << " " << value.address << endl;
    }
    oftxt3.close();

    ofstream ofbin3("test10000.bin", ios::binary);
    ifstream iftxt3("test10000.txt");

    if (ofbin3.is_open() && iftxt3.is_open())
    {
        createBinFile(iftxt3, ofbin3);
    }
}
  