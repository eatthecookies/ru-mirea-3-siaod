
#include <iostream>
#include <fstream>
#include "Graph.h"

// https://programforyou.ru/graph-redactor

int main()
{
    setlocale(LC_ALL, "RUS");
    int vertex, edges;
    string inp;
    cout << "Ориентированный? (y/n), количество ребер, узлов " << endl;
    cin >> inp >> edges >> vertex;

    Graph graph = Graph(vertex, edges);

    // заполнение графа
    int weight, vertex1, vertex2;

    if (inp == "y") {
        for (int i = 0; i < edges; i++) {
            cout << i + 1 << ". ";
            cin >> vertex1;
            cin >> vertex2;
            cin >> weight;
            graph.graphInsert(vertex1 - 1, vertex2 - 1, weight);
        }
    }
    else {
        for (int i = 0; i < edges; i++) {
            cout << i+1 << ". ";
            cin >> vertex1;
            cin >> vertex2;
            cin >> weight;
            graph.graphInsert(vertex1 - 1, vertex2 - 1, weight);
            graph.graphInsert(vertex2 - 1, vertex1 - 1, weight);
        }
    }
    
    cout << endl << "Матрица смежности введенного графа: " << endl;
    graph.printMatrix();

    //  вывести Эйлеров цикл в графе
    graph.eulerCycle();

    // реализация алгоритма прима
    graph.primsMinimalTree();

}

