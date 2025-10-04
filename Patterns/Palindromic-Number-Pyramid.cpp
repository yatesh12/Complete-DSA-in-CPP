#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        // Print leading spaces
        for (int space = 1; space <= n - i; ++space) {
            cout << " ";
        }

        // Print increasing numbers
        for (int num = 1; num <= i; ++num) {
            cout << num;
        }

        // Print decreasing numbers
        for (int num = i - 1; num >= 1; --num) {
            cout << num;
        }

        cout << endl;
    }

    return 0;
}

// Palindromic Number Pyramid
// Sample for n = 5:
//     1
//    121
//   12321
//  1234321
// 123454321
