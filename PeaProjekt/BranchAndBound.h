#pragma once
#include "Algorithm.h"
#include <vector>
struct Node
{
	int **reducedMatrix;
	int cost=0;
	int vertex=0;
	int level=0;

	Node(int size)
	{
		reducedMatrix = new int*[size];
		for (int i = 0; i < size; i++)
			reducedMatrix[i] = new int[size];
	}
	~Node()
	{
		delete reducedMatrix;
	}
};
class BranchAndBound : public Algorithm
{
public:
	BranchAndBound(int **, int);
	void countBestPath() override;
	void rowReduction(int** , int* );
	void columnReduction(int** , int* );
	Node* newNode(int** , int , int , int );
	int calculateReductionCost(int** );
};

