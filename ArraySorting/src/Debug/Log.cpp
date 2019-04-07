#include <iostream>
#include <Debug/ConsoleColor.h>
#include <Debug/Log.h>

using namespace Debug;

Log::Log()
{
}

Log::~Log()
{
}

void Log::Out(const std::string& p_string)
{
	if (LOG_LEVEL >= 1)
	{
		std::cout << WHITE << p_string << DEFAULT << '\n';
	}
}

void Log::OutLine(const std::string& p_string)
{
	if (LOG_LEVEL >= 1)
		std::cout << WHITE << p_string << DEFAULT;
}

void Log::Info(const std::string& p_string)
{
	if (LOG_LEVEL >= 1)
	{
		std::clog << BLUE << "Info\t:: " << p_string << DEFAULT << '\n';
	}
}

void Log::InfoLine(const std::string& p_string)
{
	if (LOG_LEVEL >= 1)
		std::clog << BLUE << p_string << DEFAULT;
}

void Log::Error(const std::string& p_string)
{
	if (LOG_LEVEL >= 2)
	{
		std::cerr << RED << "Error\t:: " << p_string << DEFAULT << '\n';
	}
}

void Log::ErrorLine(const std::string& p_string)
{
	if (LOG_LEVEL >= 2)
		std::cerr << RED << p_string << DEFAULT;
}

void Log::Success(const std::string& p_string)
{
	if (LOG_LEVEL >= 2)
	{
		std::clog << GREEN << "Success\t:: " << p_string << DEFAULT << '\n';
	}
}

void Log::SuccessLine(const std::string& p_string)
{
	if (LOG_LEVEL >= 2)
		std::clog << GREEN << p_string << DEFAULT;
}

void Log::Warning(const std::string& p_string)
{
	if (LOG_LEVEL >= 3)
	{
		std::cerr << YELLOW << "Warning\t:: " << p_string << DEFAULT << '\n';
	}
}

void Log::WarningLine(const std::string& p_string)
{
	if (LOG_LEVEL >= 3)
		std::cerr << YELLOW << p_string << DEFAULT;
}
