#include <iostream>

#define LOG(x) std::cout << x << std::endl

int s_Variable;

struct Entity
{
	static int x;
	int y{5};

	void Print()
	{
		LOG(x);
	}

	static void PrintHello(Entity e)
	{
		LOG("Hello!" << e.y);
	}
};

//static void PrintHello()
//{
//	LOG("Hello!");
//}

int Entity::x;

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Entity e;
	e.x = 2;

	Entity::x = 5;

	e.Print();

	Entity::PrintHello(e);

	std::cin.get();
}