#include "DecisionSecondTask.h"
// Функция для минимизации стоимости
int DecisionSecondTask::hungarianAlgorithmMin(const int costMatrix[N][N], int assignment[N]) {
    int u[N + 1] = { 0 }, v[N + 1] = { 0 }, p[N + 1] = { 0 }, way[N + 1] = { 0 };

    for (int i = 1; i <= N; ++i) {
        p[0] = i;
        int j0 = 0;
        int minv[N + 1];
        std::fill(minv, minv + N + 1, std::numeric_limits<int>::max());
        bool used[N + 1] = { false };
        do {
            used[j0] = true;
            int i0 = p[j0], delta = std::numeric_limits<int>::max(), j1;
            for (int j = 1; j <= N; ++j) {
                if (!used[j]) {
                    int cur = costMatrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= N; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                }
                else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    for (int j = 1; j <= N; ++j) {
        if (p[j] > 0) {
            assignment[p[j] - 1] = j - 1;
        }
    }

    return -v[0];
}

// Функция для максимизации эффективности
int DecisionSecondTask::hungarianAlgorithmMax(const int efficiencyMatrix[N][N], int assignment[N]) {
    int transformedMatrix[N][N];

    // Преобразование для максимизации
    int maxVal = std::numeric_limits<int>::min();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            maxVal = std::max(maxVal, efficiencyMatrix[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            transformedMatrix[i][j] = maxVal - efficiencyMatrix[i][j];
        }
    }

    // Используем Венгерский алгоритм для минимизации преобразованной матрицы
    return hungarianAlgorithmMin(transformedMatrix, assignment);
}
