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
		Log("Hello World!");
	}

	unsigned int i = 0;

	while (i < 5)
	{
		Log("Hello World!");
		i++;
	}

	do
	{
		Log("Hello World!");
		i++;
	} while (i < 5);

	std::cin.get();
}