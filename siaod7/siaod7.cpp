#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


struct node {
    string substr;
    int c = 0;
};

int main()
{
    setlocale(LC_ALL, "RUS");
    string str;
    cout << "Введите строку: ";
    cin >> str;
    //str = "ABACCBA";
    //str = "ABAOKABAS";
    int n = str.length();

    vector <vector<node>> matrix;
    matrix.resize(n, vector<node>(n));

    // первый проход
    for (int i = 0; i < n; i++) {
        matrix[i][i].substr = str[i];
        matrix[i][i].c = 1;
    }

    // второй проход
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            matrix[i + 1][i].c = 2;
            matrix[i + 1][i].substr = str.substr(i, 2);
        }
        else {
            matrix[i + 1][i].c = 1;
            matrix[i + 1][i].substr = str.substr(i, 2);
        } 
    }

    // третий и до конца...
    for (int offset = 2; offset < n; offset++) {
        for (int k = 0; k < n - offset; k++) {
            if (str[k] == str[k + offset]) {
                matrix[k + offset][k].c = 2 + matrix[k + offset - 1][k + 1].c;
                matrix[k + offset][k].substr = str.substr(k, offset + 1);
            }
            else {
                int pred1, pred2;
                pred1 = matrix[k + offset - 1][k].c;
                pred2 = matrix[k + offset][k + 1].c;

                matrix[k + offset][k].c = max(pred1, pred2);
                matrix[k + offset][k].substr = str.substr(k, offset + 1);
            }
        }
    }


    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << right << setw(4) << matrix[i][j].c << " " << setw(n) << left << matrix[i][j].substr << " ";
        cout << endl;
    }*/

    cout << "Длина наибольшего палиндрома: " << matrix[n - 1][0].c;
}
