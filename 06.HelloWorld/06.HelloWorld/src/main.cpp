#include <iostream>
#include <string>
#include <array>

#ifdef PR_DEBUG
#define LOG(x) std::cout<< x <<std::endl
#else
#define PR_DEBUG
#endif

#define WAIT std::cin.get()

template<typename T>
void Print(const T& temp)
{
	LOG(temp);
}

template<typename T,int N>
class Array
{
private:
	T m_array[N];
};

int main()
{
	Print(1);
	Print("Hello World!");

	Array<int, 5> array_int;
	Array<float, 5> array_float;

	WAIT;
}