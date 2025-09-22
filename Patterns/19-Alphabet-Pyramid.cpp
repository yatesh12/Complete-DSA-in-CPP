#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows for Alphabet Pyramid: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Pattern: Alphabet Pyramid:
    Example for n = 5:
    A
    A B
    A B C
    A B C D
    A B C D E
*/