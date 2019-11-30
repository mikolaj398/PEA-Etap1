#include "pch.h"
#include "Algorithm.h"



Algorithm::Algorithm(int ** dataMatrix, int size)
{
	result = INT_MAX;
	this->size = size;
	for (int i = 0; i < size; i++)
		cities.push_back(i);
	initMatrix(dataMatrix);
}

Algorithm::~Algorithm()
{
	delete distancesMatrix;
}

void Algorithm::printResult()
{
	std::cout << "\nKoszt: " << result<<"\n";
}
int Algorithm::countDistance(std::vector<int> cities)
{
	int distance = 0;
	int sum = 0;
	for (int i = 0; i < cities.size() - 1; i++)
	{
		//std::cout<<"From "<<cities[i]<<" to "<<cities[i+1]<<": "<< dataMatrix[cities[i]][cities[i + 1]]<<"\n";
		distance = distancesMatrix[cities[i]][cities[i + 1]];
		if (distance > 0)
			sum += distance;
	}
	//std::cout << "From " << cities[cities.size() - 1] << " to " << cities[0] << ": " << dataMatrix[cities[cities.size() - 1]][cities[0]] << "\n";
	distance = distancesMatrix[cities[cities.size() - 1]][cities[0]];
	if (distance>0)
		return sum += distance;
	return INT_MAX;
}

void Algorithm::printData(int ** dataMatrix)
{
	int size = cities.size();
	std::cout << "   ";
	for (int i = 0; i < size; i++)
	{
		std::cout.width(5);
		std::cout << i << " ";
	}
	std::cout << '\n';
	for (int i = 0; i < size; i++)
	{
		std::cout.width(2);
		std::cout << i << ")";
		for (int j = 0; j < size; j++)
		{
			std::cout.width(5);
			std::cout << dataMatrix[i][j] << " ";
		}
		std::cout << '\n';
	}
}
void Algorithm::initMatrix(int** dataMatrix)
{
	distancesMatrix = new int* [size];
	for (unsigned short i = 0; i < size; i++)
	{
		distancesMatrix[i] = new int[size];
		for (unsigned short j = 0; j < size; j++)
			distancesMatrix[i][j] = dataMatrix[i][j];
	}
}
