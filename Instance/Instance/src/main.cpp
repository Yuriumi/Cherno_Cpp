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
	int* a = new int;		// 分配4字节的空间
	int* b = new int[50];	// 分配4 * 50字节的内存空间

	delete a;
	delete[] b;

	Entity* e1 = new Entity;	// 我们不需要使用括号,因为它有默认的构造函数
	Entity* e2 = new Entity[50];

	delete e1;
	delete[] e2;

	Entity* e = new Entity();

	Entity* e = (Entity*)malloc(sizeof(Entity));

	delete e;

	int* b = new int[50];

	Entity* entity = new(b) Entity("cherno");
}