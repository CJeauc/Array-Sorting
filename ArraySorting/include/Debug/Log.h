#pragma once

#include <string>

#ifdef _DEBUG
#define LOG_LEVEL 4
#else
#define LOG_LEVEL 2
#endif

namespace Debug
{
	class Log
	{
	public:
		Log();
		~Log();

		static void Out(const std::string& p_string);
		static void OutLine(const std::string& p_string);

		static void Info(const std::string& p_string);
		static void InfoLine(const std::string& p_string);

		static void Error(const std::string& p_string);
		static void ErrorLine(const std::string& p_string);

		static void Success(const std::string& p_string);
		static void SuccessLine(const std::string& p_string);

		static void Warning(const std::string& p_string);
		static void WarningLine(const std::string& p_string);
	};
}
