#include <iostream>
using namespace std;
#include "IBBT.h"
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Создание дерева из n вершин: " << endl;
    cout << "n = ";
    int n;
    cin >> n;

    IBBT tree(n);
  

    while (true) {
        cout << "\nМеню" << endl;
        cout << "1. Вывести дерево" << endl;
        cout << "2. Вернуть самый левый узел дерева" << endl;
        cout << "3. Определить длину пути (количество ребер) от корня до ближайшего узла с заданным значением" << endl;
        cout << "4. Найти  максимальное  значение  среди  значений листьев дерева" << endl;
        cout << "0. Завершение работы" << endl;
        cout << ">> ";
        int inp;
        cin >> inp;
        cout << endl;

        
        
        switch (inp) {

        case 1:
        {
            tree.print();
            break;
        }
        case 2:
        {
            cout << tree.maxLeftNode() << endl;
            break;
        }

        case 3:
        {
            char targetChar;
            cout << "Значение: ";
            cin >> targetChar;
            if (tree.getShortestPathLengthToValue(targetChar) == -1) cout << "Заданного значения нет" << endl;

            cout << tree.getShortestPathLengthToValue(targetChar) << endl;
            break;
        }
        case 4:
            cout << tree.getMaxLeafValue() << endl;
            break;

        case 0:
            exit(0);
            break;
        }
    }
}
