#include "pch.h"
#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(int** dataMatrix, int size) : Algorithm(dataMatrix, size)
{
}

Node* BranchAndBound::newNode(int** parentMatrix,int level, int from, int where)
{
	Node* node = new Node(size);

	//przepisujemy zredukowana macierze z rodzica do dziecka
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size;j++)
			node->reducedMatrix[i][j] = parentMatrix[i][j];
	}
	
	//zerujemy wiersz i kolumne dla nowe sciezki
	//oraz polaczenie z pierwszym miastem
	for (int i = 0; level != 0 && i < size; i++)
	{
		node->reducedMatrix[from][i] = -1;
		node->reducedMatrix[i][where] = -1;
	}

	node->reducedMatrix[where][0] = -1;

	//zapisujemy poziom node'a i misto ktore przechowuje
	node->level = level;
	node->vertex = where;
	return node;
}

void BranchAndBound::rowReduction(int** reducedMatrix, int* row)
{
	std::fill_n(row, size, INT_MAX);

	//szukamy najmniejszej wartosci w kazdym wierszu
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (reducedMatrix[i][j] < row[i] && reducedMatrix[i][j] > -1)
				row[i] = reducedMatrix[i][j];

	//odejmujemy najmniejsza wartosc z kazdego wiersz
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (reducedMatrix[i][j] != -1 && row[i] != INT_MAX)
				reducedMatrix[i][j] -= row[i];
}

void BranchAndBound::columnReduction(int** reducedMatrix, int* col)
{
	std::fill_n(col, size, INT_MAX);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (reducedMatrix[i][j] < col[j] && reducedMatrix[i][j] > -1)
				col[j] = reducedMatrix[i][j];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (reducedMatrix[i][j] != -1 && col[j] != INT_MAX)
				reducedMatrix[i][j] -= col[j];
}

int BranchAndBound::calculateReductionCost(int** reducedMatrix)
{
	int cost = 0;
	int *row = new int[size];
	int *col= new int[size];
	rowReduction(reducedMatrix, row);
	columnReduction(reducedMatrix, col);

	for (int i = 0; i < size; i++)
	{
		if (row[i] != INT_MAX) cost += row[i];
		if (col[i] != INT_MAX) cost += col[i];
	}
	return cost;
}



void BranchAndBound::countBestPath()
{
	std::vector<Node*> nodes;

	//zaczynamy od pierwszego wierzcholka
	Node* root = newNode(distancesMatrix, 0, 0, 0);
	root->cost = calculateReductionCost(root->reducedMatrix);
	nodes.push_back(root);

	//iterujemy petle dopoki nie przejdziemy calego drzewa
	//lub zwrocimy wynik przez odrzucenie "drozszych" sciezek
	while (!nodes.empty())
	{
		//szukamy node'a z najmniejszym kosztem
		//zapisujemy go w "min" i usówamy z vectora
		int index = 0;
		int tmp = INT_MAX;
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i]->cost < tmp)
			{
				index = i;
				tmp = nodes[i]->cost;
			}
		//std::cout << nodes[i]->vertex +1 <<" " << nodes[i]->cost << "|"<<"\n";
		//printData(nodes[i]->reducedMatrix);
		}
		//std::cout << "==============================================================" << '\n';
		Node* min = nodes.at(index);
		nodes.erase(nodes.begin()+index);
		//warunek wyjsca z petli
		//wszystkie miasta odwiedzone 
		if (min->level == size - 1)
		{
			result = min->cost;
			return;
		}

		int i = min->vertex;
		for (int j = 0; j < size; j++)
		{
			//dodajemy kolejne node'y
			if (min->reducedMatrix[i][j] != -1)
			{
				Node* child = newNode(min->reducedMatrix,min->level + 1, i, j);
				child->cost = min->cost + min->reducedMatrix[i][j]+ calculateReductionCost(child->reducedMatrix);
				nodes.push_back(child);
			}
		}
		delete min;
	}
}

