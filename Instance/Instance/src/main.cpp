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
	// ջ�ϴ���
	Entity entity01;
	Entity entity02("cherno");

	// ���ϴ���
	Entity* entity03 = new Entity();
	Entity* entity04 = new Entity("cherno");
}