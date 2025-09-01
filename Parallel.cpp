#include <iostream>
#include <vector>
#include <chrono>
#include <thread> // For multithreading
#include <mutex>  // For protecting shared resources

/*
This C++ program performs a CPU-bound benchmark by multiplying two large matrices using parallel processing.
*/

// This function multiplies a subset of rows of A with matrix B and stores the result in C
void multiplyMatricesPartial(const std::vector<std::vector<double>> &A,
                             const std::vector<std::vector<double>> &B,
                             std::vector<std::vector<double>> &C, int N,
                             int start_row, int end_row)
{
    for (int i = start_row; i < end_row; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            double sum = 0.0;
            for (int k = 0; k < N; ++k)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main()
{
    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    std::clock_t c_start = std::clock();

    // Create two N x N matrices filled with sample data and a result matrix
    int N = 500;

    // Matrix A has all values set to 1.0, matrix B has all values set to 2.0
    std::vector<std::vector<double>> A(N, std::vector<double>(N, 1.0));
    std::vector<std::vector<double>> B(N, std::vector<double>(N, 2.0));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0.0));

    // Determine the number of threads to use (e.g., number of CPU cores)
    // get number of threads by looking at how many concurrent threads can be supported by the hardware
    int num_threads = std::thread::hardware_concurrency();
    std::cout << "Using " << num_threads << " threads." << std::endl;

    // Divide the rows of A among the threads
    int rows_per_thread = N / num_threads;

    // Create a vector to store the thread objects
    std::vector<std::thread> threads;

    // Launch the threads
    for (int i = 0; i < num_threads; ++i)
    {
        // start row is based on the thread index * number of rows per thread
        int start_row = i * rows_per_thread;
        // end row is 
        // special case for the last thread to handle the remaining rows
        int end_row = (i == num_threads - 1) ? N : (i + 1) * rows_per_thread;

        // Create and start the thread
        // Each thread runs multiplyMatricesPartial on its assigned rows and stores results in C
        // Since C is preallocated and each thread writes to a unique section, no mutex is needed here
        threads.emplace_back(multiplyMatricesPartial, std::ref(A), std::ref(B), std::ref(C), N, start_row, end_row);
    }

    // Wait for all threads to complete
    for (auto &thread : threads)
    {
        thread.join();
    }

    // End timing and calculate execution time
    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate CPU and Execution time in milliseconds
    double cpu_time = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::chrono::duration<double, std::milli> exec_time = end - start;
    std::cout << "Total CPU time: " << cpu_time << " ms" << std::endl;
    std::cout << "Execution time: " << exec_time.count() << " ms" << std::endl;


    return 0;
}