#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to check if a given capacity can ship all packages within D days
bool canShip(const vector<int>& weights, int D, int capacity) {
    int daysUsed = 1, currWeight = 0;
    for (int w : weights) {
        if (currWeight + w > capacity) {
            daysUsed++;
            currWeight = 0;
        }
        currWeight += w;
        if (daysUsed > D) return false;
    }
    return true;
}

// Main function to compute minimum ship capacity
int shipWithinDays(const vector<int>& weights, int D) {
    int lo = *max_element(weights.begin(), weights.end());
    int hi = accumulate(weights.begin(), weights.end(), 0);

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canShip(weights, D, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

// Driver code
int main() {
    vector<int> weights1 = {1,2,3,4,5,6,7,8,9,10};
    int days1 = 5;
    cout << "Minimum capacity (Example 1): " << shipWithinDays(weights1, days1) << endl;

    return 0;
}