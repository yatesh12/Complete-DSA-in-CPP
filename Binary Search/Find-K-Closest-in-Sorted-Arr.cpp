#include <iostream>
#include <vector>
using namespace std;

vector<int> findKClosestEle(vector<int>& nums, int k, int Target) {
    int left = 0, right = nums.size() - k;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (Target - nums[mid] > nums[mid + k] - Target)
            left = mid + 1;
        else
            right = mid;
    }

    return vector<int>(nums.begin() + left, nums.begin() + left + k);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 9}; // Must be sorted
    int k = 3, Target = 5;
    vector<int> res = findKClosestEle(nums, k, Target);

    cout << "K closest elements to " << Target << " are: ";
    for (int num : res) cout << num << " ";
    cout << endl;

    return 0;
}

// Time Complexity:
// - Binary search to find closest index → O(log n)
// - Expanding window to find k closest → O(k)
// Total Time Complexity: O(log n + k)
// Space Complexity: O(k)
