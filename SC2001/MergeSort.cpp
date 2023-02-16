#include "MergeSort.h"

std::vector<int> MergeSort(std::vector<int>& input, int& count)
{
	
	if (input.size() <= 1) {
		return input;
	}

	auto mid = input.begin() + input.size() / 2;
	std::vector<int> left(input.begin(), mid);
	std::vector<int> right(mid, input.end());

	left = MergeSort(left, count);
	right = MergeSort(right, count);

	return Merge(left, right, count);
}

std::vector<int> Merge(std::vector<int>& left, std::vector<int>& right, int& count)
{
	std::vector<int> result;
	result.reserve(left.size() + right.size());

	std::merge(left.begin(), left.end(), right.begin(), right.end(),std::back_inserter(result));
	count++;

	//result.insert(result.end(), std::make_move_iterator(left.begin()), std::make_move_iterator(left.end()));
	//result.insert(result.end(), std::make_move_iterator(right.begin()), std::make_move_iterator(right.end()));


	return result;
}
