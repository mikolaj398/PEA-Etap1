#include "pch.h"
#include "BruteForce.h"


BruteForce::BruteForce(int ** dataMatrix, int size): Algorithm(dataMatrix, size)
{

}
void BruteForce::swap(std::vector<int>& cities, int index1, int index2)
{
	int temp = cities[index1];
	cities[index1] = cities[index2];
	cities[index2] = temp;

}
void BruteForce::countBestPath()
{
	solve(0, cities.size() - 1);
}
void BruteForce::solve(int index1, int index2)
{
	if (index1 == index2)
	{
		int temp = countDistance(cities);
		if (temp < result)
		{
			result = temp;
		}
	}

	else
	{
		for (int i = index1; i <= index2; i++)
		{
			swap(cities, index1, i);  
			solve(index1 + 1, index2);
			swap(cities, index1, i);
		}
	}
}
