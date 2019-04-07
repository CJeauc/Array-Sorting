#pragma once
#include <string>

#ifdef _DEBUG
#define ASSERT(x) Debug::Assertion::Assert(x, #x , __FILE__, __LINE__ )
#define ASSERTF(x, y) Debug::Assertion::Assert(x, #x , __FILE__, __LINE__, y )
#else
#define ASSERT(x) Core::Debug::Assertion::Assert(true, "", "", 0)
#define ASSERTF(x, y) Core::Debug::Assertion::Assert(true, "" , "", 0, nullptr )
#endif

typedef void (*debugFunction)(void);

namespace Debug
{
	class Assertion
	{
	public:
		Assertion();
		~Assertion();

		static void Assert(const bool& p_bool, const std::string& p_str,
		                   const char* p_file, const unsigned int& p_line);
		static void Assert(const bool& p_bool, const std::string& p_str,
		                   const char* p_file, const unsigned int& p_line,
		                   const debugFunction& p_function);
		static std::string ReduceFilePath(const char* p_path);
	};
}
