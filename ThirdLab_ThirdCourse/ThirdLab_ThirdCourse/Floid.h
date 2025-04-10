#pragma once
#include "Decision.h"

class Floid : public Decision
{
public:
    int steps;
    Floid(int StartPoint);
    int* DecisionTask();
    int** DecisionTaskForSecond(int graph[8][8]);

};

