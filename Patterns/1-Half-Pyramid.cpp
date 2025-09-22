#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n (positive integer): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid input.\n";
        return 1;
    }
    cout << "Half Pyramid (n = " << n << "):\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cout << '*';
        cout << '\n';
    }
    return 0;
}

// Prints a Half Pyramid (stars):
// *
// **
// ***
// ****
// *****