#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
	bool m_Attack;

public:
	Entity(const std::string name)
		: m_Name(name), m_Age(-1), m_Attack(1.0f)
	{}

	Entity(int age)
		: m_Name("Unknow"), m_Age(age), m_Attack(1.0f)
	{}

	explicit Entity(bool attack)
		: m_Name("Unknow"), m_Age(-1), m_Attack(0)
	{}
};

int main()
{
	Entity entity_1(22);
	Entity entity_2 = 22;

	Entity entity_a("cherno");
	// Entity entity_b = "cherno";	ERROR : 隐式转换只能进行一次
	Entity entity_b = std::string("cherno");

	Entity e1(true);
	// Entity e2 = "114514";
}