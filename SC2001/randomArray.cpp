#include "randomArray.h"

std::vector<int> generateArray(int n) {
	std::mt19937 rng(std::random_device{}());
	std::vector<int> vec(n);
	std::iota(begin(vec), end(vec), 0);
	std::shuffle(begin(vec), end(vec), rng);

	return vec;
};


