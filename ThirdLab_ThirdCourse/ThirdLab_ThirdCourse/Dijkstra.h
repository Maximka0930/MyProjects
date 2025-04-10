#pragma once
#include "Decision.h"

class Dijkstra : public Decision
{
public:
	int steps;
    Dijkstra(int StartPoint);
    int* DecisionTask();
private:
    int minDistance(int dist[], bool visited[], int n);
    void updateDistances(int matrix[8][8], int dist[], bool visited[], int n, int u);


};

