#include <vector>
#include <Tools/GenerationFunctions.h>
#include <SortingAlgo/Sorter.h>
#include <SortingAlgo/SortingAlgo.h>
#include <Debug/Log.h>
#include <iostream>

int main()
{
	unsigned int numberOfTest = 6;
	bool isRandomArray = true;
	Debug::Log::Info("Enter the size of the array to sort (10^n enter n): ");
	std::cin >> numberOfTest;
	Debug::Log::Info("Should the array have random value ? : (0 : no / 1 : yes) ");
	std::cin >> isRandomArray;

	int* myTab = nullptr;
	int* tab = nullptr;

	std::vector<SortingAlgo::Sorter> sorters;
	sorters.emplace_back("BubbleSort", SortingAlgo::BubbleSort);
	sorters.emplace_back("InsertSort", SortingAlgo::InsertionSort);
	sorters.emplace_back("QuickSort", SortingAlgo::QuickSort);
	sorters.emplace_back("HeapSort", SortingAlgo::HeapSort);

	for (unsigned int size = 10; size <= pow(10, numberOfTest); size *= 10)
	{
		myTab = Generation::GenerateRandomArray(size, isRandomArray);

		Debug::Log::InfoLine("\n|--- Sorting with a size of " + std::to_string(size) + " elements ---|\n\n");
		
		for (SortingAlgo::Sorter sorterIterator : sorters)
		{
			tab = new int[size];
			Generation::CopyArray(myTab, tab, size);
			sorterIterator.Sort(tab, size);
			sorterIterator.DrawExecutionTime();
			delete[] tab;
		}

		delete[] myTab;
	}

	system("pause");

	return 0;
}
