#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;

public:
	Entity()
		: m_Name("Unknow")
	{}

	Entity(std::string name)
		: m_Name(name)
	{}
};

int main()
{
	// 栈上创建
	Entity entity01;
	Entity entity02("cherno");

	// 堆上创建
	Entity* entity03 = new Entity();
	Entity* entity04 = new Entity("cherno");
}