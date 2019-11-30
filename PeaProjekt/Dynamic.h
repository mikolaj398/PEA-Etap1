#pragma once
#include "Algorithm.h"

class Dynamic : public Algorithm
{
public:
	std::vector<std::vector<int>> dupa;
	Dynamic(int**, int);
	void countBestPath();
	int solve(int**& dataMatrix, int pos, int visited, std::vector<std::vector<int>>& state);
	int solve(int pos, int visited, std::vector<std::vector<int>>& state);
	int solve(const std::vector<std::vector<int>>& cities, int pos, int visited, std::vector<std::vector<int>>& state);
	int solve(int city, std::vector<int> remaining);
};

