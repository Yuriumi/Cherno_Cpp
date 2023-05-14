#include <iostream>

#define LOG(x) std::cout << x << std::endl

int s_Variable;

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	LOG(s_Variable);

	std::cin.get();
}