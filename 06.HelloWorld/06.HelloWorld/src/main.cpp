#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <vector>

#define LOG(x) std::cout<< x <<std::endl

#define WIDTH 1920
#define HEIGHT 1080

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
		: start(std::chrono::high_resolution_clock::now()) {}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();

		duration = end - start;
		float ms = duration.count() * 1000;
		LOG(ms << "ms");
	}
};

class Base
{
public:
	Base()
	{
		std::cout << "Created Base!\n";
	}
	virtual ~Base()
	{
		std::cout << "Destory Base\n";
	}
};

class Entity : public Base
{
private:
	int* m_array;

public:
	Entity()
	{
		m_array = new int[5];
		std::cout << "Created Entity!\n";
	}
	~Entity()
	{
		delete[] m_array;
		std::cout << "Destory Entity!\n";
	}
};

int main()
{
	Base* base = new Base();
	Entity* entity = new Entity();

	delete base;
	delete entity;

	std::cout << "============================\n";

	Base* poly = new Entity();
	delete poly;	// 这里我们调用的是Base的析构函数,Entity对象中的成员变量并未删除会一直存在在内存中
}