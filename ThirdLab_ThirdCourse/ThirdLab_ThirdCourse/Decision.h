#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>


class Decision
{
protected:
    int StartPoint;
    int CountOfVertex = 8; // 
    int k = INT_MAX;
    //int matrix[9][9] =
    //{
    //{0, k, k, 5, 2, 1, k, 4, k},
    //{k, 0, 6, k, 4, k, k, k, k},
    //{k, 6, 0, 7, k, k, k, k, 3},
    //{5, k, 7, 0, 5, k, k, 4, k},
    //{2, 4, k, 5, 0, 6, k, k, k},
    //{1, k, k, k, 6, 0, 2, 3, k},
    //{k, k, k, k, k, 2, 0, 1, k},
    //{4, k, k, 4, k, 3, 1, 0, k},
    //{k, k, 10, k, k, k, k, k,k},
    //};

    int matrix[8][8] =
    {
    {0, k, k, 5, 2, 1, k, 4},
    {k, 0, 6, k, 4, k, k, k},
    {k, 6, 0, 7, k, k, k, k},
    {5, k, 7, 0, 5, k, k, 4},
    {2, 4, k, 5, 0, 6, k, k},
    {1, k, k, k, 6, 0, 2, 3},
    {k, k, k, k, k, 2, 0, 1},
    {4, k, k, 4, k, 3, 1, 0}
    };

    //int matrix[8][8] =
    //{
    //{0, k, k, 5, 2, 1, k, 4},
    //{k, 0, 6, k, 4, k, k, k},
    //{k, 6, 0, 7, k, k, k, k},
    //{5, k, 7, 0, 5, k, k, 4},
    //{2, 4, k, 5, 0, 6, k, k},
    //{1, k, k, k, 6, 0, k, 3},
    //{k, k, k, k, k, k, 0, 1},
    //{4, k, k, 4, k, 3, 1, 0}
    //};



public:
    Decision(int StartPoint);
    Decision() {};
};

