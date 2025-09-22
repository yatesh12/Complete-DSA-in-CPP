#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows for Binary Triangle: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ((i + j) % 2) << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Pattern: 0-1 Triangle:
    Example for n = 5:
    1
    0 1
    1 0 1
    0 1 0 1
    1 0 1 0 1
*/