#include <iostream>
#include <string>
#include <array>
#include <functional>
#include <vector>

#define LOG(x) std::cout<< x <<std::endl

template<typename T>
void Print(T t)
{
	LOG(t);
}

template<typename T,unsigned int N>
void PrintArray(const std::array<int, N> m_Array, const std::function <void(int)> func)
{
	for (auto a : m_Array)
		func(a);
}

int main()
{
	std::array<int, 2> array_int;

	std::vector<int> value = { 1,5,3,4,2 };

	// 我们迭代这个数组,使用我们自己定义的规则进行查找
	auto it = std::find_if(value.begin(), value.end(), [](int value) {return value > 3; });

	array_int[0] = 0;
	array_int[1] = 1;

	int a{ 10 };

	// PrintArray<int,2>(array_int, Print);

	PrintArray<int, 2>(array_int, [a](int value) {LOG(a); });
}