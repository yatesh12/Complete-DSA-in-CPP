// #include <iostream>
// #include <vector>
// using namespace std;

// void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {
//     if(index >= nums.size()) {
//         ans.push_back(output);
//         return;
//     }

//     // Exclude the current element
//     solve(nums, output, index+1, ans);
    
//     // Include the current element
//     output.push_back(nums[index]);
//     solve(nums, output, index+1, ans);
// }

// int main() {
//     vector<int> nums = {1, 2, 3};  // Example input
//     vector<vector<int>> ans;
//     vector<int> output;
//     int index = 0;

//     solve(nums, output, index, ans);

//     // Print all subsets
//     for(const auto& subset : ans) {
//         cout << "{ ";
//         for(int num : subset)
//             cout << num << " ";
//         cout << "}" << endl;
//     }

//     return 0;
// }


// =========================================================

#include <iostream>
#include <vector>
using namespace std;

vector<string> subsequence(string ch) {
    int n = ch.length();
    int total = 1 << n; // 2^n subsequences
    vector<string> ans;

    for (int mask = 0; mask < total; ++mask) {
        string sub = "";
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sub += ch[i];
            }
        }
        ans.push_back(sub);
    }
    return ans;
}

int main() {
    string ch = "abc";
    vector<string> result = subsequence(ch);

    for (const string& str : result) {
        cout << "\"" << str << "\"" << endl;
    }

    return 0;
}