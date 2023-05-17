#include <iostream>
#include <string>
#include <array>
#include <functional>
#include <vector>

#define LOG(x) std::cout<< x <<std::endl

namespace apple
{
	void print(const std::string& string)
	{
		LOG(string);
	}
}

namespace orange
{
	void print(const char* string)
	{
		std::string temp = string;
		std::reverse(temp.begin(),temp.end());

		LOG(temp);
	}
}

int main()
{
	using namespace apple;
	using namespace orange;

	// 编译器不知道我们要使用那个print,于是他有限选择可以显示转换的.
	print("cherno");
}