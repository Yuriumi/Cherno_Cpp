#include <iostream>
#include <chrono>
#include <thread>

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

struct RGB
{
	unsigned int R;
	unsigned int G;
	unsigned int B;

	RGB() {}

	RGB(unsigned int r, unsigned int g, unsigned int b) : R(r), G(g), B(b) {}
};

void Draw_1d()
{
	Timer timer;

	RGB* rgb = new RGB[WIDTH * HEIGHT];

	for (unsigned int i = 0; i < WIDTH; i++)
	{
		for (unsigned int j = 0; j < HEIGHT; j++)
		{
			rgb[i * HEIGHT + j] = { 1,1,1 };
		}
	}

	delete[] rgb;
}

void Draw_2d()
{
	Timer timer;

	RGB** rgb = new RGB * [WIDTH];

	for (unsigned int x = 0; x < WIDTH; x++)
	{
		rgb[x] = new RGB[HEIGHT];
		for (unsigned int y = 0; y < HEIGHT; y++)
			rgb[x][y] = { 1,1,1 };
	}

	for (unsigned int x = 0; x < WIDTH; x++)
		delete[] rgb[x];

	delete[] rgb;
}

int main()
{
	{
		Timer timer;

		int* a1d = new int[5];	// 一维数组,连续的内存块最好的存储方式是存储内存块开头的内存地址.

		int** a2d = new int* [5];
		for (unsigned int i = 0; i < 5; i++)
			a2d[i] = new int[5];

		for (unsigned int x = 0; x < 5; x++)
		{
			for (unsigned int y = 0; y < 5; y++)
				a2d[x][y] = 2;
		}

		for (unsigned int i = 0; i < 5; i++)
			delete[] a2d[i];	// 释放真正的数组

		delete[] a2d;	// 释放数组指针,如果直接释放,真正存储数据的数组我们就无法访问到了,会造成内存的泄露.

		// 优化为一维数组
		int* a2d_1 = new int[4 * 5];

		for (unsigned int x = 0; x < 4; x++)
		{
			for (unsigned int y = 0; y < 5; y++)
			{
				a2d_1[x * 5 + y] = 2;
			}
		}
	}

	Draw_1d();
	Draw_2d();
}