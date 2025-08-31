import time
'''
This Python program performs an I/O-bound benchmark by writing and reading a large number of integers to and from a file.
'''
def main():

    # Start timing
    start_time = time.time()
    start_cpu_time = time.process_time()

    N = 5000000
    filename = "io_test_python.txt"

    # Write numbers to file
    with open(filename, "w") as f:
        for i in range(N):
            f.write(f"{i}\n")

    # Read numbers line by line and sum them
    total = 0
    with open(filename, "r") as f:
        for line in f:
            total += int(line.strip())

    # Print the sum
    print(f"Sum: {total}")

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