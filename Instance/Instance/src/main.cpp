#include <iostream>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{

	}

	Vertex(const Vertex& other)
		: x(other.x),y(other.y),z(other.z)
	{
		LOG("Copyed!");
	}
};

int main()
{
	std::vector<Vertex> vertices;
	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(4, 5, 6);

	std::cin.get();
}