#include <iostream>
#include "other.h"
#include "Log.h"

void Log(const char* message)
{
	std::cout << message << std::endl;
}

void Increment(int value)
{
	value++;
}

void RefIncrement(int& value)
{
	value++;
}

int main()
{
	std::cout << "Hello World!" << std::endl;
	std::cout << "--------------------" << std::endl;

	int a = 5;
	int& ref_a = a;

	ref_a = 2;

	Increment(a);
	std::cout << a << std::endl;

	RefIncrement(a);
	std::cout << a << std::endl;

	std::cin.get();
}