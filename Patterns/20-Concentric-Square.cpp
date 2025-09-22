#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int size = 2 * n - 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Replace initializer list with nested min calls
            int minDist = min(min(i, j), min(size - 1 - i, size - 1 - j));
            cout << n - minDist << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Pattern: Concentric Number Square (layers)
Input: n = 4 → Output: 7x7 grid

Sample Output:
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
*/