#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

class Example
{
private:
	std::string e_Name;

public:
	Example()
	{
		LOG("Creat a example" << e_Name);
	}
	
	Example(std::string name)
		: e_Name(name)
	{
		LOG("Creat a example " << e_Name);
	}
};

class Entity
{
private:
	std::string m_Name;
	Example e;

public:
	Entity()
		: m_Name("Unknow")
	{
		e = Example();
	}

	Entity(std::string name)
		: m_Name(name),e(Example("one"))
	{

	}

	void PrintName()
	{
		LOG(m_Name);
	}
};

int main()
{
	int player_Level = 2;
	std::string game_Rank;

	if (player_Level > 1)
		game_Rank = "Master";
	else
		game_Rank = "Beginner";

	game_Rank = player_Level > 1 ? "Master" : "Beginner";

	std::cin.get();
}