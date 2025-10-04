#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size (n): ";
    cin >> n;

    // Top half
    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= n - i; space++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    // Bottom half
    for (int i = n - 1; i >= 1; i--) {
        for (int space = 1; space <= n - i; space++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Pattern: Hollow Diamond:
    Example (n = 5):
        *    
       * *   
      *   *  
     *     * 
    *       *
     *     * 
      *   *  
       * *   
        *    

    Logic:
    - Two halves: top and bottom.
    - Each row has leading spaces and stars at symmetric positions.
    - Stars only at start and end of each row (hollow center).
*/