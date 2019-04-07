#include <Debug/Assertion.h>
#include <Debug/Log.h>

using namespace Debug;

Assertion::Assertion()
{
}

Assertion::~Assertion()
{
}

void Assertion::Assert(const bool& p_bool, const std::string& p_str,
                       const char* p_file, const unsigned int& p_line)
{
	if (!p_bool && LOG_LEVEL >= 4)
	{
		if (p_file)
			Log::WarningLine(std::string("   ") + ReduceFilePath(p_file) + std::string(" : ") + std::to_string(p_line));
		else
			Log::WarningLine("   In file at line : " + std::to_string(p_line));
		Log::ErrorLine('\t' + p_str);
		__debugbreak();
	}
}

void Assertion::Assert(const bool& p_bool, const std::string& p_str,
                       const char* p_file, const unsigned int& p_line,
                       const debugFunction& p_function)
{
	if (!p_bool && LOG_LEVEL >= 4)
	{
		p_function();
		if (p_file)
			Log::WarningLine(std::string("   ") + ReduceFilePath(p_file) + std::string(" : ") + std::to_string(p_line));
		else
			Log::WarningLine("   In file at line : " + std::to_string(p_line));
		Log::ErrorLine('\t' + p_str);
		__debugbreak();
	}
}

std::string Assertion::ReduceFilePath(const char* p_path)
{
	if (p_path)
	{
		std::string path(p_path);

		const size_t found = path.find("opengl_architecture");

		if (found == std::string::npos)
		{
			Log::Warning("File path doesn't match");
			return p_path;
		}
		return path.substr(found);
	}

	Log::Error("File path is NULL");
	return p_path;
}
