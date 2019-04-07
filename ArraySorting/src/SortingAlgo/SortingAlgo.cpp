#include <algorithm>
#include <SortingAlgo/SortingAlgo.h>

int* SortingAlgo::BubbleSort(int* p_array,
                             unsigned p_size)
{
	unsigned newSize = 0;
	while (p_size)
	{
		newSize = 0;

		for (unsigned i = 1; i < p_size; ++i)
		{
			if (p_array[i] < p_array[i - 1])
			{
				std::swap(p_array[i], p_array[i - 1]);
				newSize = i;
			}
		}
		p_size = newSize;
	}

	return p_array;
}

int* SortingAlgo::InsertionSort(int* p_array, const unsigned p_size)
{
	int key;
	int j;
	for (unsigned i = 1; i < p_size; i++)
	{
		key = p_array[i];
		j = i - 1;

		while (j >= 0 && p_array[j] > key)
		{
			p_array[j + 1] = p_array[j];
			--j;
		}
		p_array[j + 1] = key;
	}

	return p_array;
}

int* SortingAlgo::QuickSort(int* p_array, unsigned p_size)
{
	return ToolsFunctions::RecursiveQuickSort(p_array, 0, p_size - 1);
}

int SortingAlgo::ToolsFunctions::Partition(int* p_array,
                                           const int p_low,
                                           const int p_high)
{
	int pivot = p_array[p_low];
	int i = (p_low - 1);
	int j = (p_high + 1);

	while (true)
	{
		do ++i;
		while (p_array[i] < pivot);

		do --j;
		while (p_array[j] > pivot);

		if (i >= j)
			return j;

		std::swap(p_array[i], p_array[j]);
	}

}

int* SortingAlgo::ToolsFunctions::RecursiveQuickSort(int* p_array,
                                                     const int p_low,
                                                     const int p_high)
{
	if (p_low < p_high)
	{
		const int pi = Partition(p_array, p_low, p_high);

		RecursiveQuickSort(p_array, p_low, pi);
		RecursiveQuickSort(p_array, pi + 1, p_high);
	}

	return p_array;
}

int* SortingAlgo::HeapSort(int* p_array, unsigned p_size)
{
	// Build heap (rearrange array)
	for (int i = (p_size / 2 - 1); i >= 0; --i)
		ToolsFunctions::Heapify(p_array, i, p_size);

	// One by one extract an element from heap
	for (int i = (p_size - 1); i >= 0; i--)
	{
		// Move current root to end
		std::swap(p_array[0], p_array[i]);

		// call max heapify on the reduced heap
		ToolsFunctions::Heapify(p_array, 0, i);
	}

	return p_array;
}

void SortingAlgo::ToolsFunctions::Heapify(int* p_array,
                                          const unsigned& p_root,
                                          const unsigned& p_size)
{
	int largest = p_root; // Initialize largest as root
	const unsigned left = 2 * p_root + 1; // left = 2*i + 1
	const unsigned right = 2 * p_root + 2; // right = 2*i + 2

	// If left child is larger than root
	if (left < p_size && p_array[left] > p_array[largest])
		largest = left;

	// If right child is larger than largest so far
	if (right < p_size && p_array[right] > p_array[largest])
		largest = right;

	// If largest is not root
	if (largest != p_root)
	{
		std::swap(p_array[p_root], p_array[largest]);

		// Recursively heapify the affected sub-tree
		Heapify(p_array, largest, p_size);
	}
}
