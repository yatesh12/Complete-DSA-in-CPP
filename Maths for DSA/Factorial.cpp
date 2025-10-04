#include <iostream>
using namespace std;

// Recursive Factorial
// Time Complexity: O(n) — one recursive call per decrement
// Space Complexity: O(n) — due to call stack
int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

// Iterative Factorial
// Time Complexity: O(n) — single loop from 2 to n
// Space Complexity: O(1) — constant space for result and loop variable
int factorialIterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Recursive Factorial: " << factorialRecursive(n) << endl;
    cout << "Iterative Factorial: " << factorialIterative(n) << endl;

    return 0;
}