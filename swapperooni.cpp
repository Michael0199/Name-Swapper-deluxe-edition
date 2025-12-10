#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // for isspace

int main() {
    std::ifstream inputFile("Names.txt");
    std::ofstream outputFile("Swapped.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Trim leading spaces
        size_t start = line.find_first_not_of(" \t");
        if (start == std::string::npos) {
            // Empty line, skip
            continue;
        }
        line = line.substr(start);

        // Check if line contains a comma
        if (line.find(',') != std::string::npos) {
            // Print as is
            outputFile << line << std::endl;
            continue;
        }

        // Parse Fname: first word until space
        size_t spacePos = line.find(' ');
        if (spacePos == std::string::npos) {
            // No space, just one word, perhaps treat as last name or something, but assume valid
            outputFile << line << std::endl;
            continue;
        }
        std::string fname = line.substr(0, spacePos);

        // Now, after space
        std::string rest = line.substr(spacePos + 1);
        size_t pos = 0;

        // Skip leading spaces in rest
        while (pos < rest.size() && std::isspace(rest[pos])) {
            pos++;
        }

        if (pos < rest.size() && rest[pos] == '"') {
            // Find closing quote
            size_t quoteEnd = rest.find('"', pos + 1);
            if (quoteEnd != std::string::npos) {
                // Skip to after quote
                pos = quoteEnd + 1;
                // Skip any following space
                while (pos < rest.size() && std::isspace(rest[pos])) {
                    pos++;
                }
            } else {
                // Malformed, but assume valid, skip to end or something
                pos = rest.size();
            }
        }

        // Now, rest from pos is the last name part
        std::string lastPart = rest.substr(pos);

        // Print lastPart, comma, fname
        outputFile << lastPart << ", " << fname << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
