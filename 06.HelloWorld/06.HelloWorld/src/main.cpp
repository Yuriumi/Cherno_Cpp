#include <iostream>
#include <chrono>
#include <thread>

#define LOG(x) std::cout<< x <<std::endl

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

void Function()
{
	Timer timer;

	for (unsigned int i = 0; i < 100; i++)
	{
		std::cout << i << '\n';	// \n的性能要比std::endl高很多
	}
}

int main()
{
	using namespace std::literals::chrono_literals;	// 使用1s中的's'

	// 获取当前时间(高精度)
	std::chrono::time_point<std::chrono::steady_clock> start_a = std::chrono::high_resolution_clock::now();
	// 类型很长的时候我们可以使用auto关键字
	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(1s);	// 计时时间会大于1s,因为计时本身会有性能开销
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	LOG(duration.count() << 's');

	Function();

	std::cin.get();
}