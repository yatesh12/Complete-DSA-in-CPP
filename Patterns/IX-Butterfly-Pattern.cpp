#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size (n): ";
    cin >> n;

    // Top half
    for (int i = 1; i <= n; i++) {
        // Left wing
        for (int j = 1; j <= i; j++)
            cout << "*";
        // Gap
        for (int space = 1; space <= 2 * (n - i); space++)
            cout << " ";
        // Right wing
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    // Bottom half
    for (int i = n; i >= 1; i--) {
        // Left wing
        for (int j = 1; j <= i; j++)
            cout << "*";
        // Gap
        for (int space = 1; space <= 2 * (n - i); space++)
            cout << " ";
        // Right wing
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}


/*
    Pattern: Butterfly Pattern:
    Example (n = 5):
    *        *
    **      **
    ***    ***
    ****  ****
    **********
    ****  ****
    ***    ***
    **      **
    *        *

    Logic:
    - Two symmetric wings: left and right.
    - Each row has stars, then spaces, then stars.
    - Top half increases, bottom half decreases.
*/