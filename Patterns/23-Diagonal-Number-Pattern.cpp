#include <iostream>
using namespace std;

// Diagonal Number Pattern: Print row index on diagonals
// Diagonal condition: i + j == k (for each diagonal k)

void printDiagonalPattern(int n) {
    for (int k = 0; k <= 2 * (n - 1); k++) {
        for (int i = 0; i < n; i++) {
            int j = k - i;
            if (j >= 0 && j < n) {
                cout << i << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    int size = 4;
    printDiagonalPattern(size);
    return 0;
}

// Output:
// 0 1
// 0 1 2
// 0 1 2 3
//   1 2 3
//     2 3
//       3