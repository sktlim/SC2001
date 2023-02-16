#pragma once
#include <vector>
#include <algorithm>
#include <iterator>


std::vector<int> MergeSort(std::vector<int>& input, int& count);

std::vector<int> Merge(std::vector<int>& left, std::vector<int>& right, int& count);