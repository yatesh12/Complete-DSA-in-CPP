#include <iostream>
#include <vector>
using namespace std;

int findFirst(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) right = mid - 1;
        else left = mid + 1;
        if (nums[mid] == target) index = mid;
    }
    return index;
}

int findLast(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid - 1;
        if (nums[mid] == target) index = mid;
    }
    return index;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int first = findFirst(nums, target);
    int last = findLast(nums, target);

    cout << "First and Last Position of " << target << ": ["
         << first << ", " << last << "]" << endl;

    return 0;
}