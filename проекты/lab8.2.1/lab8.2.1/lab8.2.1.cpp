#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Очередь на основе связанного списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Очередь пуста
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Функция для обхода в ширину
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    Queue queue;
    initQueue(&queue);
    bool visited[MAX_VERTICES] = { false };

    visited[startVertex] = true;
    enqueue(&queue, startVertex);

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
}

int main() {
    int numVertices = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    int startVertex = 0;

    printf("Обход в ширину (BFS) начиная с вершины %d: ", startVertex);
    bfs(graph, numVertices, startVertex);

    return 0;
}