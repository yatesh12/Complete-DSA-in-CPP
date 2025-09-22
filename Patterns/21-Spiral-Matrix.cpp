#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // Left to Right
        for (int i = left; i <= right; ++i)
            matrix[top][i] = num++;
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; ++i)
            matrix[i][right] = num++;
        right--;

        // Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                matrix[bottom][i] = num++;
            bottom--;
        }

        // Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                matrix[i][left] = num++;
            left++;
        }
    }

    // Print matrix
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << "\t";
        cout << endl;
    }

    return 0;
}

/*
Pattern: Spiral Matrix:
Input: n = 4 → Output: 4x4 grid filled in spiral order

Sample Output:
1   2   3   4
12 13 14   5
11 16 15   6
10  9  8   7
*/