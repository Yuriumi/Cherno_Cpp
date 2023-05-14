#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;

private:
	int m_LogLevel = LogLevelInfo;

public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			LOG("[ERROR]: " << message);
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			LOG("[WARNING]: " << message);
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			LOG("[INFO]: " << message);
	}
};

int main()
{
	LOG("Hello World!");
	LOG("---------------");

	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Error("Hello!");
	log.Warn("Hello!");
	log.Info("Hello!");

	std::cin.get();
}