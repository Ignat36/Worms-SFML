#include "Timer.h"

void Timer::Start()
{
	isActive = true;
	start = std::chrono::high_resolution_clock::now();
}

void Timer::Stop()
{
	isActive = false;
	end = std::chrono::high_resolution_clock::now();
}

bool Timer::Active()
{
	return isActive;
}

float Timer::Elapsed()
{
	std::chrono::time_point<std::chrono::steady_clock> current;
	current = std::chrono::high_resolution_clock::now();

	long long elapsed = (std::chrono::duration_cast<std::chrono::microseconds>(current - start)).count();

	if (!isActive) return 0;
	return elapsed / MKS_PER_SECOND;
}

Timer::Timer()
{
	isActive = false;
	start = std::chrono::high_resolution_clock::now();
	end = std::chrono::high_resolution_clock::now();
}
