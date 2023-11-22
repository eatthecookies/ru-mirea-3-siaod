#include <fstream>
#include <iostream>
#include "SplayTree.h"



int main()
{
    SplayTree tree;
    // Создание дерева и бинарного файла
    ifstream ifbin("testdata.bin", ios::binary);
    createTreeFromFile(tree, ifbin);
    printTree(tree.root, nullptr, false);
    cout << findNode(tree, 18)->position;
    //tree.root = splay(tree.root, 18);
    //printTree(tree.root, nullptr, false);
    //// включение элемента в дерево;
    /*Node* newNode = new Node;
    newNode->key = 0;
    newNode->position = 0;*/

    //insert(tree, newNode);
    //removeNode(tree, 68);
    //printTree(tree.root, nullptr, false);
    //printTree1(tree.root, 0);
    //// поиск ключа в дереве;
    //cout << endl << findNode(tree, 7886895032)->position << " ";

    //// поиск записи в файле с использованием БДП;
    ifstream ifbin2("testdata.bin", ios::binary);
    cout << getOwnerFromFile(findNode(tree, 18)->position, ifbin2).address;
    //Owner owner;
    //ifbin2.read((char*)&owner, sizeof(owner));
    //Node* q = findNode(tree, 7886895032);
    //ifbin2.seekg(q->position, ios::beg);
    //cout << owner.address << endl << endl;

    // //удаление ключа из дерева;
    //removeNode(tree, 7150003532);

    // //отображение дерева
    //printTree(tree.root, nullptr, false);

}
