#include <Tools/Timer.h>
#include <Debug/Log.h>

using namespace Tools;

Timer::Timer()
	: m_isRunning(false)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
	if (!m_isRunning)
	{
		m_begin = steady_clock::now();
		m_isRunning = true;
	}
	else
		Debug::Log::Warning("Can't Start, the timer is already started");
}

void Timer::Stop()
{
	if (m_isRunning)
	{
		m_end = steady_clock::now();
		m_isRunning = false;
	}
	else
		Debug::Log::Warning("Can't Stop, the timer is already stopped");
}

double Timer::Time() const
{
	const duration<double> elapsedTime = duration_cast<duration<double>>((m_end - m_begin) * 1000);
	return std::move(elapsedTime.count());
}

void Timer::DrawTime() const
{
	Debug::Log::Out("Elapsed time as ms : " + std::to_string(this->Time()));
}

double Timer::TimeAsSecond() const
{
	const duration<double> elapsedTime = duration_cast<duration<double>>(m_end - m_begin);
	return std::move(elapsedTime.count());
}

void Timer::DrawTimeAsSecond() const
{
	Debug::Log::Out("Elapsed time as second : " + std::to_string(this->Time()));
}

std::ostream& Tools::operator<<(std::ostream& p_os, Timer& p_timer)
{
	p_os << p_timer.Time();
	return p_os;
}
