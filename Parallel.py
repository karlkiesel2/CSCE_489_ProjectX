import time
import multiprocessing

'''
This Python program performs a CPU-bound benchmark by multiplying two large matrices using parallel processing.
'''
# Same logic as the C++ application but using multiprocessing to parallelize the work
def multiplyMatricesPartial(A, B, start_row, end_row, C):
    N = len(A)
    for i in range(start_row, end_row):
        for j in range(N):
            s = 0.0
            for k in range(N):
                s += A[i][k] * B[k][j]
            C[i][j] = s

def main():
    # Start timing
    start_time = time.time()
    start_cpu_time = time.process_time()

    N = 500
    A = [[1.0] * N for _ in range(N)]
    B = [[2.0] * N for _ in range(N)]
    # create a result matrix so that each process can write to its own section
    C = [[0.0] * N for _ in range(N)]

    # Determine number of processes and rows per process
    num_processes = multiprocessing.cpu_count()
    rows_per_process = N // num_processes
    print(f"Using {num_processes} processes.")

    # Create and start processes
    processes = []
    for i in range(num_processes):
        # same logic as C++. Each process get a chunk of rows to process. The last process may will take more if there is an uneven workload
        start_row = i * rows_per_process
        end_row = (i + 1) * rows_per_process if i < num_processes - 1 else N
        # Start process
        p = multiprocessing.Process(target=multiplyMatricesPartial, args=(A, B, start_row, end_row, C))
        processes.append(p)
        p.start()

    # Wait for all processes to finish
    for p in processes:
        p.join()

    # End timing and calculate times
    end_cpu_time = time.process_time()
    end_time = time.time()

    # Convert times to milliseconds
    cpu_time = (end_cpu_time - start_cpu_time) * 1000
    exec_time = (end_time - start_time) * 1000

    # Print metrics
    print(f"CPU Time: {cpu_time:.2f} ms")
    print(f"Execution Time: {exec_time:.2f} ms")

if __name__ == "__main__":
    main()