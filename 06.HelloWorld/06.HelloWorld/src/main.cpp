#include <iostream>
#include <string>
#include <array>

#define LOG(x) std::cout<< x <<std::endl

// ͨ���������������õķ�ʽ
void SetBasic(std::string& out_Name, int& out_Age)
{
	out_Name = "cherno";
	out_Age = 27;
}

// ͨ������������ָ��ķ�ʽ
void SetBasic(std::string* const out_Name, int* const out_Age)
{
	*out_Name = std::string("Sadaharu");
	*out_Age = 22;
}

// ͨ�����鷵��
std::array<int, 2>GetAge()
{
	std::array<int, 2> result;

	result[0] = 27;
	result[1] = 22;

	return result;
}

// ʹ��std::pair��������ֵ
std::pair<bool, int>GetAge(const std::string& name)
{
	std::pair<bool, int> result;

	if (name.compare("cherno"))
	{
		result = std::make_pair(true, 27);
	}
	else
	{
		result = std::make_pair(false, -1);
	}
}

// ʹ�ýṹ��
struct Entity
{
	std::string s_Name;
	int s_Age;
};

Entity SetBasic(const std::string& out_Name, const int& out_Age)
{
	Entity e;

	e.s_Name = out_Name;
	e.s_Age = out_Age;

	return e;
}

int main()
{
	std::string m_Name{"Unknow"};
	int m_Age{ -1 };

	SetBasic(m_Name, m_Age);
	LOG(m_Name);
	LOG(m_Age);
	SetBasic(&m_Name, &m_Age);
	LOG(m_Name);
	LOG(m_Age);
}