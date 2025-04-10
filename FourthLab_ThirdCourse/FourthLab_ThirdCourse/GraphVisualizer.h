#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <windows.h>
#include <tchar.h>
#include <math.h>

class GraphVisualizer {
private:
    const double PI = 3.14159265358979323846;
    struct Vertex {
        std::string name;
        int x, y; // Координаты для отрисовки
    };

    std::vector<Vertex> vertices;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> edges;

    HWND hwnd; // Окно для отрисовки
    void DrawCircle(HDC hdc, int x, int y, int radius);
    void DrawArrow(HDC hdc, int x1, int y1, int x2, int y2, int arrowSize);

public:
    GraphVisualizer();
    GraphVisualizer(HWND hwnd);

    void AddVertex(const std::string& name, int x, int y);
    void AddEdge(const std::string& from, const std::string& to, int weight);
    void DrawGraph(HDC hdc);
    void CreateGraph(const std::vector<std::string>& vertices,
        const std::vector<std::pair<int, int>>& edges,
        const std::vector<int>& weights);
    void ShowWindowAndRun();
};
