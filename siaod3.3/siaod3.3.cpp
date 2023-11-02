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

    //ofstream oftxt1("data10.txt");

    //if (!oftxt1.is_open()) {
    //    cout << "Не удалось открыть файл" << endl;
    //    return 1;
    //}
    //
    //Owner value;

    //for (int i = 0; i < 10; i++)
    //{
    //    long long s = 7 * static_cast<long long>(pow(10, 10));

    //    for (int j = 0; j < 10; j++)
    //        s += (rand() % 9) * static_cast<long long>(pow(10, j));

    //    value.key = s;
    //    oftxt1 << value.key << " " << value.FIO << " " << value.address << endl;
    //}

    //oftxt1.close();

    //ofstream ofbin1("data10.bin", ios::binary);
    //ifstream iftxt1("data10.txt");

    //if (ofbin1.is_open() && iftxt1.is_open())
    //{
    //    createBinFile(iftxt1, ofbin1);
    //}

    //ifstream ifbin1("data10.bin", ios::binary);
    //outputBinFile(ifbin1);


    // создание таблицы


    //HashTable table(100);
    ////outputTable(table);
    //
    //ifstream ifbin1("data100.bin", ios::binary);
    //fillTable(table, ifbin1);
    //outputTable(table);



    ////outputTable(table);

    //ifstream ifbin1("data100.bin", ios::binary);
    //fillTable(table, ifbin1);
    //outputTable(table);

    ofstream ofbin("table.bin", ios::binary);
    HashTable table(100, ofbin);
    long long key;

    while (true) {
        cout << "\nМеню" << endl;
        cout << "1. Заполнение таблицы из файла" << endl;
        cout << "2. Вывод содержимого таблицы" << endl;
        cout << "4. Удаление элемента из таблицы по ключу" << endl;
        cout << "5. Поиск ключа в таблице с прямым доступом из файла" << endl;
        cout << "0. Завершение работы" << endl;
        cout << ">> ";
        int inp;
        cin >> inp;
        cout << endl;

        switch (inp) {

        case 1:
        {
            cout << endl;
            ifstream ifbin("data100.bin", ios::binary);
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
            cout << "Введите ключ: ";
            Titem item;
            cin >> item.key;

            cout << "Введите ФИО и адрес: ";
            cin >> item.FIO >> item.address;
            ofstream ofbin("table.bin", ios::binary);

            insertItem(item, table, ofbin);
            break;
        }
        case 4:
        {
            cout << "Введите ключ: ";
            cin >> key;
            ifstream ifbin("table.bin", ios::binary);
            deleteValue(table, key, ifbin);
            cout << "Значение удалено" << endl;
            break;
        }
        case 5:
        {
            ifstream ifbin("table.bin", ios::binary);
            cout << "Введите ключ: ";
            cin >> key;
            Titem item;
            ifbin.seekg(findValue(table, key));
            ifbin.read((char*)&item, sizeof(Titem));

            cout << "Найденный индекс: " << item.key << endl;
            break;
        }
        case 0:
            exit(0);
            break;
        }
    }
}
