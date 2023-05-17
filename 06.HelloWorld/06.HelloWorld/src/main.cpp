#include <iostream>
#include <string>
#include <array>

#define LOG(x) std::cout<< x <<std::endl

template<typename T>
void Print(T t)
{
	LOG(t);
}

template<typename T,unsigned int N>
void PrintArray(const std::array<int, N> m_Array, void(*print)(T t))
{
	for (auto a : m_Array)
		print(a);
}

int main()
{
	std::array<int, 2> array_int;

	array_int[0] = 0;
	array_int[1] = 1;

	PrintArray<int,2>(array_int, Print);

	PrintArray<int, 2>(array_int, [](int value) {LOG(value); });
}