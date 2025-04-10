#include "Graph.h"

Graph::Graph(int vertices) {
    this->vertices = vertices;
}

void Graph::addEdge(int start, int end, int weight) {
    edges.push_back({ start, end, weight });
}

void Graph::drawGraph(Graphics^ g) {
    Pen^ pen = gcnew Pen(Color::Black);
    Font^ font = gcnew Font("Arial", 10);

    // ������ ������� � ����
    for (int i = 0; i < edges.size(); ++i) {
        Edge edge = edges[i];

        // ���������� ��� ������
        Point startPoint(edge.start * 100 + 50, 100);
        Point endPoint(edge.end * 100 + 50, 100);

        // ������ ������� ��� ����
        g->DrawLine(pen, startPoint, endPoint);

        // ������ ����� ���� ����
        g->DrawString(
            edge.weight.ToString(),
            font,
            Brushes::Black,
            (startPoint.X + endPoint.X) / 2,
            (startPoint.Y + endPoint.Y) / 2
        );
    }

    // ������ �������
    for (int i = 0; i < vertices; ++i) {
        Point vertexPoint(i * 100 + 50, 100);
        g->FillEllipse(Brushes::LightBlue, vertexPoint.X - 15, vertexPoint.Y - 15, 30, 30);
        g->DrawEllipse(pen, vertexPoint.X - 15, vertexPoint.Y - 15, 30, 30);
        g->DrawString(i.ToString(), font, Brushes::Black, vertexPoint.X - 5, vertexPoint.Y - 5);
    }
}
