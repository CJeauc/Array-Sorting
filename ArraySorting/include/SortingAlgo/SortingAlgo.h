#pragma once

namespace SortingAlgo
{
	int* BubbleSort(int* p_array,
	                unsigned p_size);

	int* InsertionSort(int* p_array,
	                   unsigned p_size);

	int* QuickSort(int* p_array,
	               unsigned p_size);

	int* HeapSort(int* p_array,
	              unsigned p_size);

	namespace ToolsFunctions
	{
		int Partition(int* p_array,
		              const int p_low,
		              const int p_high);

		int* RecursiveQuickSort(int* p_array,
		                        const int p_low,
		                        const int p_high);

		void Heapify(int* p_array,
		             const unsigned& p_root,
		             const unsigned& p_size);
	}
}
