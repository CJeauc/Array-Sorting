#pragma once

namespace Generation
{
	int* GenerateRandomArray(int p_size = 100,
	                         bool p_random = true);

	void DrawArray(const int* p_array,
	               const unsigned p_size);

	void CopyArray(const int* p_sourceArray,
	               int* p_destinationArray,
	               const unsigned& p_size);
}
