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

    // генерация данных в файл 

    //ofstream oftxt1("data100.txt");

    //if (!oftxt1.is_open()) {
    //    cout << "Не удалось открыть файл" << endl;
    //    return 1;
    //}
    //
    //Owner value;

    //for (int i = 0; i < 100; i++)
    //{
    //    long long s = 7 * static_cast<long long>(pow(10, 10));

    //    for (int j = 0; j < 10; j++)
    //        s += (rand() % 9) * static_cast<long long>(pow(10, j));

    //    value.key = s;
    //    oftxt1 << value.key << " " << value.FIO << " " << value.address << endl;
    //}

    //oftxt1.close();

    //ofstream ofbin1("data100.bin", ios::binary);
    //ifstream iftxt1("data100.txt");

    //if (ofbin1.is_open() && iftxt1.is_open())
    //{
    //    createBinFile(iftxt1, ofbin1);
    //}

    //ifstream ifbin1("data100.bin", ios::binary);
    //outputBinFile(ifbin1);


    // создание таблицы


    HashTable table(100);
    //outputTable(table);
    
    ifstream ifbin1("data100.bin", ios::binary);
    fillTable(table, ifbin1);
    outputTable(table);
   
}
