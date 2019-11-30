#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "DataLoader.h"
#include "Algorithm.h"
#include "Stopwatch.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
#include "Dynamic.h"
#include "PathTester.h"
void printMenu()
{
	std::cout << "1. Testuj funkcje celu.\n";
	std::cout << "2. Brute force.\n";
	std::cout << "3. Branch and bound.\n";
	std::cout << "4. Dynamic programing.\n";
	std::cout << "5. Wszystkie.\n";
	std::cout << "0. Wyjscie.\n\n";
}
int main()
{
	std::string path = "";
	std::cout << "Podaj sciezke do pliku: "; std::cin >> path;
	auto data = std::make_unique<DataLoader>("data\\" + path + ".txt");
	auto dataMatrix = data->getDataMatrix();
	int dataSize = data->getSize();
	data->PrintData();

	Stopwatch sw;
	BruteForce bruteForce(dataMatrix, dataSize);
	BranchAndBound bnb(dataMatrix, dataSize);
	Dynamic dynamic(dataMatrix, dataSize);
	PathTester tester(dataMatrix, dataSize);

	int choice = -1;
	while (choice != 0)
	{
		printMenu();
		std::cin >> choice;
		switch (choice)
		{
		case 1: 
			tester.test();
			break;
		case 2:
			sw.start();
			bruteForce.countBestPath();
			sw.stop();
			bruteForce.printResult();
			std::cout << "Czas: " << sw.getTime() << "[ms]\n";
			break;
		case 3:
			sw.start();
			bnb.countBestPath();
			sw.stop();
			bnb.printResult();
			std::cout << "Czas: " << sw.getTime() << "[ms]\n";
			break;
		case 4:
			sw.start();
			dynamic.countBestPath();
			sw.stop();
			dynamic.printResult();
			std::cout << "Czas: " << sw.getTime() << "[ms]\n";
			break;
		case 5:
			std::cout << "Brute Force:";
			sw.start();
			bruteForce.countBestPath();
			sw.stop();
			bruteForce.printResult();
			std::cout << "Czas: " << sw.getTime() << "[ms]\n";
			std::cout << '\n';

			std::cout << "Branch and Bound:";
			sw.start();
			bnb.countBestPath();
			sw.stop();
			bnb.printResult();
			std::cout << "Czas: " << sw.getTime() << "[ms]\n";
			std::cout << '\n';

			std::cout << "Dynamic Programming:";
			sw.start();
			dynamic.countBestPath();
			sw.stop();
			dynamic.printResult();
			std::cout << "Czas: " << sw.getTime() << "[ms]\n";
			std::cout << '\n';
			break;
		case 6:

			std::ofstream myfile;
			std::vector<int> sizes = { 6,7,8, 9, 10, 11, 12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
			int howManyMeasurements = 1;
			for (int j = 0; j <sizes.size()-19; j++)
			{
				for (int i = 0; i < howManyMeasurements; i++)
				{
					myfile.open("C:\\Users\\Mikolaj\\Desktop\\PEA\\Results\\bnb.txt", std::ios_base::app);
					if (i==0) myfile << "Size:" << std::to_string(sizes[j]) << "\n";
					auto randomMatrix = data->getRandom(sizes[j]);
					BranchAndBound bruteForce(randomMatrix, sizes[j]);
					bruteForce.printData(randomMatrix);
					sw.start();
					bruteForce.countBestPath();
					sw.stop();
					myfile << sw.getTime() << '\n';
					myfile.close();
				}
			}
			//std::cout << LONG_MAX << std::endl;
			system("C:\\WINDOWS\\System32\\shutdown /s");
			return 0;
		}
	}
	return 0;
}
