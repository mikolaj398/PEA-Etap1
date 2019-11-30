#include "pch.h"
#include "Dynamic.h"
using namespace std;
Dynamic::Dynamic(int** dataMatrix, int size) : Algorithm(dataMatrix, size)
{
	for (int i = 0; i < size; i++)
	{
		vector<int> pom;
		for (int j = 0; j < size; j++)
			pom.push_back(dataMatrix[i][j]);
		dupa.push_back(pom);
	}
}
void Dynamic::countBestPath()
{
	vector<vector<int>> state(dupa.size());
	for (auto& neighbors : state)
		neighbors = vector<int>((1 << dupa.size()) - 1, INT_MAX);

	result = solve(dupa, 0, 1, state);
}


//int Dynamic::solve(int city, std::vector<int> remaining)
//{
//	std::vector<int> newRemaining;
//	std::vector<int> costs;
//
//	for (int j = 0; j < remaining.size(); j++)
//		if (remaining[j] != city)
//			newRemaining.push_back(remaining[j]);
//
//	if (newRemaining.size() == 1)
//	{
//		int leaf = (distancesMatrix[newRemaining[0]][0]+ distancesMatrix[city][newRemaining[0]]);
//		return leaf;
//	}
//
//	for (int i = 0; i < newRemaining.size(); i++)
//	{
//		int child = solve(newRemaining[i], newRemaining);
//		costs.push_back((child + distancesMatrix[city][newRemaining[i]]));
//	}
//
//	int min = INT_MAX;
//	for (int i = 0; i < costs.size(); i++)
//	{
//		if (min > costs[i])
//			min = costs[i];
//	}
//	return min;
//}
int Dynamic::solve(const vector<vector<int>>& xd, int pos, int visited, vector<vector<int>>& state)
{
	if (visited == ((1 << xd.size()) - 1))
		return xd[pos][0]; // return to starting city

	if (state[pos][visited] != INT_MAX)
		return state[pos][visited];

	for (int i = 0; i < xd.size(); ++i)
	{
		// can't visit ourselves unless we're ending & skip if already visited
		if (i == pos || (visited & (1 << i)))
			continue;

		int distance = xd[pos][i] + solve(xd, i, visited | (1 << i), state);
		if (distance < state[pos][visited])
			state[pos][visited] = distance;
	}

	return state[pos][visited];
}
