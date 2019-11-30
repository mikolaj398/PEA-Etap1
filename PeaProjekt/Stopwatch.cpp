#include "pch.h"
#include "Stopwatch.h"

void Stopwatch::start() 
{
	startTime = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() 
{
	stopTime = std::chrono::high_resolution_clock::now();
}

long Stopwatch::getTime() 
{
	return std::chrono::duration_cast<std::chrono::microseconds>(stopTime-startTime).count();
}
