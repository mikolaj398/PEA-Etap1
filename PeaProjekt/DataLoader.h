#pragma once
#include <fstream>
#include <string>
#include <iostream>
class DataLoader
{
private:
	int **dataMatrix;
	int size;

public:
	DataLoader(std::string);
	int** getDataMatrix();
	int** getRandom(int size);
	int getSize();
	void PrintData();
	~DataLoader();
};

