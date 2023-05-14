#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
	int example[5];

	Entity()
	{
		for (int i = 0; i < 5; i++)
			example[i] = 2;
	}

	int ArrayCount()
	{
		return sizeof(example) / sizeof(int);
	}
};

int main()
{
	Entity e;
	
	std::cin.get();
}