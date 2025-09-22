#include <iostream>
using namespace std;

// Helper function to compute nCr
int nCr(int n, int r) {
    int res = 1;
    if (r > n - r) r = n - r; // Use symmetry
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    int rows;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> rows;

    for (int i = 0; i < rows; ++i) {
        // Optional: spacing for triangle shape
        for (int space = 0; space < rows - i - 1; ++space)
            cout << " ";

        for (int j = 0; j <= i; ++j) {
            cout << nCr(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}

// Pascal's Triangle: 
// Example for rows = 5:
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1