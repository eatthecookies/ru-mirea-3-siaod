#include <fstream>
#include <iostream>
#include "BTree.h"



int main()
{
    BTree tree;

    // Создание дерева из бинарного файла
    ifstream ifbin("testdata.bin", ios::binary);
    createTreeFromFile(ifbin, tree);
    //printTree(tree.root, nullptr, false);
    printTree1(tree.root, 0);

    // включение элемента в дерево;
    Node* newNode = new Node;
    newNode->key = 0;
    newNode->position = 0;

    addNode(newNode, tree);
    cout << "---------------------------------" << endl ;
    // поиск ключа в дереве;
    // cout << endl << findNode(tree, 7886895032)->position << " ";
    
    
    // поиск записи в файле с использованием БДП;
    ifstream ifbin2("testdata.bin", ios::binary);
    cout << getOwnerFromFile(findNode(tree, 24)->position, ifbin2).address << " " << endl << endl;
    
    //cout << owner.address << endl << endl;

    // удаление ключа из дерева;
    removeNode(tree, 68);

    // отображение дерева
    printTree1(tree.root, 0);

}

