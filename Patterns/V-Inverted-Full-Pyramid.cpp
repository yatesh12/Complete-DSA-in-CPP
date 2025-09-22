#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n (positive integer): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid input.\n";
        return 1;
    }
    cout << "Inverted Full Pyramid (n = " << n << "):\n";
    for (int i = n; i >= 1; --i) {
        for (int s = 1; s <= (n - i); ++s) cout << ' ';
        for (int j = 1; j <= (2 * i - 1); ++j) cout << '*';
        cout << '\n';
    }
    return 0;
}


// Prints an Inverted Full (Centered) Pyramid (stars):
// *********
//  *******
//   *****
//    ***
//     *

