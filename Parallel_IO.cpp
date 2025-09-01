#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <numeric> // std::partial_sum

/*
This C++ program performs an I/O-bound benchmark by writing and reading a large number of integers to and from a file using parallel processing.
Due to the inherent sequential nature of file I/O, true parallelization is not possible,
but we can simulate some degree of concurrency by using separate threads for writing and reading.
*/

const int N = 5000000;
const std::string filename = "io_test_c_plus_plus_parallel.txt";

// Function to write numbers to a file (Thread 1)
void writeNumbersToFile() {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }
    for (int i = 0; i < N; ++i) {
        outFile << i << "\n";
    }
    outFile.close();
}

// Function to read numbers from a file and calculate the sum (Thread 2)
long readNumbersFromFile() {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return -1; // Indicate error
    }
    long sum = 0;
    int value;
    while (inFile >> value) {
        sum += value;
    }
    inFile.close();
    return sum;
}

int main() {
    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    std::clock_t c_start = std::clock();

    // Launch the threads for writing and reading
    std::thread writeThread(writeNumbersToFile);
    std::thread readThread(readNumbersFromFile);

    // Wait for the threads to complete
    writeThread.join();
    long sum = 0;
    //It only measures correctly if it waits until after the read thread has completed
    readThread.join();
    sum = readNumbersFromFile();

    // Print the sum (only if reading was successful)
    if (sum != -1) {
        std::cout << "Sum: " << sum << std::endl;
    } else {
        std::cerr << "Error calculating sum." << std::endl;
    }

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