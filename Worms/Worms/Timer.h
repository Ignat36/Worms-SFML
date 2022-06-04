#pragma once

#include <ctime>
#include <chrono>

class Timer
{
public:
	void Start();
	void Stop();
	bool Active();
	float Elapsed();

public:
	Timer();

private:
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> end;
	bool isActive;

	float MKS_PER_SECOND = 1e6;
};

