#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream in("Names.txt");
    ofstream out("Swapped.txt");
    string line;
    
    while (getline(in, line)) {
        size_t space_pos = line.find(' ');
        if (space_pos == string::npos) continue; // Skip lines without space
        
        string Fname = line.substr(0, space_pos);
        string S = line.substr(space_pos + 1);
        
        // Check for quotes in S
        size_t quote1 = S.find('"');
        if (quote1 != string::npos) {
            size_t quote2 = S.find('"', quote1 + 1);
            if (quote2 != string::npos) {
                // Ignore the string value between the quotes (including quotes)
                S.erase(quote1, quote2 - quote1 + 1);
            }
        }
        
        // Print the rest of the line (S) and add a comma, then Fname and a new line
        out << S << "," << Fname << endl;
    }
    
    in.close();
    out.close();
    return 0;
}