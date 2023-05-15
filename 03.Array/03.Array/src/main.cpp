#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

class Entity
{
private:
	int X{ 10 }, Y{ 10 };
	mutable int speed{ 2 };

public:
	int GetX() const
	{
		speed = 0;
		return X;
	}

	void SetX(int x)
	{
		X = x;
	}
};

void PrintEntity(const Entity& e)
{
	// e.Set();	ERROR
	int temp = e.GetX();
	LOG(temp);
}

int main()
{
	int number = 10;
	const int MaxAge = 90;

	const int* a = new int;	// ָ��ָ����ڴ�����Ϊ����,�����޸�.

	// *a = 10;
	a = &number;
	LOG(a);
	a = &MaxAge;
	LOG(a);

	int* const b = new int;	// ָ��ָ����ڴ��ַΪ���������޸�.

	LOG(b);
	*b = 20;
	// b = &number;

	LOG(b);

	LOG("-------------");

	Entity e;

	PrintEntity(e);

	std::cin.get();
}