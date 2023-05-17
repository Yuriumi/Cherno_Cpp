#include <iostream>
#include <string>
#include <array>
#include <functional>
#include <vector>

#define LOG(x) std::cout<< x <<std::endl

inline namespace apple
{
	void print(const std::string& string)
	{
		LOG(string);
	}

	namespace orange
	{
		void print(const char* string)
		{
			std::string temp = string;
			std::reverse(temp.begin(), temp.end());

			LOG(temp);
		}
	}
}

namespace red
{
	inline namespace blue
	{
		class One
		{
		public:
			int number1{10};
		};
	}

	namespace blue
	{
		class Two
		{
		public:
			int number2{ 20 };
		};
	}

	void PrintNumber()
	{
		One one;
		LOG(one.number1);
		Two two;
		LOG(two.number2);
	}
}

void SetNumber()
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
	using namespace apple;
	using namespace orange;

	// ��������֪������Ҫʹ���Ǹ�print,����������ѡ�������ʾת����.
	print("cherno");
}