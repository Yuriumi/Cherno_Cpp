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

struct Position
{
	int x, y, z;
};

struct RGB
{
	int a;

	union
	{
		struct
		{
			int r, g, b;
		};
		struct
		{
			Position p;
		};
	};
};

int main()
{
	union
	{
		float a;
		int b;
	};

	a = 2.0f;	// a��b����һ���ڴ�

	LOG(a << "," << b);	//int ȡ����ɸ��������ڴ�,�������ͳ���һ������.

	RGB rgb{ 1,1,1,1 };

	LOG(rgb.r << rgb.g << rgb.b << rgb.a);

	rgb.p = { 2,2,2 };

	LOG(rgb.r << rgb.g << rgb.b << rgb.a);
}