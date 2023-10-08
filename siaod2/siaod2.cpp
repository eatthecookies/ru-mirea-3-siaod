#include <iostream>
using namespace std;

int main()
{
    int inp;
    cout << "Меню." << endl;
    cout << "1. " << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cin >> inp;

    switch (inp)
    {
    case 1:
        
    case 2:

    case 3:

    case 4:

    case 5:

    };
       
}


#include <iostream>
#include "Owner.h"
#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main()
{

    const int UP = 1000000;
    Table table;


    for (int i = 100; i <= UP; i *= 10)
    {
        createTable(table, i);

        auto t1 = chrono::high_resolution_clock::now();
        linearSearch(table, i - 1).address;
        auto t2 = chrono::high_resolution_clock::now();

        duration<double, std::milli> ms_double = t2 - t1;

        cout << "Elapsed time on " << i << " is " << ms_double.count() << "ms\n";

        delete[]table.p;
    }


    for (int i = 100; i <= UP; i *= 10)
    {
        createTableBS(table, i);

        auto t1 = chrono::high_resolution_clock::now();
        barrierSearch(table, i - 1);
        auto t2 = chrono::high_resolution_clock::now();

        duration<double, std::milli> ms_double = t2 - t1;

        cout << "Elapsed time on " << i << " is " << ms_double.count() << "ms\n";

        //delete[] table.p;
    }


    for (int i = 100; i <= UP; i *= 10)
    {
        createTable(table, i);

        auto t1 = chrono::high_resolution_clock::now();
        binaryOptimizedSearch(table, i - 1);
        auto t2 = chrono::high_resolution_clock::now();

        duration<double, std::milli> ms_double = t2 - t1;

        cout << "Elapsed time on " << i << " is " << ms_double.count() << "ms\n";

        delete[]table.p;
    }

}
