#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    // Sort the array to enable two-pointer technique
    sort(nums.begin(), nums.end());

    // Traverse each element up to n - 2
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for the first element of the triplet
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;       // Left pointer
        int k = n - 1;       // Right pointer

        // Two-pointer scan to find pairs that sum to -nums[i]
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                // Need a larger sum: move left pointer to the right
                j++;
            } else if (sum > 0) {
                // Need a smaller sum: move right pointer to the left
                k--;
            } else {
                // Found a valid triplet
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                // Skip duplicates for second element
                while (j < k && nums[j] == nums[j - 1]) ++j;

                // Skip duplicates for third element
                while (j < k && nums[k] == nums[k + 1]) --k;
            }
        }
    }

    return result;
}


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets summing to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

// Time: O(n^2)
// Space: O(k) unique triplets