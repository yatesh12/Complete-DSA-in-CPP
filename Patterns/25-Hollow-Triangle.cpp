#include <iostream>
using namespace std;

void printHollowTriangle(int n) {
    for (int i = 0; i < n; i++) {
        // Leading spaces
        for (int s = 0; s < n - i - 1; s++)
            cout << " ";

        // Print stars/space
        for (int j = 0; j <= i; j++) {
            if (i == n - 1) {
                // Base row: all '*'
                cout << "* ";
            } else {
                if (j == 0 || j == i)
                    cout << "* ";
                else
                    cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter height of triangle: ";
    cin >> n;

    printHollowTriangle(n);

    return 0;
}

/*
Pattern: Hollow Triangle with Base
Example (n = 5):
    *
   * *
  *   *
 *     *
*********
*/
