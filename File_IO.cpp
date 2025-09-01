#include <iostream>
#include <fstream>
#include <chrono>
#include <sys/resource.h> // used for obtaining memory usage

/*
This C++ program performs an I/O-bound benchmark by writing and reading a large number of integers to and from a file.
*/
int main()
{

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    std::clock_t c_start = std::clock();

    // number of integers to read and write
    const int N = 5000000;
    const std::string filename = "io_test_c_plus_plus.txt";

    // Write numbers to file
    std::ofstream outFile(filename);
    for (int i = 0; i < N; ++i)
    {
        outFile << i << "\n";
    }
    outFile.close();

    // Read numbers line by line and sum them
    std::ifstream inFile(filename);
    long sum = 0;
    int value;
    while (inFile >> value)
    {
        sum += value;
    }
    inFile.close();

    // print the sum
    std::cout << "Sum: " << sum << std::endl;

    // End timing and calculate execution time
    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();

    // calculate CPU and Execution time in milliseconds
    // CLOCKS_PER_SEC is the number of clock ticks per second
    double cpu_time = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::chrono::duration<double, std::milli> exec_time = end - start;
    std::cout << "CPU time: " << cpu_time << " ms" << std::endl;
    std::cout << "Execution time: " << exec_time.count() << " ms" << std::endl;

    // Peak memory usage in KB. This can add quite a bit of overhead, so comment out this block if you want to measure times.
    rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Peak Memory Usage: " << usage.ru_maxrss << " KB" << std::endl;

    return 0;
}