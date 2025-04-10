#include "DecisionFirstTask.h"
// Функция для поиска пути с использованием BFS
bool DecisionFirstTask::bfs(int residualGraph[MAX_NODES][MAX_NODES], int n, int source, int sink, int parent[]) {
    bool visited[MAX_NODES] = { false };
    std::queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;

                if (v == sink) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Алгоритм Форда-Фалкерсона
int DecisionFirstTask::fordFulkerson(int graph[MAX_NODES][MAX_NODES], int n, int source, int sink, int residualGraph[MAX_NODES][MAX_NODES]) {
    memcpy(residualGraph, graph, sizeof(int) * MAX_NODES * MAX_NODES); // Копируем начальный граф в остаточный граф
    int parent[MAX_NODES];
    int maxFlow = 0;

    while (bfs(residualGraph, n, source, sink, parent)) {
        int pathFlow = INT_MAX;

        // Найти минимальную пропускную способность в найденном пути
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = std::min(pathFlow, residualGraph[u][v]);
        }

        // Обновить остаточный граф
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

// Функция для поиска минимального разреза
void DecisionFirstTask::findMinCut(int residualGraph[MAX_NODES][MAX_NODES], int n, int source, bool visited[MAX_NODES]) {
    memset(visited, false, sizeof(bool) * MAX_NODES);
    std::queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}