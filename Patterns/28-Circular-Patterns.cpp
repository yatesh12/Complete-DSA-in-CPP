#include <iostream>
#include <cmath>
using namespace std;

// Function to print an approximate circle pattern
void printCircle(int radius) {
    int diameter = 2 * radius;

    // Loop through each point in the grid
    for (int y = radius; y >= -radius; y--) {
        for (int x = -radius; x <= radius; x++) {
            // Check if the point lies within the circle using the equation x^2 + y^2 <= r^2
            if (x * x + y * y <= radius * radius)
                cout << "*";  // Inside the circle
            else
                cout << " ";  // Outside the circle
        }
        cout << endl;
    }
}

int main() {
    int radius;
    cout << "Enter radius of the circle: ";
    cin >> radius;

    printCircle(radius);
    return 0;
}

// Output: Enter radius of the circle: 5
//      *     
//   *******
//  ********* 
//  ********* 
//  *********
// ***********
//  *********
//  *********
//  *********
//   *******
//      *