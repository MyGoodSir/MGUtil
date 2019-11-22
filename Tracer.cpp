#include "Tracer.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
Tracer::Tracer() : m_curr(nullptr), m_fnCount(0)
{
}

void Tracer::writeProfile(const ProfileResult& result)
{
	if (m_fnCount++ > 0)
		m_os << ",";

	std::string name = result.name;
	std::replace(name.begin(), name.end(), '"', '\'');

	m_os << "{";
	m_os << "\"cat\":\"function\",";
	m_os << "\"dur\":"<<(result.end-result.start)<<',';
	m_os << "\"name\":\"" << name <<"\",";
	m_os << "\"ph\":\"X\",";
	m_os << "\"pid\":0,";
	m_os << "\"tid\":0,";
	m_os << "\"ts\":"<<result.start;
	m_os << "}";

	m_os.flush();
}

void Tracer::writeHeader()
{
	m_os << "{\"otherData\": {},\"traceEvents\":[";
	m_os.flush();
}

void Tracer::writeFooter()
{
	m_os << "]}";
	m_os.flush();
}

Tracer& Tracer::get()
{
	static Tracer* inst = new Tracer();
	return *inst;
}

void Tracer::beginSession(const char* name, const char* filepath)
{
	m_os.open(filepath);
	writeHeader();
	m_curr = name;
}

void Tracer::endSession()
{
	writeFooter();
	m_os.close();
	m_curr = "";
	m_fnCount = 0;
}
