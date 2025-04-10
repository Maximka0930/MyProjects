#include "Dijkstra.h"

Dijkstra::Dijkstra(int StartPoint) :Decision(StartPoint)
{
    steps = 0;
}
int* Dijkstra::DecisionTask() {
    int* dist = new int[CountOfVertex];    // Массив расстояний
    bool* visited = new bool[CountOfVertex]; // Массив для отслеживания посещённых вершин

    for (int i = 0; i < CountOfVertex; i++) {
        dist[i] = INT_MAX;    // Изначально все расстояния бесконечны
        visited[i] = false;   // Изначально все вершины непосещённые
    }
    dist[StartPoint] = 0;    // Расстояние до начальной вершины равно 0
    steps++;
    // Основной цикл алгоритма
    for (int count = 0; count < 8 - 1; count++) {
        // Выбор ближайшей непосещённой вершины
        int u = minDistance(dist, visited, 8);
        visited[u] = true; // Пометка как посещённой

        // Обновление расстояний до соседей
        updateDistances(matrix, dist, visited, 8, u);
    }
    return dist;
}
int Dijkstra::minDistance(int dist[], bool visited[], int n) {
        int min = INT_MAX;
        int min_index = -1;

        // Проходим по всем вершинам, чтобы найти непосещённую вершину с минимальным расстоянием
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        return min_index;
    }
void Dijkstra::updateDistances(int matrix[8][8], int dist[], bool visited[], int n, int u) {
        for (int v = 0; v < n; v++) {
            // Проверяем, есть ли путь к соседу и не посещена ли вершина
            steps++;
            if (matrix[u][v] != INT_MAX && !visited[v]) {
                // Если путь через u короче, обновляем расстояние до v
                if (dist[u] + matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + matrix[u][v];
                }
            }
        }
    }
