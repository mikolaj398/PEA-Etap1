#pragma once
#include <vector>
#include <iostream>
class Algorithm
{
public:
	Algorithm(int **, int);
	~Algorithm();
	void printResult();
	
	int result;
	unsigned int size;
	void printData(int**);
protected:
	virtual void countBestPath() = 0;
	int countDistance(std::vector<int>);
	
	void initMatrix(int**);

	int** distancesMatrix;
	std::vector<int> cities;
};

