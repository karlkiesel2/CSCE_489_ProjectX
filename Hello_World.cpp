#include <iostream>
#include <chrono>
#include <ctime>
#include <sys/resource.h> // used for obtaining memory usage

/*
A simple C++ program that prints "Hello, World!" and measures execution time.
*/
int main()
{
    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    std::clock_t c_start = std::clock();

    // Print Hello, World!
    std::cout << "Hello, World!" << std::endl;

    // End timing and calculate execution time
    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();

    // calculate CPU and Execution time in milliseconds
    // CLOCKS_PER_SEC is the number of clock ticks per second
    double cpu_time = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::chrono::duration<double, std::milli> exec_time = end - start;
    std::cout << "Execution time: " << exec_time.count() << " ms" << std::endl;
    std::cout << "CPU time: " << cpu_time << " ms" << std::endl;

    // Peak memory usage in KB. This can add quite a bit of overhead, so comment out this block if you want to measure times.
    rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Peak Memory Usage: " << usage.ru_maxrss << " KB" << std::endl;

    return 0;
}