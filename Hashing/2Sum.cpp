#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> m;
    int n = nums.size();

    for(int i=0; i < n; i++){
        int first = nums[i];
        int second = target - first;

        if(m.find(second) != m.end()){
            return {i, m[second]};
        }
        
        m[first] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {21, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}