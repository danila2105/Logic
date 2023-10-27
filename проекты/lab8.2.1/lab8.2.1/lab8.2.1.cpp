#define _CRT_SECURE_NO_WARNINGS
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

// Задание 2. Реализация очереди

struct node
{
    int vertex;  // Индекс вершины
    struct node* next; // Ссылка на следующую вершину в очереди
};

struct node* head = NULL, * last = NULL; // Указатели на начало и конец очереди
int dlinna = 0; // Длина очереди

// Функции добавления вершины в очередь, извлечения вершины из очереди и просмотра очереди
void enqueue(int vertex);
int dequeue(void);
void review(void);
void addVertex(void);
void removeVertex(void);

int graph[6][6] = { // Матрица смежности вашего графа
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 1;
    int startVertex = 0;

    while (choice)
    {
        printf("Выберите действие:\n");
        printf("(1) Добавить вершину\n");
        printf("(2) Удалить вершину\n");
        printf("(3) Просмотр очереди\n");
        printf("(4) Выбрать начальную вершину для обхода в ширину\n");
        printf("(0) Выход из программы\n\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        system("cls");

        switch (choice)
        {
        case 1:
            addVertex();
            system("pause");
            system("cls");
            break;
        case 2:
            removeVertex();
            system("pause");
            system("cls");
            break;
        case 3:
            review();
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Введите индекс начальной вершины для обхода в ширину: ");
            scanf("%d", &startVertex);
            system("cls");
            printf("Обход в ширину, начиная с вершины %d:\n", startVertex);

            // Очистим очередь перед новым обходом
            while (dlinna > 0) {
                dequeue();
            }

            // Добавим начальную вершину в очередь
            enqueue(startVertex);

            int visited[6] = { 0 }; // Массив для отслеживания посещенных вершин

            while (dlinna > 0) {
                int currentVertex = dequeue();
                visited[currentVertex] = 1;
                printf("Посещенная вершина: %d\n", currentVertex);

                for (int i = 0; i < 6; i++) {
                    if (graph[currentVertex][i] == 1 && !visited[i]) {
                        enqueue(i);
                        visited[i] = 1;
                    }
                }
            }
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}

void enqueue(int vertex) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->vertex = vertex;
    p->next = NULL;
    if (head == NULL) {
        head = p;
        last = p;
    }
    else {
        last->next = p;
        last = p;
    }
    dlinna++;
}

int dequeue(void) {
    if (head == NULL) {
        printf("Очередь пуста\n");
        exit(1);
    }
    int vertex = head->vertex;
    struct node* temp = head;
    head = head->next;
    free(temp);
    dlinna--;
    return vertex;
}

void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Очередь пуста\n");
    }
    while (struc) {
        printf("Вершина - %d\n", struc->vertex);
        struc = struc->next;
    }
}

void addVertex(void) {
    int vertex;
    printf("Введите индекс вершины для добавления: ");
    scanf("%d", &vertex);
    // Добавляем вершину в граф
    for (int i = 0; i < 6; i++) {
        graph[i][vertex] = 0;
    }
    for (int i = 0; i < 6; i++) {
        graph[vertex][i] = 0;
    }
}

void removeVertex(void) {
    int vertex;
    printf("Введите индекс вершины для удаления: ");
    scanf("%d", &vertex);
    // Удаляем вершину из графа
    for (int i = 0; i < 6; i++) {
        graph[i][vertex] = 0;
    }
    for (int i = 0; i < 6; i++) {
        graph[vertex][i] = 0;
    }
}




