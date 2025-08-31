#include <iostream>
#include <vector>
#include <chrono>
/*
This C++ program performs a CPU-bound benchmark by multiplying two large matrices.
*/
// This function multiplies two matrices A and B of size N x N
void multiplyMatrices(const std::vector<std::vector<double>> &A,
                      const std::vector<std::vector<double>> &B,
                      std::vector<std::vector<double>> &C, int N)
{

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // Compute the dot product of row i of A and column j of B
            double sum = 0.0;
            for (int k = 0; k < N; ++k)
            {
                sum += A[i][k] * B[k][j];
            }
            // store the result in C
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
    // matrix A has all values set to 1.0, matrix B has all values set to 2.0
    std::vector<std::vector<double>> A(N, std::vector<double>(N, 1.0));
    std::vector<std::vector<double>> B(N, std::vector<double>(N, 2.0));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0.0));

    // start timing, perform multiplication, and end timing
    multiplyMatrices(A, B, C, N);

    // End timing and calculate execution time
    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();

    // calculate CPU and Execution time in milliseconds
    // CLOCKS_PER_SEC is the number of clock ticks per second
    double cpu_time = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::chrono::duration<double, std::milli> exec_time = end - start;
    std::cout << "Execution time: " << exec_time.count() << " ms" << std::endl;
    std::cout << "CPU time: " << cpu_time << " ms" << std::endl;

    return 0;
}