#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::Log(std::string& in, ConsoleLogger::COLOR text, ConsoleLogger::COLOR bg)
{
	int color = text + (bg * 16);
	SetConsoleTextAttribute(hConsole, color);

	std::cout << in ;

	SetConsoleTextAttribute(hConsole, 15);
}

void ConsoleLogger::Log(const char* in, ConsoleLogger::COLOR text, ConsoleLogger::COLOR bg)
{
	int color = text + (bg * 16);
	SetConsoleTextAttribute(hConsole, color);

	std::cout << in;

	SetConsoleTextAttribute(hConsole, 15);
}
