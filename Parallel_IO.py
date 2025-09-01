import time
import threading

'''
This Python program performs an I/O-bound benchmark by writing and reading a large number of integers to and from a file using threading.
Due to the GIL and inherent sequential nature of file I/O, true parallelization is not possible.
'''

def write_numbers_to_file(filename, N):
    with open(filename, "w") as f:
        for i in range(N):
            f.write(f"{i}\n")

def read_numbers_from_file(filename):
    total = 0
    try:
        with open(filename, "r") as f:
            for line in f:
                total += int(line.strip())
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return None  # Indicate error
    return total

def main():
    # Start timing
    start_time = time.time()
    start_cpu_time = time.process_time()

    N = 5000000
    filename = "io_test_python_parallel.txt"

    # Launch the threads
    write_thread = threading.Thread(target=write_numbers_to_file, args=(filename, N))
    read_thread = threading.Thread(target=read_numbers_from_file, args=(filename,))

    write_thread.start()
    read_thread.start() #The IO can only be tested one at a time, so don't await the read function

    write_thread.join()
    #Important: the read thread must only be read after the write thread has completed writing.
    read_thread.join()

    #Check for errors, since this multithreaded function is highly prone to errors.
    result = read_numbers_from_file(filename)

    # End timing and calculate times
    end_cpu_time = time.process_time()
    end_time = time.time()

    # Convert times to milliseconds
    cpu_time = (end_cpu_time - start_cpu_time) * 1000
    exec_time = (end_time - start_time) * 1000

    # Print metrics
    print(f"CPU Time: {cpu_time:.2f} ms")
    print(f"Execution Time: {exec_time:.2f} ms")

    # Print the sum
    if result is not None:
        print(f"Sum: {result}")
    else:
        print("Error: Could not calculate the sum. May have failed to write to file.")
if __name__ == "__main__":
    main()