#include <iostream>
#include <chrono>
#include <thread>
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


int main()
{
	std::vector<int> numbers = { 3,5,4,1,2 };

	std::sort(numbers.begin(), numbers.end(), [](int a, int b)
		{
			if (a == 2)
				return false;
			if (b == 2)
				return true;

			return a < b;
		});

	for (int value : numbers)
		LOG(value);
}