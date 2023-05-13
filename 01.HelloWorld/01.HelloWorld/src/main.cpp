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

	for (unsigned int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue;

		Log("Hello World!");
		std::cout << i << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	for (unsigned int i = 0; i < 5; i++)
	{
		if (i > 2)
			break;

		Log("Hello World!");
	}

	std::cout << "--------------------" << std::endl;

	for (unsigned int i = 0; i < 5; i++)
	{
		if (i > 2)
			return 0;

		Log("Hello World!");
	}

	std::cin.get();
}