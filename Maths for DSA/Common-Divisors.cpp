#include <iostream>
#include <cmath>
#include <algorithm> // for __gcd
using namespace std;

long long int commDiv(long long int a, long long int b) {
    long long g = __gcd(a, b); // Efficient GCD
    long long cnt = 0;
    for (long long i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            cnt += (i * i == g) ? 1 : 2; // Count both i and g/i unless they are equal
        }
    }
    return cnt;
}

int main() {
    long long a = 12, b = 24;
    cout << commDiv(a, b) << endl;
    return 0;
}

// Time: O(log min(a, b)) + O(√gcd)
// Space: O(1)