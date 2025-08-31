import time
'''
Python benchmark to test receiving input from a user
'''
def main():

    # Start timing
    start_time = time.time()
    start_cpu_time = time.process_time()

    # Hold lines entered in by user
    lines = []
    print("Enter lines of text. Type 'print' to display all entries.")

    # Add user input to list until the user types 'print'. Then print all lines and exit.
    while True:
        user_input = input()
        if user_input == "print":
            print("Stored lines:")
            for line in lines:
                print(line)
            break
        else:
            print("New line stored.")
            lines.append(user_input)

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