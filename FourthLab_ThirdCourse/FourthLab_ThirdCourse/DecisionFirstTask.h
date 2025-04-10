#pragma once
#include <iostream>
#include <queue>
#include <climits>
#include <cstring> // Для memset

class DecisionFirstTask
{
private:
	static const int MAX_NODES = 100; // Максимальное количество узлов в графе
	bool bfs(int residualGraph[MAX_NODES][MAX_NODES], int n, int source, int sink, int parent[]);
public:
	int fordFulkerson(int graph[MAX_NODES][MAX_NODES], int n, int source, int sink, int residualGraph[MAX_NODES][MAX_NODES]);
	void findMinCut(int residualGraph[MAX_NODES][MAX_NODES], int n, int source, bool visited[MAX_NODES]);

};

