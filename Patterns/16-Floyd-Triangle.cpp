#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows for Floyd's Triangle: ";
    cin >> rows;

    int num = 1; // Running counter
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << num++ << " ";
        }
        cout << endl;
    }

    return 0;
}

// Floyd's Triangle:
// Example for rows = 5:
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15