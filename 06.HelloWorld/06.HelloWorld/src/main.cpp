#include <iostream>
#include <string>
#include <array>

#define LOG(x) std::cout<< x <<std::endl

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
}