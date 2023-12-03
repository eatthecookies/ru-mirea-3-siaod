#include "Graph.h"
#include <set>

Graph::Graph(int vertices, int edges) : vertices(vertices), edges(edges) {
    matrix.resize(vertices, vector<int>(vertices));
}

void Graph::printMatrix() {

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            cout << setw(3) << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Graph::graphInsert(int v1, int v2, int w) {
    matrix[v1][v2] = w;
}

void Graph::eulerCycle() {
    if (!isEulers()) {
        cout << "Граф неэйлеров, невозможно найти эйлеров цикл." << endl;
        return;
    }
    int vertices = matrix.size(); // количество вершин
    vector <vector <int>> matrix = this->matrix;

    stack<int> stack;
    stack.push(0);
    vector<int> cycle;

    while (!stack.empty()) {
        int v = stack.top(); // текущий узел
        int i = 0;
        bool found = false;

        while (i < vertices) { // обход по ребрам узла
            if (matrix[v][i] != 0) {
                found = true;
                break;
            }
            ++i;
        }

        if (found) {
            stack.push(i);
            // убираем ребро в матрице, как уже посетившее
            matrix[v][i] = 0;
            matrix[i][v] = 0;
        }
        else { // пришли в тупик, идем обратно на один узел
            cycle.push_back(v);
            stack.pop();
        }
    }

    cout << "Эйлеров цикл: ";
    for (int i = cycle.size() - 1; i >= 0; --i) {
        cout << cycle[i] + 1 << " ";
    }
    cout << endl;
}

bool Graph::isEulers()
{
    for (int i = 0; i < vertices; i++) {
        int c = 0;
        for (int k = 0; k < vertices; k++) {
            if (matrix[i][k] != 0) c++;
        }
        if (c % 2 != 0) return false;
    }
    return true;
}

int Graph::primsMinimalTree(vector <int> &visited, vector <int>& unvisited, vector <vector <int>> &minimalTree){
    minimalTree.resize(vertices, vector<int>(vertices));

    int counter = 0;
    while (!unvisited.empty()) {
        counter++;
        int minimal = 10000;
        int selectedV = -1;
        int selectedU = -1;

        for (int i = 0; i < visited.size(); i++) {

            int currentV = visited[i];

            for (int k = 0; k < vertices; k++) {

                if (matrix[currentV][k] != 0 &&
                    find(unvisited.begin(), unvisited.end(), k) != unvisited.end())
                {
                    if (minimal > matrix[currentV][k]) {
                        minimal = matrix[currentV][k];
                        selectedV = currentV;
                        selectedU = k;
                    }
                }
            }

        }
        if (counter > 1000 ) {
            return -1;
        }
        if (selectedV != -1 && selectedU != -1) {
            minimalTree[selectedV][selectedU] = minimal;
            minimalTree[selectedU][selectedV] = minimal;
            visited.push_back(selectedU);
            auto it = find(unvisited.begin(), unvisited.end(), selectedU);
            unvisited.erase(it);
        }
    }
    return 0;
}

vector<vector <int>> Graph::primsMinimalTree()
{
    vector <vector <int>> minimalTree;
    vector <int> visited;
    vector <int> unvisited;

    int k = 0;
    for (int i = 0; i < vertices; i++) {
        if (i != k)
            unvisited.push_back(i);
    }
    visited.push_back(k);


    while (primsMinimalTree(visited, unvisited, minimalTree) == -1) {
        k++;
        minimalTree.clear();
        unvisited.clear();
        visited.clear();
        for (int i = 0; i < vertices; i++) {
            if (i != k)
                unvisited.push_back(i);
        }
        visited.push_back(k);
    }
    
    
    cout << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            cout << setw(3) << minimalTree[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return minimalTree;
}


