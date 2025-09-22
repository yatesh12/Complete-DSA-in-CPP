#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}

// Numeric Left Pyramid (1..i):
// Sample for n = 5:
// 1
// 12
// 123
// 1234
// 12345