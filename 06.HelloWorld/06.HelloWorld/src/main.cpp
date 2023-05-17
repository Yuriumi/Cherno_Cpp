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

	// ��������֪������Ҫʹ���Ǹ�print,����������ѡ�������ʾת����.
	print("cherno");
}