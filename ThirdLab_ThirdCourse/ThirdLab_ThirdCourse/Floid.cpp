#include "Floid.h"


Floid::Floid(int StartPoint) :Decision(StartPoint)
    {
        steps = 0;
    }
int* Floid::DecisionTask() {
        // Матрица расстояний  
        int** dist = new int* [CountOfVertex];
        for (int i = 0; i < CountOfVertex; i++) {
            dist[i] = new int[CountOfVertex];
        }

        // Инициализация матрицы расстояний начальными значениями
        for (int i = 0; i < CountOfVertex; i++) {
            for (int j = 0; j < CountOfVertex; j++) {
                if (matrix[i][j] == 0 && i != j) {
                    dist[i][j] = INT_MAX; // Если нет ребра, расстояние бесконечное
                }
                else {
                    dist[i][j] = matrix[i][j]; // Иначе расстояние как в матрице смежности
                }
            }
        }

        // Основной алгоритм Флойда-Уоршелла
        for (int k = 0; k < CountOfVertex; k++) {
            for (int i = 0; i < CountOfVertex; i++) {
                for (int j = 0; j < CountOfVertex; j++) {
                    steps++;
                    // Если есть путь через вершину k, который короче
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int* result = new int[CountOfVertex]; // Предполагаем, что вы хотите вернуть массив расстояний от вершины 0
        for (int i = 0; i < CountOfVertex; i++) {
            result[i] = dist[StartPoint][i]; // Например, возвращаем расстояния от первой вершины
        }

        // Освобождение памяти для матрицы
        for (int i = 0; i < CountOfVertex; i++) {
            delete[] dist[i]; // Удаляем каждую строку
        }
        delete[] dist; // Удаляем массив указателей

        return result; // Возвращаем массив
    }
int** Floid::DecisionTaskForSecond(int graph[8][8]) {
        //const int V = 8; // Количество вершин в графе
        // Матрица расстояний
        int** dist = new int* [CountOfVertex];
        for (int i = 0; i < CountOfVertex; i++) {
            dist[i] = new int[CountOfVertex];
        }

        // Инициализация матрицы расстояний начальными значениями
        for (int i = 0; i < CountOfVertex; i++) {
            for (int j = 0; j < CountOfVertex; j++) {
                if (graph[i][j] == 0 && i != j) {
                    dist[i][j] = INT_MAX; // Если нет ребра, расстояние бесконечное
                }
                else {
                    dist[i][j] = graph[i][j]; // Иначе расстояние как в матрице смежности
                }
            }
        }

        // Основной алгоритм Флойда-Уоршелла
        for (int k = 0; k < CountOfVertex; k++) {
            for (int i = 0; i < CountOfVertex; i++) {
                for (int j = 0; j < CountOfVertex; j++) {
                    // Если есть путь через вершину k, который короче
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }
