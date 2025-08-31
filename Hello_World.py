import time


# Start timing
start_time = time.time()
start_cpu_time = time.process_time()

# Print Hello, World!
print("Hello, World!")

# End timing and calculate execution time
end_cpu_time = time.process_time()
end_time = time.time()

# Convert times to milliseconds
cpu_time = (end_cpu_time - start_cpu_time) * 1000
exec_time = (end_time - start_time) * 1000

# Print metrics
print(f"CPU Time: {cpu_time:.2f} ms")
print(f"Execution Time: {exec_time:.2f} ms")