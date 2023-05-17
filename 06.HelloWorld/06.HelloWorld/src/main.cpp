#include <iostream>
#include <string>
#include <array>

#define LOG(x) std::cout<< x <<std::endl

template<unsigned int N>
void PrintArray(const std::array<int, N>& m_Array)
{
	/*for (auto a : m_Array)
	{
		LOG(a);
	}*/

	for (unsigned int i = 0; i < N; i++)
	{
		LOG(m_Array[i]);
	}
}

int main()
{
	std::array<int, 5> array_int;
	array_int[0] = 0;
	array_int[1] = 1;
	array_int[2] = 2;
	array_int[3] = 3;
	array_int[4] = 4;

	PrintArray<5>(array_int);
}