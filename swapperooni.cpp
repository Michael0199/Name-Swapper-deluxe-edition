#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open Names.txt for reading
    std::ifstream input("Names.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening Names.txt" << std::endl;
        return 1;
    }
    // Open Swapped.txt for writing
    std::ofstream output("Swapped.txt");
    if (!output.is_open()) {
        std::cerr << "Error opening Swapped.txt" << std::endl;
        input.close();
        return 1;
    }
    std::string line;
    // Loop until no more lines to read
    while (std::getline(input, line)) {
        // Find the position of the first space
        size_t spacePos = line.find(' ');
        if (spacePos != std::string::npos) {
            // Extract Fname (first string until space)
            std::string Fname = line.substr(0, spacePos);
            // Extract the rest after the space
            std::string rest = line.substr(spacePos + 1);
            // Print rest, add comma, then Fname, and a new line
            output << rest << ", " << Fname << std::endl;
        } else {
            // If no space, just output the line as is (though this might not happen per constraints)
            output << line << std::endl;
        }
    }
    // Close both files
    input.close();
    output.close();

   return 0;
}
