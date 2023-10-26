#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale> 


#define MAX_VERTICES 10  // Максимальное количество вершин в графе
#define MAX_EDGES 20     // Максимальное количество рёбер в графе

int main() {
    setlocale(LC_ALL, "Russian");
    int n;  // Количество вершин
    int m;  // Количество рёбер
    int i, j, k;
    int incidenceMatrix[MAX_VERTICES][MAX_EDGES];

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Введите количество вершин и рёбер графа
    printf("Введите количество вершин в графе (не более %d): ", MAX_VERTICES);
    scanf("%d", &n);
    printf("Введите количество рёбер в графе (не более %d): ", MAX_EDGES);
    scanf("%d", &m);

    // Генерация матрицы инцидентности
    printf("Матрица инцидентности графа:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            incidenceMatrix[i][j] = 0;  // Инициализируем все значения нулем
        }
    }
    for (k = 0; k < m; k++) {
        printf("Введите номера вершин, инцидентных ребру %d (0-%d): ", k, n - 1);
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        incidenceMatrix[vertex1][k] = 1;
        incidenceMatrix[vertex2][k] = 1;
    }

    // Вывод матрицы инцидентности
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", incidenceMatrix[i][j]);
        }
        printf("\n");
    }

    // Определение размера графа
    printf("Размер графа: %d вершин, %d рёбер\n", n, m);

    // Поиск изолированных, концевых и доминирующих вершин
    int isolatedVertices = 0;
    int leafVertices = 0;
    int dominatingVertices = 0;

    for (i = 0; i < n; i++) {
        int degree = 0;
        for (j = 0; j < m; j++) {
            if (incidenceMatrix[i][j] == 1) {
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
