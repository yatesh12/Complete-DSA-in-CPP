#include <iostream>
using namespace std;

void mirroredHalfPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "  "; // two spaces for alignment
        }
        // Print stars
        for (int k = 1; k <= i; k++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5; // You can change n for different sizes
    mirroredHalfPyramid(n);
    return 0;
}

/*
Mirrored Half Pyramid Pattern: 
        *
      * *
    * * *
  * * * *
* * * * *
*/
