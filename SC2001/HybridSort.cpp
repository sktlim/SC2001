#include "HybridSort.h"

std::vector<int> HybridSort(std::vector<int> input, int n, int& count) {
	if (n < 2) {
		std::cout << "n must be larger than 2" << std::endl;
		std::vector<int> empty{};
		return empty;
	}
	else if (input.size() < n) {
		std::vector<int> insort_output = InsertionSort(input, count);
		return insort_output;
	}
	else {
		auto mid = input.begin() + input.size() / 2;
		std::vector<int> output_L{};
		std::vector<int> output_R{};

		std::vector<int> newInput_L(input.begin(), mid);
		std::vector<int> newInput_R(mid, input.end());
		output_L = HybridSort(newInput_L, n, count);
		output_R = HybridSort(newInput_R, n, count);

		std::vector<int> output = Merge(output_L, output_R);
		count++;
		return output;
	}
};
