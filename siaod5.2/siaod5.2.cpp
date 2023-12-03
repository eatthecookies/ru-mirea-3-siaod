#include <fstream>
#include <iostream>
#include "SplayTree.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    SplayTree tree;
    // Создание дерева и бинарного файла
    ifstream ifbin("testdata.bin", ios::binary);
    createTreeFromFile(tree, ifbin);
    printTree1(tree.root, 0);
    cout << "----------------" << endl;
    // включение элемента в дерево;

    Node* newNode = new Node;
    newNode->key = 55;
    newNode->position = 0;

    insert(tree, newNode);
    printTree1(tree.root, 0);

    // поиск записи в файле с использованием БДП;
    ifstream ifbin2("testdata.bin", ios::binary);
    //cout << endl << getOwnerFromFile(findNode(tree, 7886895032)->position, ifbin2).address << endl << endl;
    cout << endl << getOwnerFromFile(findNode(tree, 18)->position, ifbin2).address << endl << endl;

    //удаление ключа из дерева;
    removeNode(tree, 24);

    //отображение дерева
    printTree1(tree.root, 0);

}
