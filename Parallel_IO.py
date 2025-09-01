import time
import threading

'''
This Python program performs a parallel I/O-bound benchmark by writing and reading a large number of integers to and from a file using multiple threads.
'''

# same logic as in the single-threaded version, but split into a separate funtion so that each thread can call it
def write_numbers_to_file(filename, N):
    with open(filename, "w") as f:
        for i in range(N):
            f.write(f"{i}\n")

# same logic as in the single-threaded version, but split into a separate funtion so that each thread can call it
def read_numbers_from_file(filename):
    total = 0
    with open(filename, "r") as f:
        for line in f:
            total += int(line.strip())
        print(f"Sum: {total}")

def main():
    # Start timing
    start_time = time.time()
    start_cpu_time = time.process_time()

    N = 5000000
    # To avoid race conditions but still allow parallelism, use two different files for reading and writing
    readFilename = "io_test_parallel_read.txt"
    writeFilename = "io_test_python_parallel_write.txt"

    # Launch the threads
    write_thread = threading.Thread(target=write_numbers_to_file, args=(writeFilename, N))
    read_thread = threading.Thread(target=read_numbers_from_file, args=(readFilename,))

    # Use two threads here. One for reading and one for writing
    write_thread.start()
    read_thread.start()

    # Wait for the threads to finish.
    write_thread.join()
    
    read_thread.join()


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