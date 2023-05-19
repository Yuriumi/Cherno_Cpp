#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <vector>

#define LOG(x) std::cout<< x <<std::endl

#define WIDTH 1920
#define HEIGHT 1080

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
		: start(std::chrono::high_resolution_clock::now()) {}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();

		duration = end - start;
		float ms = duration.count() * 1000;
		LOG(ms << "ms");
	}
};

struct Entity
{
	int x;
	int y;
};


int main()
{
	Entity e{ 5,8 };
	int* position = (int*)&e;

	LOG(position[0] << "," << position[1]);

	int y = *(int*)((char*)&e + 4);
	LOG(y);
}