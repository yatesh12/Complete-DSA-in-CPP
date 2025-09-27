#include <iostream>
using namespace std;

void printXPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Star on main or secondary diagonal
            if (i == j || i + j == n + 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of pattern (odd number recommended): ";
    cin >> n;
    printXPattern(n);
    return 0;
}


// x_pattern:
// Example (n = 7):
// *     *
//  *   *
//   * *
//    *
//   * *
//  *   *
// *     *
