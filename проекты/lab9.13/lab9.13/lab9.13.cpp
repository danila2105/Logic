#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <clocale>

using namespace std;

// Структура для представления списка смежности
struct Graph {
    int V; // Количество вершин
    vector<vector<int>> adj; // Списки смежности
};

// Функция для добавления ребра в граф
void addEdge(Graph& graph, int u, int v) {
    graph.adj[u].push_back(v);
    graph.adj[v].push_back(u); // Граф неориентированный
}

// Функция для поиска расстояний в графе с использованием BFS
vector<int> bfsDistance(Graph& graph, int start) {
    vector<int> distances(graph.V, -1); // Инициализируем расстояния как -1 (недостижимость)
    distances[start] = 0; // Расстояние от стартовой вершины до самой себя - 0

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph.adj[u]) {
            if (distances[v] == -1) {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }

    return distances;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int V = 6; // Количество вершин в графе
    Graph graph;
    graph.V = V;
    graph.adj.resize(V);

    // Добавляем рёбра в граф
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    // Вывод списка смежности
    for (int i = 0; i < V; i++) {
        cout << "Вершина " << i << " смежна с вершинами: ";
        for (int v : graph.adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    int startNode;
    printf("Введите начальный узел для поиска расстояний: ");
    scanf("%d", &startNode);

    vector<int> distances = bfsDistance(graph, startNode);

    // Выводим расстояния от startNode до всех вершин
    cout << "Расстояния от вершины " << startNode << " до других вершин:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "До вершины " << i << ": " << distances[i] << endl;
    }

    return 0;
}