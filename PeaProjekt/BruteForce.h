#pragma once
#include <vector>
#include "Algorithm.h"

class BruteForce: public Algorithm
{
public:
	BruteForce(int **, int);
	void swap(std::vector<int>& cities, int index1, int index2);
	void countBestPath() override;
	void solve(int index1, int index2);

};

