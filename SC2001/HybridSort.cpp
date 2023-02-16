#include "HybridSort.h"

std::vector<int> HybridSort(std::vector<int>& input, int n, int& count) {
	if (n <= 1) { // n must be greater than 1 for insertion sort to trigger
		std::cout << "n must be larger than 1" << std::endl;
		std::vector<int> empty{};
		return empty;
	}

	// where n is threshold value, or 'S' in the example class document
	else if (input.size() < n) { 
		std::vector<int> insort_output = InsertionSort(input, count);
		return insort_output;
	}
	
	// recursive call of Hybrid Sort
	else { 
		auto mid = input.begin() + input.size() / 2;
		std::vector<int> left(input.begin(), mid);
		std::vector<int> right(mid, input.end());


		left = HybridSort(left, n, count);
		right = HybridSort(right, n, count);

		std::vector<int> output;

		count++;
		return Merge(left, right, count);;
	}
};
