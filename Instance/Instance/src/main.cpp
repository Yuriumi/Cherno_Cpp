#include <iostream>
#include <memory>

#define LOG(x) std::cout << x << std::endl

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;

public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		/*for (unsigned int i = 0; i < m_Size + 1; i++)
		{
			m_Buffer[i] = string[i];
		}*/
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		LOG("Copy");
	}

	char& operator[](const unsigned int index)
	{
		return m_Buffer[index];
	}

	~String()
	{
		delete[] m_Buffer;
	}

	friend std::ostream& operator<< (std::ostream& stream, const String& string);
};

std::ostream& operator<< (std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

int main()
{
#pragma region Basic Cpoy
	/*int* a = new int(10);
	int* b = a;
	*b = 5;

	LOG(*a);
	LOG(*b);

	delete a;*/
#pragma endregion

	String string("cherno");
	String name = string;

	name[2] = 'a';

	LOG(string);
	LOG(name);
}