#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
	float x, y;

	Entity(){}

	Entity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	void Print()
	{
		LOG(x << "," << y);
	}
};

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Entity e;
	LOG(e.x << "," << e.y);
	e.Print();

	std::cin.get();
}