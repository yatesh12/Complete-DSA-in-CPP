#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows (half height of hourglass): ";
    cin >> n;

    // Top half: inverted pyramid
    for (int i = 0; i < n; i++) {
        // Leading spaces
        for (int j = 0; j < i; j++)
            cout << " ";
        // Stars
        for (int j = 0; j < 2 * (n - i) - 1; j++)
            cout << "*";
        cout << endl;
    }

    // Bottom half: regular pyramid
    for (int i = 0; i < n; i++) {
        // Leading spaces
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        // Stars
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}

// Output: n = 5
// *********
//  *******
//   *****
//    ***
//     *
//     *
//    ***
//   *****
//  *******
// *********