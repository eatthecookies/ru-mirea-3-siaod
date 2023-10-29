#include <iostream>
#include "Owner.h"
#include <chrono>
#include <vector>
#include <fstream>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


int main()
{
    setlocale(LC_ALL, "Russian");
    Titem result;
    int searchKey = 1000016541;

    // 100
    
    ifstream ifbin100("test100.bin", ios::binary);

    vector <TableItem> table100;
    if (ifbin100.is_open())
    {
        createTable(table100, ifbin100);
        auto t1 = chrono::high_resolution_clock::now();
        int offset = binaryOptimizedSearch(table100, 1000022929);
        auto t2 = chrono::high_resolution_clock::now();
        ifstream ifbins100("test100.bin", ios::binary);
        findByOffset(ifbins100, offset);

        duration<double, std::milli> ms_double = t2 - t1;
        cout << "Elapsed time is " << ms_double.count() << "ms\n";
    }

    // 1000
    ifstream ifbin1000("test1000.bin", ios::binary);

    vector <TableItem> table1000;
    if (ifbin1000.is_open())
    {
        createTable(table1000, ifbin1000);
        auto t1 = chrono::high_resolution_clock::now();
        int offset = binaryOptimizedSearch(table1000, 1000018397);
        auto t2 = chrono::high_resolution_clock::now();
        ifstream ifbins1000("test1000.bin", ios::binary);
        findByOffset(ifbins1000, offset);

        duration<double, std::milli> ms_double = t2 - t1;
        cout << "Elapsed time is " << ms_double.count() << "ms\n";
    }

    // 10 000

    ifstream ifbin10000("test10000.bin", ios::binary);

    vector <TableItem> table10000;
    if (ifbin10000.is_open())
    {
        createTable(table10000, ifbin10000);
        auto t1 = chrono::high_resolution_clock::now();
        int offset = binaryOptimizedSearch(table10000, 1000018254);
        auto t2 = chrono::high_resolution_clock::now();
        ifstream ifbins10000("test10000.bin", ios::binary);
        findByOffset(ifbins10000, offset);

        duration<double, std::milli> ms_double = t2 - t1;
        cout << "Elapsed time is " << ms_double.count() << "ms\n";
    }
}
