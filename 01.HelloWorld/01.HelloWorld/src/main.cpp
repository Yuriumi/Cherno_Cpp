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

	int var = 8;

	void* ptr = 0; // 表示空指针,0对于内存地址是无效的
	ptr = NULL;
	ptr = nullptr;

	ptr = &var;

	int* ptr_a = &var;

	*ptr_a = 10;

	std::cout << *ptr_a << std::endl;
	std::cout << var << std::endl;

	char* buffer = new char[8];
	memset(buffer, 0, 8);

	delete[] buffer;

	std::cin.get();
}