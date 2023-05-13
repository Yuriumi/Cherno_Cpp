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

	int x = 5;
	if (x == 5)
		std::cout << "Hello World!" << std::endl;

	std::cin.get();
}