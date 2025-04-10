#include "SecondTask.h"
//using namespace System;

SecondTask::SecondTask() : Decision()
{
    for (int i = 0; i < CountOfVertex; ++i) {
        dist[i] = new int[CountOfVertex];
        next[i] = new int[CountOfVertex];
        for (int j = 0; j < CountOfVertex; ++j) {
            dist[i][j] = matrix[i][j];
            next[i][j] = (matrix[i][j] == INF) ? -1 : j;
        }
    }

    floydWarshall(dist, next, CountOfVertex);

}

SecondTask::~SecondTask()
{
    // Очистка памяти
    for (int i = 0; i < CountOfVertex; ++i) {
        delete[] dist[i];
        delete[] next[i];
    }
    delete[] dist;
    delete[] next;
}

void SecondTask::floydWarshall(int** dist, int** next, int n) {

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k]; // Обновляем маршрут
                }
            }
        }
    }
}
int SecondTask::findShortestRoute(int* cities, int numCities, System::String^& path) {
    int minCost = INF;
    int bestPath[100];
    int bestPathSize = 0;

    int currentPath[100];
    int currentPathSize;

    // Сортируем промежуточные города для корректного использования std::next_permutation
    std::sort(cities + 1, cities + numCities - 1);

    do {
        int currentCost = 0;
        currentPathSize = 0;

        for (int i = 0; i < numCities - 1; ++i) {
            int u = cities[i];
            int v = cities[i + 1];
            if (dist[u][v] == INF) {
                currentCost = INF;
                break;
            }
            currentCost += dist[u][v];

            // Восстановление и добавление промежуточного пути
            int segment[100];
            int segmentSize = 0;

            int pos = u;
            while (pos != v) {
                segment[segmentSize++] = pos;
                pos = next[pos][v];
            }
            segment[segmentSize++] = v;

            // Копируем сегмент (кроме последней вершины) в currentPath
            for (int j = 0; j < segmentSize - 1; ++j) {
                currentPath[currentPathSize++] = segment[j];
            }
        }
        currentPath[currentPathSize++] = cities[numCities - 1];

        if (currentCost < minCost) {
            minCost = currentCost;
            bestPathSize = currentPathSize;
            for (int j = 0; j < currentPathSize; ++j) {
                bestPath[j] = currentPath[j];
            }
        }

    } while (std::next_permutation(cities + 1, cities + numCities - 1));

    // Запись полного пути
    for (int i = 0; i < bestPathSize; ++i) {
        if (i != bestPathSize - 1) {
            path += (bestPath[i] + 1) + "->";
        }
        else {
            path += (bestPath[i] + 1);
        }
    }

    return minCost;
}