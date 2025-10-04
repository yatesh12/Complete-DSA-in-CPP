#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Function to print a sinusoidal wave pattern
void printWave(string text, int height = 5) {
    int len = text.length();
    vector<string> rows(height, string(len, ' '));

    // Map each character to a row based on sine wave
    for (int i = 0; i < len; i++) {
        // Calculate sine value and map to row index
        double angle = (double)i * 2 * M_PI / len;
        int row = (int)((sin(angle) + 1) * (height - 1) / 2);
        rows[row][i] = text[i];
    }

    // Print the wave row by row
    for (const string& row : rows)
        cout << row << endl;
}

int main() {
    string text;
    cout << "Enter text to wave: ";
    cin >> text;

    printWave(text);
    return 0;
}

// Output: HELLOCPP
//      L     P
//     L   C  
//    E   P   
//   H   O    


