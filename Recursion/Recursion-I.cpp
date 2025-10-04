#include <iostream>
using namespace std;

int factorial(int n) {
    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return -1; // Sentinel value to indicate invalid input
    }
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    int ans = factorial(n);
    if (ans != -1)
        cout << "Factorial: " << ans << endl;

    return 0;
}