#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <numeric>

/*
This C++ program performs an I/O-bound benchmark by writing and reading a large number of integers to and from a file using parallel processing.
*/

const int N = 5000000;
// To avoid race conditions but still allow parallelism, use two different files for reading and writing
const std::string readFilename = "io_test_parallel_read.txt";
const std::string writeFilename = "io_test_c_plus_plus_parallel_write.txt";

std::mutex file_mutex;

// Function to write numbers to a file (Thread 1)
void writeNumbersToFile() {
    // First, set the file to empty if it already exists
    // trunc will delete the file contents if it already exists
    std::ofstream clearFile(writeFilename, std::ofstream::trunc);
    clearFile.close();
    std::ofstream outFile(writeFilename);
    for (int i = 0; i < N; ++i) {
        outFile << i << "\n";
    }
    outFile.close();
}

// Function to read numbers from a file and calculate the sum (Thread 2)
void readNumbersFromFile() {
    std::ifstream inFile(readFilename);
    long sum = 0;
    int value;
    while (inFile >> value) {
        sum += value;
    }
    inFile.close();

    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    std::clock_t c_start = std::clock();

    // Launch 2 threads. One for writing, one for reading.
    std::thread writeThread(writeNumbersToFile);
    std::thread readThread(readNumbersFromFile);

    // Wait for the threads to complete
    writeThread.join();
    readThread.join();

    // End timing and calculate execution time
    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate CPU and Execution time in milliseconds
    double cpu_time = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::chrono::duration<double, std::milli> exec_time = end - start;

    std::cout << "CPU time: " << cpu_time << " ms" << std::endl;
    std::cout << "Execution time: " << exec_time.count() << " ms" << std::endl;

    return 0;
}