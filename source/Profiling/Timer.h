#pragma once
#include <cmath>
#include <chrono>
#include <iostream>
class Timer
{
private:
	const char* m_name;
	std::chrono::time_point<std::chrono::steady_clock> m_initialTimepoint;
	bool m_stopped;
public:
	Timer(const char* name);
	void stop();
	~Timer();
};

