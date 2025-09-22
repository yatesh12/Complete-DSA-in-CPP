#include <iostream>
using namespace std;

void printHollowRectangle(int rows, int cols) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            // Print star on boundary, space inside
            if (i == 1 || i == rows || j == 1 || j == cols)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    printHollowRectangle(rows, cols);
    return 0;
}


// hollow_rectangle:
// Example (rows = 4, cols = 6):
// ******
// *    *
// *    *
// ******