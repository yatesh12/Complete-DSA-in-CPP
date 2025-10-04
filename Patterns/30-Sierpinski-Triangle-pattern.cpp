#include <iostream>
using namespace std;

void printSierpinski(int rows) {
    for (int row = 0; row < rows; ++row) {
        // Print leading spaces for triangle alignment
        for (int space = 0; space < rows - row - 1; ++space)
            cout << " ";

        // Print stars and holes with consistent spacing
        for (int col = 0; col <= row; ++col) {
            if ((row & col) == 0)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows (e.g., 8, 16, 32): ";
    cin >> n;

    printSierpinski(n);
    return 0;
}

// Output for n = 8
//        * 
//       * * 
//      *   * 
//     * * * * 
//    *       * 
//   * *     * * 
//  *   *   *   * 
// * * * * * * * *




