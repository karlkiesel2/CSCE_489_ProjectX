import time
'''
This Python program performs a CPU-bound benchmark by multiplying two large matrices.
'''

# This function multiplies two matrices A and B of size N x N
def multiplyMatrtices(A, B):
    N = len(A)
    # C is a 2D list initialized to zero
    C = [[0.0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            # Compute the dot product of row i of A and column j of B
            s = 0.0
            for k in range(N):
                s += A[i][k] * B[k][j]
            # store the result in C
            C[i][j] = s
    return C

def main():

    # Start timing
    start_time = time.time()
    start_cpu_time = time.process_time()

    N = 500
    A = [[1.0]*N for _ in range(N)]
    B = [[2.0]*N for _ in range(N)]

    C = multiplyMatrtices(A, B)

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