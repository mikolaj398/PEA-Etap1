#include "pch.h"
#include "DataLoader.h"


DataLoader::DataLoader(std::string path)
{
	std::ifstream dataFile(path);

	if (!dataFile) {
		std::cout << "Nie mozna otworzyc pliku.\n";
		return;
	}

	std::string name;

	dataFile >> name;
	dataFile >> size;

	dataMatrix = new int*[size];
	for (auto i = 0; i < size; i++)
	{
		dataMatrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			dataFile >> dataMatrix[i][j];
	}
	dataFile.close();
}

int** DataLoader::getDataMatrix()
{
	return dataMatrix;
}
int** DataLoader::getRandom(int size)
{
	int **data = new int* [size];
	for (auto i = 0; i < size; i++)
	{
		data[i] = new int[size];
		for (int j = 0; j < size; j++)
			if (i == j)
				data[i][j] = -1;
			else
				data[i][j] = rand() % 100;
	}
	return data;
}
int DataLoader::getSize()
{
	return size;
}

void DataLoader::PrintData()
{	
	std::cout << "   ";
	for (int i = 0; i < size; i++)
	{
		std::cout.width(5);
		std::cout << i<< " ";
	}
	std::cout << '\n';
	for (int i = 0; i < size; i++)
	{
		std::cout.width(2);
		std::cout << i << ")";
		for (int j = 0; j < size; j++)
		{
			std::cout.width(5);
			std::cout << dataMatrix[i][j]<<" ";
		}
		std::cout << '\n';
	}
}

DataLoader::~DataLoader()
{
	delete dataMatrix;
}
