#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Player // һ���಻�����ɷ�����ʱ,Ĭ��Ϊ˽��
{
public:
	int x, y;
	int speed;

	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Player player01;
	player01.x = 0;
	player01.y = 0;
	player01.speed = 10;

	player01.Move(1, 1);

	std::cin.get();
}