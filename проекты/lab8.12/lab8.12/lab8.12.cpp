#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <clocale>

#define MAX_VERTICES 6 // Максимальное количество вершин
#define MAX_QUEUE_SIZE 100


// Функция для генерации случайного числа от 0 до 1
double randomProbability() {
    return (double)rand() / RAND_MAX;
}

// Генерация случайной матрицы смежности
void generateRandomAdjacencyMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int numEdges) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            matrix[i][j] = 0;
        }
    }

    int edgeCount = 0;
    while (edgeCount < numEdges) {
        int vertex1 = rand() % numVertices;
        int vertex2 = rand() % numVertices;

        if (vertex1 != vertex2 && matrix[vertex1][vertex2] == 0) {
            matrix[vertex1][vertex2] = 1;
            matrix[vertex2][vertex1] = 1;
            edgeCount++;
        }
    }
}

// Функция для обхода в ширину
void breadthFirstSearch(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int numVertices) {
    bool visited[MAX_VERTICES] = { 0 };
    int queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    printf("Посещенная вершина: %d\n", startVertex);
    queue[rear++] = startVertex;

    while (front != rear) {
        int currentVertex = queue[front++];
        for (int neighbor = 0; neighbor < numVertices; neighbor++) {
            if (graph[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                printf("Посещенная вершина: %d\n", neighbor);
                queue[rear++] = neighbor;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int numVertices = 6; // Задайте желаемое количество вершин
    int numEdges = 8;    // Задайте желаемое количество ребер
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    generateRandomAdjacencyMatrix(adjacencyMatrix, numVertices, numEdges);


    printf("Матрица смежности:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    int startVertex;
    printf("Введите начальную вершину для обхода в ширину (от 0 до %d): ", numVertices - 1);
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Недопустимая начальная вершина. Пожалуйста, введите вершину между 0 и %d.\n", numVertices - 1);
        return 1; // Выход с кодом ошибки
    }

    printf("Обход в ширину, начиная с вершины %d:\n", startVertex);
    breadthFirstSearch(adjacencyMatrix, startVertex, numVertices);

    return 0;
}
