#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
	const std::string m_Name;

public:
	Entity()
		: m_Name("Unknow")
	{
		std::cout << "Created Entity" << std::endl;
	}

	void PrintName() const
	{
		std::cout << m_Name << std::endl;
	}
};

int main()
{
	{
		// std::unique_ptr<Entity> entity_a = new Entity();	不能隐式转换
		std::unique_ptr<Entity> entity_b(new Entity());	// 可以但不建议
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();

		// std::unique_ptr<Entity> e = entity;	不安全的,实际上编译器也会阻止你这么干,防止出现错误

		std::shared_ptr<Entity> shareE;
		{
			std::shared_ptr<Entity> shareEntity_a(new Entity());	// 同样不推荐
			std::shared_ptr<Entity> shareEntity = std::make_shared<Entity>();	// 推荐

			shareE = shareEntity;
		}	// shareEntity已经超出生命周期但没有调用析构函数,因为shareE还存在,引用记数不为0
	}	// 析构被调用,shareE也超出了生命周期
}