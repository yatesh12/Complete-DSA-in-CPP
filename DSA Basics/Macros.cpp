#include <iostream>
using namespace std;

// Micro : A piece of code in a program that is replaced by value of micro
#define PI 3.14
 
inline int getMax(int a, int b){ // No function call overhead and extra memory usage
   int ans = (a < b) ? a : b;
}

int main() {
    int r = 5;
    // double pi = 3.14;
    double area = PI * r * r;
    cout << "Area is: " << area << endl;

    int a, b = 5;
    int ans = getMax(a, b);
  return 0;
}