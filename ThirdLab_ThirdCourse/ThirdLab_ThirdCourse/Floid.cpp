#include "Floid.h"


Floid::Floid(int StartPoint) :Decision(StartPoint)
    {
        steps = 0;
    }
int* Floid::DecisionTask() {
        // ������� ����������  
        int** dist = new int* [CountOfVertex];
        for (int i = 0; i < CountOfVertex; i++) {
            dist[i] = new int[CountOfVertex];
        }

        // ������������� ������� ���������� ���������� ����������
        for (int i = 0; i < CountOfVertex; i++) {
            for (int j = 0; j < CountOfVertex; j++) {
                if (matrix[i][j] == 0 && i != j) {
                    dist[i][j] = INT_MAX; // ���� ��� �����, ���������� �����������
                }
                else {
                    dist[i][j] = matrix[i][j]; // ����� ���������� ��� � ������� ���������
                }
            }
        }

        // �������� �������� ������-��������
        for (int k = 0; k < CountOfVertex; k++) {
            for (int i = 0; i < CountOfVertex; i++) {
                for (int j = 0; j < CountOfVertex; j++) {
                    steps++;
                    // ���� ���� ���� ����� ������� k, ������� ������
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int* result = new int[CountOfVertex]; // ������������, ��� �� ������ ������� ������ ���������� �� ������� 0
        for (int i = 0; i < CountOfVertex; i++) {
            result[i] = dist[StartPoint][i]; // ��������, ���������� ���������� �� ������ �������
        }

        // ������������ ������ ��� �������
        for (int i = 0; i < CountOfVertex; i++) {
            delete[] dist[i]; // ������� ������ ������
        }
        delete[] dist; // ������� ������ ����������

        return result; // ���������� ������
    }
int** Floid::DecisionTaskForSecond(int graph[8][8]) {
        //const int V = 8; // ���������� ������ � �����
        // ������� ����������
        int** dist = new int* [CountOfVertex];
        for (int i = 0; i < CountOfVertex; i++) {
            dist[i] = new int[CountOfVertex];
        }

        // ������������� ������� ���������� ���������� ����������
        for (int i = 0; i < CountOfVertex; i++) {
            for (int j = 0; j < CountOfVertex; j++) {
                if (graph[i][j] == 0 && i != j) {
                    dist[i][j] = INT_MAX; // ���� ��� �����, ���������� �����������
                }
                else {
                    dist[i][j] = graph[i][j]; // ����� ���������� ��� � ������� ���������
                }
            }
        }

        // �������� �������� ������-��������
        for (int k = 0; k < CountOfVertex; k++) {
            for (int i = 0; i < CountOfVertex; i++) {
                for (int j = 0; j < CountOfVertex; j++) {
                    // ���� ���� ���� ����� ������� k, ������� ������
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }
