#include "pch.h"
#include "PathTester.h"

PathTester::PathTester(int** dataMatrix, int size) : Algorithm(dataMatrix, size)
{

}

void PathTester::test()
{
	int choice = -1;
	while (choice != 0)
	{
		std::cout << "1. Wprowadz sciezke recznie.\n";
		std::cout << "2. Wygeneruje automatycznie.\n";
		std::cout << "0. Wstecz. \n";
		std::cin >> choice;
		switch (choice)
		{
		case 1: testManual(); break;
		case 2: testAutomatic(); break;
		case 0: return;
		default: continue;
		}
	}
}
void PathTester::testManual()
{
	std::vector<int> path{ 1,2,0 };
	//for (int i = 0; i < cities.size(); i++)
	//{
	//	int tmp;
	//	std::cin >> tmp;
	//	path.push_back(tmp);
	//}
	std::cout<<"Wartosc podanej sciezki: " << countDistance(path) << "\n";
}
void PathTester::testAutomatic()
{
	int howManyTests;
	std::cout << "Podaj ile testow chcesz wykonac: "; std::cin >> howManyTests;
	for (int i = 0; i < howManyTests; i++)
	{
		std::vector<int> path = cities;
		std::random_shuffle(path.begin(), path.end());
		for (int i = 0; i < path.size(); i++)
			std::cout << path[i] << " ";
		std::cout << "\nWartosc podanej sciezki: " << countDistance(path) << "\n";
	}

}

void PathTester::countBestPath()
{
}
