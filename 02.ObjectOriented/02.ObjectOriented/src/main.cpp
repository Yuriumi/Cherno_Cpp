#include <iostream>

#define LOG(x) std::cout << x << std::endl

// 不适用局部静态
//class Singleton
//{
//private:
//	static Singleton* s_Instance;
//public:
//	static Singleton& Get() { return *s_Instance; }
//};
//
//Singleton* Singleton::s_Instance = nullptr;

class Singleton
{
public:
	static Singleton& Get()
	{
		static Singleton instance;
		return instance;
	}
};

void Function()
{
	static int i = 0;
	i++;
	LOG(i);
}

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Function();
	Function();
	Function();
	Function();
	Function();

	std::cin.get();
}