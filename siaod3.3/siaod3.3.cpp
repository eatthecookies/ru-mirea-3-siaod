#include <iostream>
#include "Owner.h"
#include <chrono>
#include <fstream>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


int main()
{
    setlocale(LC_ALL, "Russian");

    HashTable table(100);
    long long key;
    cout << " ";

    while (true) {
        cout << "\nМеню" << endl;
        cout << "1. Заполнение таблицы из файла" << endl;
        cout << "2. Вывод содержимого бинарного файла" << endl;
        cout << "3. Вывод содержимого таблицы" << endl;
        cout << "4. Удаление элемента из таблицы по ключу" << endl;
        cout << "5. Поиск ключа в таблице с прямым доступом из файла" << endl;
        cout << "6. Выполнение задания" << endl;
        cout << "0. Завершение работы" << endl;
        cout << ">> ";
        int inp;
        cin >> inp;
        cout << endl;

        switch (inp) {

        case 1:
        {
            cout << endl;
            ifstream ifbin("data10.bin", ios::binary);
            ofstream ofbin("table.bin", ios::binary);

            fillTable(table, ifbin, ofbin);

            break;
        }
        case 2:
        {
            ifstream ifbin("table.bin", ios::binary);
            outputBinFile(ifbin);
            break;
        }
        case 3:
        {
            outputTable(table);
            break;
        }
        case 4:
        {
            cout << "Введите ключ: ";
            cin >> key;
            ifstream ifbin("table.bin", ios::binary);
            ofstream ofbin("table.bin", ios::binary);
            deleteValue(table, key, ofbin);
            cout << "Значение удалено" << endl;
            break;
        }
        case 5:
        {
            ifstream ifbin("table.bin", ios::binary);
            
            cout << "Введите ключ: ";
            cin >> key;
            Titem item;
            if (findValue(table, key) != -1) {
                ifbin.seekg(findValueOffset(table, key));
                ifbin.read((char*)&item, sizeof(Titem));
                cout << "Найденная запись: " << item.key << " " << item.FIO << " " << item.address << endl;
            }
            else {
                cout << "Элемент по данному ключу отсутствует." <<endl;
            }

            break;
        }
        case 6:
        {
            ifstream ifbin("table.bin", ios::binary);

            long long firstKey, middleKey, lastKey;

            firstKey = table.values[0].key;
            middleKey = table.values[table.length / 2].key;
            lastKey = table.values[table.length - 1].key;
            
            
            Titem item;

            auto t1 = chrono::high_resolution_clock::now();
               
            ifbin.seekg(findValueOffset(table, firstKey));
            ifbin.read((char*)&item, sizeof(Titem));
                
            auto t2 = chrono::high_resolution_clock::now();

            duration<double, std::milli> ms_double = t2 - t1;

            cout << "Elapsed time on firstKey is " << ms_double.count() << "ms\n";


            t1 = chrono::high_resolution_clock::now();

            ifbin.seekg(findValueOffset(table, middleKey));
            ifbin.read((char*)&item, sizeof(Titem));

            t2 = chrono::high_resolution_clock::now();

            ms_double = t2 - t1;

            cout << "Elapsed time on middleKey is " << ms_double.count() << "ms\n";

            t1 = chrono::high_resolution_clock::now();

            ifbin.seekg(findValueOffset(table, lastKey));
            ifbin.read((char*)&item, sizeof(Titem));

            t2 = chrono::high_resolution_clock::now();

            ms_double = t2 - t1;

            cout << "Elapsed time on lastKey is " << ms_double.count() << "ms\n";

            break;
        }
        case 80:
        {
            ofstream ofbin1("data500000.bin", ios::binary);
            ifstream iftxt1("output.txt");

            if (ofbin1.is_open() && iftxt1.is_open())
            {
                createBinFile(iftxt1, ofbin1);
            }
            break;
        }
        case 0:
            exit(0);
            break;
        }
    }
}
