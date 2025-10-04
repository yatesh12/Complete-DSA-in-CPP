#include <iostream>
using namespace std;

void printSpaces(int count) {
    while (count-- > 0) cout << ' ';
}

void printStars(int count) {
    while (count-- > 0) cout << '*';
}

void printSolidDiamond(int N) {
    if (N <= 0) {
        cout << "Height must be >= 1\n";
        return;
    }

    // Top half (including middle row)
    for (int i = 1; i <= N; ++i) {
        printSpaces(N - i);
        printStars(2 * i - 1);
        cout << '\n';
    }

    // Bottom half
    for (int i = N - 1; i >= 1; --i) {
        printSpaces(N - i);
        printStars(2 * i - 1);
        cout << '\n';
    }
}

int main() {
    int N;
    cout << "Enter half-height of diamond (>=1): ";
    if (!(cin >> N) || N < 1) {
        cout << "Invalid input. Using default value N = 5.\n";
        N = 5;
    }

    printSolidDiamond(N);
    return 0;
}


// solid diamond:
// Example (N = 5):
//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *