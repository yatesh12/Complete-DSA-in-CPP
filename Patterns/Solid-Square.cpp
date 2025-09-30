#include <iostream>
using namespace std;

void printSolidRectangle(int rows, int cols) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    printSolidRectangle(rows, cols);
    return 0;
}


// solid_rectangle:
// Example (rows = 4, cols = 6):
// ******
// ******
// ******
// ******

