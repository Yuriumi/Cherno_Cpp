#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
	const std::string m_Name;

public:
	Entity()
		: m_Name("Unknow")
	{
		std::cout << "Created Entity" << std::endl;
	}

	void PrintName() const
	{
		std::cout << m_Name << std::endl;
	}
};

int main()
{
	{
		// std::unique_ptr<Entity> entity_a = new Entity();	������ʽת��
		std::unique_ptr<Entity> entity_b(new Entity());	// ���Ե�������
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();

		// std::unique_ptr<Entity> e = entity;	����ȫ��,ʵ���ϱ�����Ҳ����ֹ����ô��,��ֹ���ִ���

		std::shared_ptr<Entity> shareE;
		{
			std::shared_ptr<Entity> shareEntity_a(new Entity());	// ͬ�����Ƽ�
			std::shared_ptr<Entity> shareEntity = std::make_shared<Entity>();	// �Ƽ�

			shareE = shareEntity;
		}	// shareEntity�Ѿ������������ڵ�û�е�����������,��ΪshareE������,���ü�����Ϊ0
	}	// ����������,shareEҲ��������������
}