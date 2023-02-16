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

    //-------------------------------------------------------------------------------------------------------------------------
    // Part ci)
    //std::vector<double> comparison_count;
    //std::vector<int> nsize {1000, 5000, 10000, 50000, 100000, 500000, 1'000'000, 5'000'000, 10'000'000}; //varying n size
    //int count = 0;

    //for (int i = 0; i < nsize.size() ; i++) {
    //    std::vector<int> vec = generateArray(nsize[i]);
    //    std::vector<int> output = HybridSort(vec, 13, count);
    ////    std::cout << "S/N: " << i << " Comparison Count: " << count << std::endl;
    //    std::cout << count << std::endl;
    //    comparison_count.push_back(count);
    //    count = 0;
    //    output.clear();
    //}

    //std::vector<double> x = linspace(0, 10);
    //plot(x, comparison_count, "-o");
    //show();

    //-------------------------------------------------------------------------------------------------------------------------
    // Part cii)
    std::vector<double> comparison_count;
    std::vector<double> time_count;

    std::vector<int> vec = generateArray(10000000);
    int count = 0;

    for (int i = 2; i < 23; i++) {
        auto t1 = high_resolution_clock::now();
        std::vector<int> output = HybridSort(vec, i, count);
        auto t2 = high_resolution_clock::now();

        duration<double, std::milli> hybrid_double = t2 - t1;

        std::cout << count << std::endl;
        time_count.push_back(hybrid_double.count());
        count = 0;
    }

    for (auto i : time_count) {
        std::cout << i << std::endl;
    }

    //std::vector<double> x = linspace(0, 1000);
    //plot(x, comparison_count, "-o");
    //show();

    //-------------------------------------------------------------------------------------------------------------------------
    // Part ciii)



    //-------------------------------------------------------------------------------------------------------------------------
    // Part d)
    //std::vector<double> comparison_count_merge;
    //std::vector<double> comparison_count_hybrid;
    //int count_merge = 0;
    //int count_hybrid = 0;

    //std::vector<int> vec = generateArray(10'000'000);

    //auto t1 = high_resolution_clock::now();
    //std::vector<int> output_1 = HybridSort(vec, 4, count_hybrid);
    //auto t2 = high_resolution_clock::now();

    //auto t3 = high_resolution_clock::now();
    //std::vector<int> output_2 = MergeSort(vec, count_merge);
    //auto t4 = high_resolution_clock::now();

    //duration<double, std::milli> hybrid_double = t2 - t1;
    //duration<double, std::milli> merge_double = t4 - t3;

    //std::cout << "MergeSort - Comparison Count: " << count_merge << std::endl;
    //std::cout << "HybridSort - Comparison Count: " << count_hybrid << std::endl;

    //std::cout << "MergeSort - Runtime: " << merge_double.count() << "ms" << std::endl;
    //std::cout << "HybridSort - Runtime: " << hybrid_double.count() << "ms" << std::endl;

    //-------------------------------------------------------------------------------------------------------------------------

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
