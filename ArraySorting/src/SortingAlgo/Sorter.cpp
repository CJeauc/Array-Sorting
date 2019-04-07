#include <SortingAlgo/Sorter.h>
#include <Debug/Log.h>

using namespace SortingAlgo;


Sorter::Sorter(const std::string& p_name,
               const SortingFunction& p_function)
	: m_name(p_name), m_sorting(p_function)
{
}

Sorter::~Sorter()
{
}

int* Sorter::Sort(int* p_array,
                  const unsigned& p_size)
{
	m_executionTime.Start();
	int*const array = m_sorting(p_array, p_size);
	m_executionTime.Stop();

	return array;
}

void Sorter::DrawExecutionTime() const
{
	Debug::Log::Out(m_name + " :\t" + std::to_string(m_executionTime.Time()) + " ms");
}
