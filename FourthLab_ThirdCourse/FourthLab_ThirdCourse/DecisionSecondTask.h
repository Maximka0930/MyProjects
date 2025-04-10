#pragma once
#include <iostream>
#include <limits>
#include <algorithm>

class DecisionSecondTask
{
private:
	static const int N = 5;
public:
	int hungarianAlgorithmMin(const int costMatrix[N][N], int assignment[N]);
	int hungarianAlgorithmMax(const int efficiencyMatrix[N][N], int assignment[N]);

};

