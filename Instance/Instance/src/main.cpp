#include <iostream>
#include <memory>

#define LOG(x) std::cout << x << std::endl

class Entity
{
private:
	int x;

public:
	void Print()
	{
		LOG("Hello!");
	}
};

struct Vector3
{
	int x, y, z;
	float speed;
};

class ScopedPtr
{
private:
	Entity* m_Ptr;

public:
	ScopedPtr(Entity* entity)
		: m_Ptr(entity)
	{

	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}

	Entity* operator->()
	{
		return m_Ptr;
	}

	const Entity* operator->() const
	{
		return m_Ptr;
	}
};

int main()
{
	ScopedPtr entity = new Entity();

	entity->Print();

	int offset = (int)&(((Vector3*)nullptr)->x);

	LOG(offset);

	std::cin.get();
}