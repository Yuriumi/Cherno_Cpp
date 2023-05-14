#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Log
{
public:
	enum Level
	{
		LevelError = 0, LevelWarning, LevelInfo
	};

	/*const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;*/

private:
	Level m_LogLevel = LevelInfo;

public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			LOG("[ERROR]: " << message);
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			LOG("[WARNING]: " << message);
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			LOG("[INFO]: " << message);
	}
};