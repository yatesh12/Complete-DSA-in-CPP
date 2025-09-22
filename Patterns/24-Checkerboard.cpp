#include <iostream>
using namespace std;

void printCheckerboard(int n) {
    for (int i = 0; i < n; i++) {
        // Shift rows alternatively
        if (i % 2 != 0) cout << " ";
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of checkerboard: ";
    cin >> n;

    printCheckerboard(n);

    return 0;
}

/*
Pattern: Checkerboard / Chessboard

Example (n = 6):
* * * * * *
 * * * * * *
* * * * * *
 * * * * * *
*/
