#pragma once
#include "Decision.h"

class SecondTask : public Decision
{
private:
    bool* selectedCities;
    const int INF = INT_MAX; // Бесконечность для отсутствующих рёбер
    int** dist = new int* [CountOfVertex];
    int** next = new int* [CountOfVertex];

    ~SecondTask();
    void floydWarshall(int** dist, int** next, int n);

public:
    SecondTask();
    int findShortestRoute(int* cities, int numCities, System::String^ &path);

};

