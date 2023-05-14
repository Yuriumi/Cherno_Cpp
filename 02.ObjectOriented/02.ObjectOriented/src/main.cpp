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

	~Entity()
	{
		LOG("Destory Entity");
	}

	void Print()
	{
		LOG(x << "," << y);
	}
};

void Function()
{
	Entity e;
	LOG(e.x << "," << e.y);
	e.Print();
}

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Function();

	std::cin.get();
}