#include <iostream>

void MultiplyAndLog(int a, int b)
{
	std::cout << a * b << std::endl;
}

int main()
{
	std::cout << "Hello World!" << std::endl;
	std::cout << "--------------------" << std::endl;

	MultiplyAndLog(2, 8);
	MultiplyAndLog(4, 9);
	MultiplyAndLog(52,66);

	std::cin.get();
}