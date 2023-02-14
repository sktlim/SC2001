// SC2001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <matplot/matplot.h>
#include <cmath>

#include "InsertionSort.h"
#include "MergeSort.h"
#include "HybridSort.h"
#include "randomArray.h"

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    using namespace matplot;


    //std::vector<int> vec = generateArray(5000);
    std::vector<double> comparison_count;
    std::vector<int> nsize {1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000};
    int count = 0;

    for (int i = 0; i < nsize.size(); i++) {
        std::vector<int> vec = generateArray(nsize[i]);
        std::vector<int> output = MergeSort(vec, count);
        std::cout << "S/N: " << i << " Comparison Count: " << count << std::endl;
        comparison_count.push_back(count);
        count = 0;
    }

    std::cout << " " << std::endl;

    for (auto i : comparison_count) {
        std::cout << i << std::endl;
    }

    std::vector<double> x = linspace(0, 10000005);
    plot(x, comparison_count, "-o");
    show();

    /*for (auto i : time_taken) {
        std::cout << i << std::endl;
    }*/

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
