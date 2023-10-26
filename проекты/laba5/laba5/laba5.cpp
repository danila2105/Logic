#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale> 

#define MAX_VERTICES 10  // Максимальное количество вершин в графе

int main() {
    setlocale(LC_ALL, "Russian");

    int n;  // Количество вершин
    int i, j;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Введите количество вершин графа
    printf("Введите количество вершин в графе (не более %d): ", MAX_VERTICES);
    scanf("%d", &n);

    // Генерация матрицы смежности
    printf("Матрица смежности графа:\n");
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (i == j) {
                adjacencyMatrix[i][j] = 0;  // Нет петли у вершины
            }
            else {
                int random = rand() % 2;  // Случайное 0 или 1 для определения наличия ребра
                adjacencyMatrix[i][j] = random;
                adjacencyMatrix[j][i] = random;  // Граф неориентированный, поэтому симметричен
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
    // Определение размера графа
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (adjacencyMatrix[i][j] == 0)
                continue;
            else
                count++;
        }
    }
    printf("Размер графа: %d \n", count);

    // Поиск изолированных, концевых и доминирующих вершин

    int isolatedVertices = 0;
    int leafVertices = 0;
    int dominatingVertices = 0;

    for (i = 0; i < n; i++) {
        int degree = 0;
        for (j = 0; j < n; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                degree++;
            }
        }
        if (degree == 0) {
            isolatedVertices++;
        }
        else if (degree == 1) {
            leafVertices++;
        }
        if (degree == n - 1) {
            dominatingVertices++;
        }
    }

    printf("Изолированных вершин: %d\n", isolatedVertices);
    printf("Концевых вершин: %d\n", leafVertices);
    printf("Доминирующих вершин: %d\n", dominatingVertices);

    return 0;
}
