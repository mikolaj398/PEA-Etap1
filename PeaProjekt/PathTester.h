#pragma once
#include "Algorithm.h"
#include <algorithm>   
class PathTester :public Algorithm
{
public:
	PathTester(int**, int);
	void test();
	void testManual();
	void testAutomatic();
	void countBestPath();
};

