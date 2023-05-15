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
	using namespace std::string_literals;

	const char* name_a = "cherno";

	// name_a[2] = 'a';	ERROR

	char name_b[] = "cherno";

	name_b[2] = 'a';

	LOG(name_b);

	std::string hello = "Hello "s + "World!";

	LOG(hello);
	
	std::cin.get();
}