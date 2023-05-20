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

class AnotherClass : public Base
{
public:
	AnotherClass() {}
	~AnotherClass() {}
};

int main()
{
	double dpi = 3.1415926;
	int number = static_cast<int>(dpi);
	double d = 1.1;
	void* p = &d;
	double* dp = static_cast<double*>(p);

	Entity* entity = new Entity();
	Base* base = entity;

	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);

	if (ac)
	{
		LOG("Cast");
	}
}