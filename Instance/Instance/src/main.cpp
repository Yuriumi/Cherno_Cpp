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

int main()
{
	Vector2 position(0.0f, 0.0f);
	Vector2 speed(0.7f, 0.7f);
	Vector2 powerUp(1.0f, 1.0f);

	Vector2 result1 = position.Add(speed.Multiply(powerUp));
	Vector2 result2 = position + speed * powerUp;

	std::cout << result2 << std::endl;
}