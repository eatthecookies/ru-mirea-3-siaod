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

    ifstream ifbin1("test100.bin", ios::binary);

    Titem result;
    int searchKey = 1000016541;
    
    auto t1 = chrono::high_resolution_clock::now();
    result = linearSearch(ifbin1, searchKey);
    auto t2 = chrono::high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    cout << "Elapsed time is " << ms_double.count() << "ms\n";


    ifstream ifbin2("test1000.bin", ios::binary);

    searchKey = 1000018397;
    t1 = chrono::high_resolution_clock::now();
    result = linearSearch(ifbin2, searchKey);
    t2 = chrono::high_resolution_clock::now();

    ms_double = t2 - t1;
    cout << "Elapsed time is " << ms_double.count() << "ms\n";


    ifstream ifbin3("test10000.bin", ios::binary);

    searchKey = 1000018254;
    t1 = chrono::high_resolution_clock::now();
    result = linearSearch(ifbin3, searchKey);
    t2 = chrono::high_resolution_clock::now();

    ms_double = t2 - t1;
    cout << "Elapsed time is " << ms_double.count() << "ms\n";

}
