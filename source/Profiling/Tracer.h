#pragma once
#include <fstream>
struct ProfileResult
{
	const char* name;
	long long start, end;

};

class Tracer
{
private:
	const char* m_curr;
	std::ofstream m_os;
	int m_fnCount;
public:
	Tracer();
	void writeProfile(const ProfileResult& result);
	void writeHeader();
	void writeFooter();
	static Tracer& get();
	void beginSession(const char* name, const char* filepath = "results.json");
	void endSession();

};

