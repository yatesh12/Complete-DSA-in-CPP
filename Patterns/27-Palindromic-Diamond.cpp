#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows (half height of diamond): ";
    cin >> n;

    // Top half
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = 1; j <= n - i; j++)
            cout << " ";

        // Descending numbers
        for (int j = i; j >= 1; j--)
            cout << j;

        // Ascending numbers
        for (int j = 2; j <= i; j++)
            cout << j;

        cout << endl;
    }

    // Bottom half
    for (int i = n - 1; i >= 1; i--) {
        // Leading spaces
        for (int j = 1; j <= n - i; j++)
            cout << " ";

        // Descending numbers
        for (int j = i; j >= 1; j--)
            cout << j;

        // Ascending numbers
        for (int j = 2; j <= i; j++)
            cout << j;

        cout << endl;
    }

    return 0;
}

// Output: n = 5
//    1
//   212
//  32123
// 4321234
//  32123
//   212
//    1