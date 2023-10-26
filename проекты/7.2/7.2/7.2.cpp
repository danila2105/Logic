#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#define MAX_VERTICES 100

// Функция для добавления вершины в стек
void push(int stack[], int* top, int vertex) {
    stack[++(*top)] = vertex;
}

// Функция для извлечения вершины из стека
int pop(int stack[], int* top) {
    return stack[(*top)--];
}

// Функция для обхода в глубину без использования рекурсии
void DFS(int adjacencyMatrix[][MAX_VERTICES], int numVertices, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    int stack[MAX_VERTICES];
    int top = -1;

    push(stack, &top, startVertex);

    printf("Результат обхода в глубину:\n");

    while (top != -1) {
        int currentVertex = pop(stack, &top);

        if (visited[currentVertex] == 1) {
            continue;
        }

        printf("Посещена вершина: %d\n", currentVertex);
        visited[currentVertex] = 1;

        for (int i = numVertices - 1; i >= 0; i--) {
            if (adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                push(stack, &top, i);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numVertices = 6;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = { 0 };

    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[1][0] = 1;
    adjacencyMatrix[0][2] = 1;
    adjacencyMatrix[2][0] = 1;
    adjacencyMatrix[1][3] = 1;
    adjacencyMatrix[3][1] = 1;
    adjacencyMatrix[2][4] = 1;
    adjacencyMatrix[4][2] = 1;
    adjacencyMatrix[3][5] = 1;
    adjacencyMatrix[5][3] = 1;

    int startVertex = 0;

    DFS(adjacencyMatrix, numVertices, startVertex);

    return 0;
}