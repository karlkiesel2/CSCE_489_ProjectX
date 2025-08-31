#include <iostream>
#include <vector>
#include <string>
#include <chrono>

/*
* C++ benchmark to test receiving input from a user
*/
int main() {

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    std::clock_t c_start = std::clock();

    // vector of strings to hold lines of user input
    std::vector<std::string> lines;
    std::string input;

    std::cout << "Enter lines of text. Type 'print' to display all entries.\n";

    // Add user input to list until the user types 'print'. Then print all lines and exit.
    while (true) {
        std::getline(std::cin, input);

        if (input == "print") {
            std::cout << "Stored lines:\n";
            for (const auto& line : lines) {
                std::cout << line << std::endl;
            }
            break;
        } else {
            std::cout << "New line stored.\n";
            lines.push_back(input);
        }
    }

    // End timing and calculate execution time
    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();

    // calculate CPU and Execution time in milliseconds
    // CLOCKS_PER_SEC is the number of clock ticks per second
    double cpu_time = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::chrono::duration<double, std::milli> exec_time = end - start;
    std::cout << "CPU time: " << cpu_time << " ms" << std::endl;
    std::cout << "Execution time: " << exec_time.count() << " ms" << std::endl;


    return 0;
}