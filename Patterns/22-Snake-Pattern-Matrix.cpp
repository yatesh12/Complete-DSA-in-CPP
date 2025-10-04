#include <iostream>
using namespace std;

// Snake Pattern Matrix: Zigzag row-wise traversal
// Odd rows → left to right; Even rows → right to left

void printSnakePattern(int n, int m) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Left to right
            for (int j = 0; j < m; j++) {
                cout << num++ << " ";
            }
        } else {
            // Right to left
            int temp = num + m - 1;
            for (int j = 0; j < m; j++) {
                cout << temp-- << " ";
                num++;
            }
        }
        cout << endl;
    }
}

int main() {
    int rows = 4, cols = 4;
    printSnakePattern(rows, cols);
    return 0;
}

// Output:
// 1 2 3 4 
// 8 7 6 5
// 9 10 11 12
// 16 15 14 13