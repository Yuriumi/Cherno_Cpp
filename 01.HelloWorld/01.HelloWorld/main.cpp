#include <iostream>
#include "other.h"
#include "Log.h"

void Log(const char* message)
{
	std::cout << message << std::endl;
}

int main()
{
	std::cout << "Hello World!" << std::endl;
	std::cout << "--------------------" << std::endl;

	LogInit();
	Log("Hello World!");

	std::cin.get();
}