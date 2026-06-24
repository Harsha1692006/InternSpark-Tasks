#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// ==========================================
// TASK 3: FILE HANDLING & WORD FREQUENCY
// ==========================================
int main() {
    cout << "--- TASK 3: SYSTEM PROGRAMMING (FILE I/O) ---\n\n";

    string filename = "sample.txt";

    // 1. CREATE AND WRITE TO A FILE
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not create or open the file for writing!\n";
        return 1;
    }

    // Adding some sample text to the file
    outFile << "welcome to your internship welcome to coding on macbook\n";
    outFile << "learning system programming is fun and coding is awesome\n";
    outFile.close();
    cout << "[Step 1] Successfully created '" << filename << "' with sample text.\n";

    // 2. READ FROM THE FILE AND COUNT WORD FREQUENCIES
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open '" << filename << "' for reading!\n";
        return 1;
    }

    map<string, int> wordCount;
    string line, word;

    // Read the file line by line
    while (getline(inFile, line)) {
        stringstream ss(line);
        // Extract words from the line
        while (ss >> word) {
            // Clean up basic punctuation if any
            for (int i = 0; i < word.size(); i++) {
                word[i] = tolower(word[i]);
            }
            wordCount[word]++;
        }
    }
    inFile.close();
    cout << "[Step 2] Successfully read the file and processed word counts.\n\n";

    // 3. DISPLAY RESULTS
    cout << "--- WORD FREQUENCY RESULTS ---\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << " : " << pair.second << " times\n";
    }

    return 0;
}