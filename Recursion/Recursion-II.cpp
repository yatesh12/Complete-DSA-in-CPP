#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibonacciSeries(int n) {
    for (int i = 0; i <= n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    cout << "Fibonacci Series up to " << n << " terms: ";
    fibonacciSeries(n);

    return 0;
}