#include <iostream>
using namespace std;

void printSpaces(int count) {
    for (int i = 0; i < count; i++) cout << ' ';
}

void printStars(int count) {
    for (int i = 0; i < count; i++) cout << '*';
}

void printHollowPyramid(int H) {
    if (H <= 0) return;

    for (int i = 1; i <= H; i++) {
        printSpaces(H - i);

        if (i == 1) {
            cout << "*";
        } else if (i < H) {
            cout << "*";
            printSpaces(2 * i - 3);
            cout << "*";
        } else {
            printStars(2 * H - 1);
        }

        cout << endl;
    }

    cout << flush; // Ensures output is flushed to console
}

int main() {
    int H;
    cout << "Enter height of pyramid: ";
    if (!(cin >> H)) H = 5;

    printHollowPyramid(H);
    return 0;
}


// hollow pyramid:
// Example (H = 5):
//     *
//    * *
//   *   *
//  *     *
// *********
