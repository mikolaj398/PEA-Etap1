#pragma once
#include <iostream>
#include <chrono>
class Stopwatch
{
public:
	void start();
	void stop();
	long getTime();

private:
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point stopTime;
};

