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

class Example
{
private:
	int x, y;

public:
	Example(int x, int y)
	{
		/*x = x
		  y = y	我们实际上并没有完成初始化操作,只是将其自身的值重新赋值给自身,
		  相当于啥也没干*/

		this->x = x;
		this->y = y;
	}

	int GetX() const
	{
		const Example* e = this;
		return e->x;
	}

	void PrintExample()
	{
		const Example& e = *this;
		std::cout << e.GetX() << std::endl;
	}
};

struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	bool operator==(const Vector2& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other)
	{
		return !(*this == other);
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ',' << other.y;
	return stream;
}

int* CreatIntArray()
{
	int array[50];
	array[0] = 10;
	return array;
}

class ScopePtr
{
private :
	Example* m_Ptr;

public:
	ScopePtr(Example* ptr)
		: m_Ptr(ptr){}

	~ScopePtr()
	{
		delete m_Ptr;
	}
};

int main()
{
	int* a = CreatIntArray();

	{
		ScopePtr example = new Example(1, 1);
	}
}