#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

class Example
{
private:
	std::string e_Name;

public:
	Example()
	{
		LOG("Creat a example" << e_Name);
	}
	
	Example(std::string name)
		: e_Name(name)
	{
		LOG("Creat a example " << e_Name);
	}
};

class Entity
{
private:
	std::string m_Name;
	Example e;

public:
	Entity()
		: m_Name("Unknow")
	{
		e = Example();
	}

	Entity(std::string name)
		: m_Name(name),e(Example("one"))
	{

	}

	void PrintName()
	{
		LOG(m_Name);
	}
};

int main()
{
	Entity e0;
	//e0.PrintName();

	Entity e1("Cherno");
	//e1.PrintName();

	std::cin.get();
}