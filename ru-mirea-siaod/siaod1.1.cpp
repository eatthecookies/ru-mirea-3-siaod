﻿#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    while (true)
    {
        int inp;
        cout << "\n=============== Меню =========================" << endl;
        cout << "1. На заданнном числе задать биты с четными номерами в значение 1" << endl;
        cout << "2. На введенном числе обнулить 7, 9, 11 биты" << endl;
        cout << "3. Введенное число умножить на 16" << endl;
        cout << "4. Введенное число поделить на 16" << endl;
        cout << "5. На введенном числе обнулить n-ный бит" << endl;
        cout << "6. Завершить работу" << endl;
        cout << "================================================\n>> ";
        cin >> inp;
        cout << "\n";

        int number;
        int mask;

        switch (inp)
        {
        case 1:
            number = 0xFE9C8;  
            mask = 0x55555555;
            cout << "Число в двоичном представлении: " << bitset<32>(number) << endl;
            cout << "Маска в двоичном представлении: " << bitset<32>(mask) << endl;
            number |= mask;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Результат в шестнадцатиричной системе счисления: " << hex << number << endl;
            cout << "Результат в двоичной системе счисления: " << bitset<32>(number) << endl;
            break; 
        case 2:
            mask = 0xFFFFF57F;
            cout << "Введите число: ";
            cin >> number;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Число в двоичном представлении: " << bitset<32>(number) << endl;
            cout << "Маска в двоичном представлении: " << bitset<32>(mask) << endl;
            number &= mask;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Результат в шестнадцатиричной системе счисления: " << hex << number << endl;
            cout << "Результат в двоичной системе счисления: " << bitset<32>(number) << endl;
            break;
        case 3:
            cout << "Введите число: ";
            cin >> number;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Число в двоичном представлении: " << bitset<32>(number) << endl;
            number <<= 4;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Результат в шестнадцатиричной системе счисления: " << hex << number << endl;
            cout << "Результат в двоичной системе счисления: " << bitset<32>(number) << endl;
            break;
        case 4:
            cout << "Введите число: ";
            cin >> number;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Число в двоичном представлении: " << bitset<32>(number) << endl;
            number >>= 4;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Результат в шестнадцатиричной системе счисления: " << hex << number << endl;
            cout << "Результат в двоичной системе счисления: " << bitset<32>(number) << endl;
            break;
        case 5:
            cout << "Введите число: ";
            cin >> number;
            cout << "Введите бит, который необходимо обнулить: ";
            int n;
            cin >> n;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Число в двоичном представлении: " << bitset<32>(number) << endl;
            cout << "---------------------------------------------------------------" << endl;
            
            mask = 1;
            number = number & (~(mask << n));
            
            cout << "Результат в шестнадцатиричной системе счисления: " << hex << number << endl;
            cout << "Результат в двоичной системе счисления: " << bitset<32>(number) << endl;
            break;
        case 6:
            cout << "Завершение работы программы..." << endl;
            exit(0);
        };

    }
    
    
}