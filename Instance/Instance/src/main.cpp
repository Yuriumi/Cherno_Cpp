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
	int* a = new int;		// ����4�ֽڵĿռ�
	int* b = new int[50];	// ����4 * 50�ֽڵ��ڴ�ռ�

	delete a;
	delete[] b;

	Entity* e1 = new Entity;	// ���ǲ���Ҫʹ������,��Ϊ����Ĭ�ϵĹ��캯��
	Entity* e2 = new Entity[50];

	delete e1;
	delete[] e2;

	Entity* e = new Entity();

	Entity* e = (Entity*)malloc(sizeof(Entity));

	delete e;

	int* b = new int[50];

	Entity* entity = new(b) Entity("cherno");
}