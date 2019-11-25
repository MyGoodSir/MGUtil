#include "Timer.h"
#include "Tracer.h"

Timer::Timer(const char* name) : m_name(name), m_stopped(false)
{
	m_initialTimepoint = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
	auto finalTimepoint = std::chrono::high_resolution_clock::now();

	long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_initialTimepoint).time_since_epoch().count();
	long long finish = std::chrono::time_point_cast<std::chrono::microseconds>(finalTimepoint).time_since_epoch().count();
	
	Tracer::get().writeProfile({ m_name, start, finish });
	m_stopped = true;

}

Timer::~Timer()
{
	if (!m_stopped)
		stop();
}
