#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
	while (true)
	{
        int inp;
        cout << "\n=============== Меню =========================" << endl;
        cout << "1. Сортировка произвольного набора до 8 чисел (от 0 до 7)" << endl;
        cout << "2. Сортировка произвольного набора из 64 чисел (от 0 до 63)" << endl;
        cout << "3. Завершить работу" << endl;
        cout << "================================================\n>> ";
        cin >> inp;
        cout << "\n";
        
        vector <int> array;
        
        
        switch (inp)
        {
        case 1:
        {
            unsigned char bitSequence = 0x0;
            
            // ввод массива с клавиатуры
            int n, val;
            cout << "Введите количество чисел (до 8 чисел от 0 до 7): ";
            cin >> n;
            cout << "Введите массив чисел: ";
            for (int i = 0; i < n; i++)
            {
                cin >> val;
                array.push_back(val);
            }
            
            // заполнение битовой последовательности на основе массива
            for (auto i : array) 
                bitSequence |= 1 << (7 - i); // 7-i т.к. биты идут слева направо, а не наоборот (как принято)

            // "распаковка" битовой последовательности в массив
            unsigned char mask;
            int counter = 0;
            for (int i = 0; i < 8; i++)
            {
                mask = 1 << (7-i);
                if ((mask & bitSequence)!= 0)
                    array[counter++] = i;
            }
            
            // печать массива
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            cout << endl;

            break;
        }
        case 2:
        {
            vector <unsigned char> bitVector;
            break;
        }
        case 3:
            cout << "Завершение работы программы..." << endl;
            exit(0);
        };
	}
	
}
