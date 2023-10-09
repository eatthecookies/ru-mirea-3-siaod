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
    /*ofstream oftxt("test100.txt");
    
    if (!oftxt.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    for (int i = 0; i < 100; i++)
    {
        Owner value;
        value.key = rand() % 999999999 + 1000000000;
        oftxt << value.key << " " << value.address << endl;
    }
    oftxt.close();

    ofstream ofbin("test100.bin", ios::binary);
    ifstream iftxt("test100.txt");

    if (ofbin.is_open() && iftxt.is_open())
    {
        createBinFile(iftxt, ofbin);
    }
    */

    ifstream ifbin("test100.bin", ios::binary);

    outputBinFile(ifbin);

   /*Owner result;
    int searchKey = 1000016541;
    result = linearSearch(ifbin, searchKey);

    cout << result.key << result.address;*/


    /*for (int i = 100; i <= UP; i *= 10)
    {
        createTable(table, i);

        auto t1 = chrono::high_resolution_clock::now();
        linearSearch(table, i - 1).address;
        auto t2 = chrono::high_resolution_clock::now();

        duration<double, std::milli> ms_double = t2 - t1;

        cout << "Elapsed time on " << i << " is " << ms_double.count() << "ms\n";

        delete[]table.p;
    }*/


}
