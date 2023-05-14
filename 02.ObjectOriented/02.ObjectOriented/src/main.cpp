#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
	float X, Y;

	void Move(float Xa, float Ya)
	{
		X += Xa;
		Y += Ya;
	}
};

class Player : public Entity
{
public:
	const char* Name;

	void PrintName()
	{
		LOG(Name);
	}
};

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	

	std::cin.get();
}