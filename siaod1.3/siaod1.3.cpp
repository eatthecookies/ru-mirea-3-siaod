#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    while (true)
    {



        int inp;
        cout << "\n=============== Меню =========================" << endl;
        cout << "1. Сортировка 20 чисел из файла" << endl;
        cout << "2. Сортировка 100 чисел из файла" << endl;
        cout << "3. Сортировка 1000 чисел из файла" << endl;
        cout << "4. Сортировка из файла 1МБ" << endl;
        cout << "5. Завершить работу" << endl;
        cout << "================================================\n>> ";
        cin >> inp;
        cout << "\n";


        switch (inp)
        {
        case 1:
        {
            vector <unsigned char> bitVector(3);
            ifstream fin1("fileinput1.txt");
            ofstream fout1("fileoutput1.txt");
            int n = 0, i = 0;
            while (!fin1.eof())
            {
                fin1 >> n;
                bitVector[(23 - n) / 8] |= 1 << ((23 - n) % 8);
            }

            unsigned char mask;
            int counter = 0;
            for (int i = 0; i < 23; i++)
            {
                mask = 1 << ((23 - i) % 8);
                if ((mask & bitVector[(23 - i) / 8]) != 0)
                    fout1 << i << endl;
            }

            fin1.close();
            fout1.close();
            
            break;
        }
        case 2:
        {
            vector <unsigned char> bitVector(16);
            ifstream fin2("fileinput100.txt");
            ofstream fout2("fileoutput100.txt");

            int n = 0, i = 0;
            while (!fin2.eof())
            {
                fin2 >> n;
                bitVector[(127 - n) / 8] |= 1 << ((127 - n) % 8);
            }


            // "распаковка" битовой последовательности в массив
            unsigned char mask;
            int counter = 0;
            for (int i = 0; i < 128; i++)
            {
                mask = 1 << ((127 - i) % 8);
                if ((mask & bitVector[(127 - i) / 8]) != 0)
                    fout2 << i << endl;
            }


            break;
        }
        case 3:
        {
            vector <unsigned char> bitVector(128);
            ifstream fin3("fileinput1000.txt");
            ofstream fout3("fileoutput1000.txt");

            int n = 0, i = 0;
            while (!fin3.eof())
            {
                fin3 >> n;
                bitVector[(1023 - n) / 8] |= 1 << ((1023 - n) % 8);
            }


            // "распаковка" битовой последовательности в массив
            unsigned char mask;
            int counter = 0;
            for (int i = 0; i < 1024; i++)
            {
                mask = 1 << ((1023 - i) % 8);
                if ((mask & bitVector[(1023 - i) / 8]) != 0)
                    fout3 << i << endl;
            }


            break;
        }
        case 4:
        {

            vector <unsigned char> bitVector(18750);
            ifstream fin4("fileinput1mb.txt");
            ofstream fout4("fileoutput1mb.txt");

            int n = 0, i = 0;
            while (!fin4.eof())
            {
                fin4 >> n;
                bitVector[(150000 - 1 - n) / 8] |= 1 << ((150000 - 1 - n) % 8);
            }


            // "распаковка" битовой последовательности в массив
            unsigned char mask;
            int counter = 0;
            for (int i = 0; i < 150000; i++)
            {
                mask = 1 << ((150000 - 1 - i) % 8);
                if ((mask & bitVector[(150000 - 1 - i) / 8]) != 0)
                    fout4 << i << endl;
            }


            break;
        }
        case 5:
        {
            cout << "Завершение работы программы..." << endl;
            exit(0);
        }
        };
    }

}
