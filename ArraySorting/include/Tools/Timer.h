#pragma once

#include <chrono>
#include <ostream>

using namespace std::chrono;

namespace Tools
{
	class Timer
	{
	private:
		steady_clock::time_point m_begin;
		steady_clock::time_point m_end;
		bool m_isRunning;

	public:
		Timer();
		~Timer();

		void Start();
		void Stop();

		double Time() const; //return elapsed time as ms
		void DrawTime() const; //display elapsed time as ms

		double TimeAsSecond() const; //return elapsed time as second
		void DrawTimeAsSecond() const; //display elapsed time as second
	};

	std::ostream& operator<<(std::ostream& p_os, Timer& p_timer);
}
