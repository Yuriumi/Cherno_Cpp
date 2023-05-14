#include <iostream>

#define LOG(x) std::cout << x << std::endl

enum Example : unsigned int
{
	A, B, C
};

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Example value = B;

	if (value == B)
	{
		// Do something here
	}

	std::cin.get();
}