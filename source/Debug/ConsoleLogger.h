#pragma once
#include <Windows.h>
#include <string>

class ConsoleLogger
{
private:
	HANDLE hConsole;

public:
	enum COLOR
	{
		BLACK = 0,
		BLUE = 1, 
		GREEN = 2,
		DARK_CYAN = 3,
		RED = 4,
		PURPLE = 5,
		GOLD = 6,
		LIGHT_GRAY = 7,
		GRAY = 8,
		LIGHT_BLUE = 9,
		LIME = 10,
		CYAN = 11,
		PINK = 12,
		MAGENTA = 13,
		YELLOW = 14,
		WHITE = 15

	};

	
	//TODO: Add formatting options, time & date, etc

	ConsoleLogger() { hConsole = GetStdHandle(STD_OUTPUT_HANDLE); };
	void Log(std::string& in, COLOR text, COLOR bg);
	void Log(const char* in, COLOR text, COLOR bg);
	~ConsoleLogger() { SetConsoleTextAttribute(hConsole, 15); }


	

};

