#pragma once
#include <Tools/Timer.h>

namespace SortingAlgo
{
	typedef int* (*SortingFunction)(int*, unsigned);

	class Sorter
	{
	private:
		std::string m_name;
		Tools::Timer m_executionTime;
		SortingFunction m_sorting;

	public:
		Sorter(const std::string& p_name,
		       const SortingFunction& p_function);
		~Sorter();

		int* Sort(int* p_array,
		          const unsigned& p_size);

		void DrawExecutionTime() const;
	};
}
