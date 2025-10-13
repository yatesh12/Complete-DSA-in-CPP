#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays with sum equal to k
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixFreq; // <prefixSum, count>
    prefixFreq[0] = 1;  // Edge case: prefix sum 0 occurs once

    int prefixSum = 0, count = 0;

    for (int num : nums) {
        prefixSum += num;

        // Check if there's a prefix sum that would make current sum - k
        if (prefixFreq.find(prefixSum - k) != prefixFreq.end()) {
            count += prefixFreq[prefixSum - k];
        }

        // Record current prefix sum
        prefixFreq[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, -1, 2, 1};
    int k = 3;

    int result = subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}

// Time: O(n)
// Space: O(n)