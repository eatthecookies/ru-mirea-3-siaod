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

    ofstream ofbin1("data100.bin", ios::binary);
    ifstream iftxt1("data100.txt");
    if (ofbin1.is_open() && iftxt1.is_open())
    {
        createBinFile(iftxt1, ofbin1);
    }
    ifstream ifbin1("data100.bin", ios::binary);
    outputBinFile(ifbin1);


    // создание таблицы


    //HashTable table(100);
    ////outputTable(table);
    //
    //ifstream ifbin1("data100.bin", ios::binary);
    //fillTable(table, ifbin1);
    //outputTable(table); 
    //outputTable(table);
    //ifstream ifbin1("data100.bin", ios::binary);
    //fillTable(table, ifbin1);
    //outputTable(table);

    HashTable table(100);
    long long key;

    while (true) {
        cout << "\nМеню" << endl;
        cout << "1. Заполнение таблицы из файла" << endl;
        cout << "2. Вывод содержимого таблицы" << endl;
        cout << "3. Вставка элемента в таблицу по ключу" << endl;
        cout << "4. Удаление элемента из таблицы по ключу" << endl;
        cout << "5. Поиск ключа в таблице" << endl;
        cout << "0. Завершение работы" << endl;
        cout << ">> ";
        int inp;
        cin >> inp;
        cout << endl;
        
        switch (inp) {

        case 1:
            cout << "1. Заполнить таблицу из 10 записей значениями из файла data10.bin" << endl;
            cout << "2. Заполнить таблицу из 100 записей из файла data100.bin" << endl;
            cout << ">> ";
            cin >> inp;

            switch (inp)
            {
                case 1:
                {
                    cout << endl;
                    ifstream ifbin1("data10.bin", ios::binary);
                    fillTable(table, ifbin1);
                    outputTable(table);
                    break;
                }
                case 2:
                {
                    cout << endl;
                    ifstream ifbin2("data100.bin", ios::binary);
                    fillTable(table, ifbin2);
                    outputTable(table);
                    break;
                }
            }
            break;
        case 2:
            outputTable(table);
            break;

        case 3:
        {
            cout << "Введите ключ: ";
            Titem item;
            cin >> item.key;

            cout << "Введите ФИО и адрес: ";
            cin >> item.FIO >> item.address;

            insertItem(item, table);
            break;
        }
        case 4:
            cout << "Введите ключ: ";
            cin >> key;
            deleteValue(table, key);
            cout << "Значение удалено" << endl;
            break;
        case 5:
            cout << "Введите ключ: ";
            cin >> key;
            cout << "Найденный индекс: " << findValue(table, key) << endl;
            break;
        case 0:
            exit(0);
            break;
        }
    }
}
