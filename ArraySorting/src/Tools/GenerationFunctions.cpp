#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <Tools/GenerationFunctions.h>
#include <Debug/Log.h>

int* Generation::GenerateRandomArray(const int p_size,
                                     const bool p_random)
{
	if (p_size < 0)
	{
		Debug::Log::Error("Can't init the Array with a negative size");
		return nullptr;
	}

	srand(static_cast<unsigned>(time(nullptr)));
	int*const array = new int[p_size];

	if (p_random)
	{
		for (int i = 0; i < p_size; ++i)
			array[i] = rand();
	}
	else
	{
		for (int i = 0; i < p_size; ++i)
			array[i] = 0;
	}

	return array;
}

void Generation::DrawArray(const int* p_array,
                           const unsigned p_size)
{
	for (unsigned int i = 0; i < p_size; ++i)
		Debug::Log::Out(std::to_string(p_array[i]));
	Debug::Log::Out("");
}

void Generation::CopyArray(const int* p_sourceArray,
                           int* p_destinationArray,
                           const unsigned& p_size)
{
	if (p_sourceArray && p_destinationArray)	
		std::memcpy(p_destinationArray, p_sourceArray, p_size * sizeof(int));
}
