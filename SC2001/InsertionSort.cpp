#include "InsertionSort.h"


std::vector<int> InsertionSort(std::vector<int> input, int& count)
{
    for (auto i = input.begin(); i < input.end(); i++) {
        for (auto j = i; j > input.begin(); j--) {
            count++;
            if (*j < *(j - 1)) {
                std::iter_swap(j, j - 1);
            }
            else {
                break;
            }
        }
    }
    
    return input;
}
