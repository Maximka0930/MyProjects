#include "GraphVisualizer.h"

GraphVisualizer::GraphVisualizer() : hwnd(nullptr) {}

GraphVisualizer::GraphVisualizer(HWND hwnd) : hwnd(hwnd) {}

void GraphVisualizer::DrawCircle(HDC hdc, int x, int y, int radius) {
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}

void GraphVisualizer::DrawArrow(HDC hdc, int x1, int y1, int x2, int y2, int arrowSize) {
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);

    double angle = atan2(y2 - y1, x2 - x1) + PI;
    int arrowX1 = static_cast<int>(x2 + arrowSize * cos(angle - PI / 6));
    int arrowY1 = static_cast<int>(y2 + arrowSize * sin(angle - PI / 6));
    int arrowX2 = static_cast<int>(x2 + arrowSize * cos(angle + PI / 6));
    int arrowY2 = static_cast<int>(y2 + arrowSize * sin(angle + PI / 6));

    LineTo(hdc, arrowX1, arrowY1);
    MoveToEx(hdc, x2, y2, NULL);
    LineTo(hdc, arrowX2, arrowY2);
}

void GraphVisualizer::AddVertex(const std::string& name, int x, int y) {
    vertices.push_back({ name, x, y });
}

void GraphVisualizer::AddEdge(const std::string& from, const std::string& to, int weight) {
    edges[from].push_back({ to, weight });
}

void GraphVisualizer::DrawGraph(HDC hdc) {
    // Рисуем рёбра
    for (const auto& vertex : vertices) {
        for (const auto& edge : edges[vertex.name]) {
            auto toVertex = std::find_if(vertices.begin(), vertices.end(), [&](const Vertex& v) {
                return v.name == edge.first;
                });

            if (toVertex != vertices.end()) {
                // Рисуем стрелку для рёбер
                DrawArrow(hdc, vertex.x, vertex.y, toVertex->x, toVertex->y, 10);

                // Отображаем вес рёбер
                int midX = (vertex.x + toVertex->x) / 2;
                int midY = (vertex.y + toVertex->y) / 2;
                std::string weightStr = std::to_string(edge.second);
                TextOutA(hdc, midX, midY, weightStr.c_str(), weightStr.length());
            }
        }
    }

    // Рисуем вершины
    for (const auto& vertex : vertices) {
        DrawCircle(hdc, vertex.x, vertex.y, 20);
        TextOutA(hdc, vertex.x - 10, vertex.y - 10, vertex.name.c_str(), vertex.name.length());
    }
}

void GraphVisualizer::CreateGraph(const std::vector<std::string>& vertices,
    const std::vector<std::pair<int, int>>& edges,
    const std::vector<int>& weights) {
    // Добавляем вершины
    for (const auto& vertex : vertices) {
        AddVertex(vertex, rand() % 500, rand() % 500);  // Размещаем вершины случайным образом
    }

    // Добавляем рёбра
    for (size_t i = 0; i < edges.size(); ++i) {
        const auto& edge = edges[i];
        int weight = (i < weights.size()) ? weights[i] : 0;  // Берём вес ребра из списка
        AddEdge(vertices[edge.first], vertices[edge.second], weight);
    }
}

void GraphVisualizer::ShowWindowAndRun() {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"GraphVisualizerWindow";

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, L"Failed to register window class!", L"Error", MB_OK);
        return;
    }

    hwnd = CreateWindow(wc.lpszClassName, L"Graph Visualizer", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, wc.hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, L"Failed to create window!", L"Error", MB_OK);
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
