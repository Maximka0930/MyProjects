#include "Dijkstra.h"

Dijkstra::Dijkstra(int StartPoint) :Decision(StartPoint)
{
    steps = 0;
}
int* Dijkstra::DecisionTask() {
    int* dist = new int[CountOfVertex];    // ������ ����������
    bool* visited = new bool[CountOfVertex]; // ������ ��� ������������ ���������� ������

    for (int i = 0; i < CountOfVertex; i++) {
        dist[i] = INT_MAX;    // ���������� ��� ���������� ����������
        visited[i] = false;   // ���������� ��� ������� ������������
    }
    dist[StartPoint] = 0;    // ���������� �� ��������� ������� ����� 0
    steps++;
    // �������� ���� ���������
    for (int count = 0; count < 8 - 1; count++) {
        // ����� ��������� ������������ �������
        int u = minDistance(dist, visited, 8);
        visited[u] = true; // ������� ��� ����������

        // ���������� ���������� �� �������
        updateDistances(matrix, dist, visited, 8, u);
    }
    return dist;
}
int Dijkstra::minDistance(int dist[], bool visited[], int n) {
        int min = INT_MAX;
        int min_index = -1;

        // �������� �� ���� ��������, ����� ����� ������������ ������� � ����������� �����������
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
            // ���������, ���� �� ���� � ������ � �� �������� �� �������
            steps++;
            if (matrix[u][v] != INT_MAX && !visited[v]) {
                // ���� ���� ����� u ������, ��������� ���������� �� v
                if (dist[u] + matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + matrix[u][v];
                }
            }
        }
    }
