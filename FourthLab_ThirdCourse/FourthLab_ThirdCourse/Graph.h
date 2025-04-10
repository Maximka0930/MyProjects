#pragma once
#include <vector>
#include <string>
#include <Windows.h>
using namespace System::Drawing;

class Graph
{
public:
    Graph(int vertices);
    void addEdge(int start, int end, int weight);
    void drawGraph(Graphics^ g);

private:
    struct Edge {
        int start;
        int end;
        int weight;
    };

    int vertices;
    std::vector<Edge> edges;
};
