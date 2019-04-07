#pragma once

#ifdef _WIN32 // Windows OS both 32 and 64 bit

#include <iostream>
#include <windows.h>

#define BLUE blue
#define RED red
#define GREEN green
#define YELLOW yellow
#define WHITE white
#define DEFAULT grey

inline std::ostream& blue(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
	                        FOREGROUND_BLUE | FOREGROUND_GREEN |
	                        FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& red(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_ERROR_HANDLE);
	SetConsoleTextAttribute(hStdout,
	                        FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& green(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
	                        FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& yellow(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_ERROR_HANDLE);
	SetConsoleTextAttribute(hStdout,
	                        FOREGROUND_GREEN | FOREGROUND_RED |
	                        FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& white(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
	                        FOREGROUND_RED | FOREGROUND_GREEN |
	                        FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& grey(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
	                        FOREGROUND_RED | FOREGROUND_GREEN |
	                        FOREGROUND_BLUE);
	return s;
}

struct color
{
	color(WORD attribute) : m_color(attribute)
	{
	}

	WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>&
operator<<(std::basic_ostream<_Elem, _Traits>& i, color& c)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, c.m_color);
	return i;
}

#elif __unix__

#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"
#define DEFAULT "\033[0m"

#endif // OS selection
