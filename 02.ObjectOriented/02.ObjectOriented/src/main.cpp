#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

class Printable
{
public:
	virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
public:
	std::string GetClassName() override { return "Player"; }
};

void PrintName(Printable* p)
{
	LOG(p->GetClassName());
}

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Printable* e = new Entity();
	Printable* p = new Player();

	PrintName(e);
	PrintName(p);

	std::cin.get();
}