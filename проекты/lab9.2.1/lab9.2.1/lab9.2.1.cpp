#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include<clocale>
#include <time.h>
using namespace std;

// Функция для выполнения обхода в глубину и подсчёта расстояний
void dfsDistance(vector<vector<int>>& adjMatrix, vector<int>& distances, int currentNode, int currentDistance) {
    distances[currentNode] = currentDistance;

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[currentNode][i] == 1 && distances[i] == -1) {
            dfsDistance(adjMatrix, distances, i, currentDistance + 1);
        }
    }
}

// Функция для вывода матрицы смежности на экран
void printAdjacencyMatrix(vector<vector<int>>& adjMatrix) {
    for (const vector<int>& row : adjMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int V = 6; // Количество вершин в графе
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    // Заполняем матрицу смежности для примера
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][2] = adjMatrix[2][0] = 1;
    adjMatrix[1][3] = adjMatrix[3][1] = 1;
    adjMatrix[2][4] = adjMatrix[4][2] = 1;
    adjMatrix[3][5] = adjMatrix[5][3] = 1;

    // Выводим матрицу смежности
    printf("Матрица смежности графа:\n");
    printAdjacencyMatrix(adjMatrix);

    int startNode;
    printf("Введите начальный узел для поиска расстояний: ");
    scanf("%d", &startNode);
    clock_t start = clock();
    vector<int> distances(V, -1); // Инициализируем расстояния как -1 (недостижимость)
    dfsDistance(adjMatrix, distances, startNode, 0);
    clock_t end = clock();
    double time_spent10 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time adjmatrix: %f s.\n", time_spent10);

    // Выводим расстояния от startNode до всех вершин
    cout << "Расстояния от вершины " << startNode << " до других вершин:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "До вершины " << i << ": " << distances[i] << endl;
    }

    return 0;
}