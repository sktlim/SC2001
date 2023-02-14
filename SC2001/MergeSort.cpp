#include "MergeSort.h"

std::vector<int> MergeSort(std::vector<int> input, int& count)
{
    auto mid = input.begin() + input.size() / 2;
    std::vector<int> output_L {};
    std::vector<int> output_R {};

    if (input.end() - 1 - input.begin() <= 0)
        return input;
    else if (input.end() - 1 - input.begin() > 1) {
        std::vector<int> newInput_L(input.begin(), mid);
        std::vector<int> newInput_R(mid, input.end());
        output_L = MergeSort(newInput_L, count);
        output_R = MergeSort(newInput_R, count);
    }
    else if (input.end() - 1 - input.begin() == 1) {
        output_L.push_back(*input.begin());
        output_R.push_back(*(input.end()-1));
    }

    std::vector<int> output = Merge(output_L, output_R);
	count++;
    return output;
}

std::vector<int> Merge(std::vector<int> left, std::vector<int> right)
{
    if (left.empty())
        return right;
    if (right.empty())
        return left;

    std::vector<int> result{};

	while (!left.empty() || !right.empty()) {
		if (left.empty()) {
			result.insert(std::end(result), std::begin(right), std::end(right));
			break;
		}
		else if (right.empty()) {
			result.insert(std::end(result), std::begin(left), std::end(left));
			break;
		}
		else {
			if (left.front() < right.front()) {
				result.push_back(left.front());
				left.erase(left.begin());
			}

			else if (left.front() > right.front()) {
				result.push_back(right.front());
				right.erase(right.begin());
			}

			else {
				result.push_back(left.front());
				result.push_back(right.front());
				left.erase(left.begin());
				right.erase(right.begin());
			}
		}
	}

    return result;

}
