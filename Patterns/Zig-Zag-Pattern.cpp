#include <iostream>
using namespace std;

void printZigZag(int n) {
    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col <= n; col++) {
            // Print star based on zig-zag mapping
            if ((row + col) % 4 == 0 || (row == 2 && col % 4 == 0))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of columns: ";
    cin >> n;
    printZigZag(n);
    return 0;
}


// zigzag_pattern:
// Example (n = 9):
//   *   *   *
//  * * * * * *
// *   *   *   *
