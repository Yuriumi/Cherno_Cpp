#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
	int example[5];

	Entity()
	{
		for (int i = 0; i < 5; i++)
			example[i] = 2;
	}

	int ArrayCount()
	{
		return sizeof(example) / sizeof(int);
	}
};

int main()
{
	const char* name_a = "Cherno";	// C�����ַ���
	// char* name_b = "Cherno";		����,˫�����е����ַ�������,const char*
	char name_c[3] = {'a','b','c'};	// ����ֹ��
	char name_d[4] = { 'a','b','c',0 };	// �ֶ������ֹ��

	LOG(name_a);
	LOG(name_c);
	LOG(name_d);

	std::string name = "Cherno";
	LOG(name.size());

	// std::string m_name = "Cherno" + "Hello!";

	std::string m_name = "Cherno";

	m_name += "Hello!";

	bool contains = m_name.find("no") != std::string::npos;

	LOG(contains);
	
	std::cin.get();
}