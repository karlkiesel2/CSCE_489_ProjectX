import time
import resource # used for obtaining memory usage


# Start timing
start_time = time.time()
start_cpu_time = time.process_time()

# Print Hello, World!
print("Hello, World!")

# End timing and calculate times
end_cpu_time = time.process_time()
end_time = time.time()

# Convert times to milliseconds
cpu_time = (end_cpu_time - start_cpu_time) * 1000
exec_time = (end_time - start_time) * 1000

# Print metrics
print(f"CPU Time: {cpu_time:.2f} ms")
print(f"Execution Time: {exec_time:.2f} ms")

# Get peak memory usage. Comment out this block to measure times without the added overhead.
peak_memory = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
print(f"Peak Memory Usage: {peak_memory} KB")