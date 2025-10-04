#include <iostream>
#include <vector>
using namespace std;


// Function to return list containing first n Fibonacci numbers.
vector<int> fibonacciNumbers(int n) {
    vector<int> fib(n); // Preallocate space for n elements

    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;

    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}


int main() {
    int n;
    cout << "Enter the number of Fibonacci terms: ";
    cin >> n;

    vector<int> result = fibonacciNumbers(n);

    cout << "Fibonacci sequence up to " << n << " terms:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Time: O(N)
// Space: O(N)