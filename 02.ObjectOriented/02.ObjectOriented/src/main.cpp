#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
	virtual std::string GetName() { return "Cherno"; }
};

class Player : public Entity
{
public:
	std::string GetName() override { return "Player"; }
};

void PrintName(Entity* entity)
{
	LOG(entity->GetName());
}

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Entity* e = new Entity();
	PrintName(e);

	Player* p = new Player();
	PrintName(p);

	std::cin.get();
}