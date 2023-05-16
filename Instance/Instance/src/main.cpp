#include <iostream>
#include <memory>
#include <vector>

#define LOG(x) std::cout << x << std::endl

struct Vector3
{
	int x, y, z;
};

std::ostream& operator<< (std::ostream& stream, const Vector3& veretx)
{
	stream << veretx.x << ',' << veretx.y << ',' << veretx.z;
	return stream;
}

void PrintArray(const std::vector<Vector3>& vertices)
{
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		LOG(vertices[i]);
	}
}

int main()
{
	std::vector<Vector3> vertices;

	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });
	vertices.push_back({ 7,8,9 });

	PrintArray(vertices);

	vertices.erase(vertices.begin() + 1);

	for (Vector3& v : vertices)
	{
		LOG(v);
	}

	vertices.clear();

	std::cin.get();
}