#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // stores actual values (not indices)

    for (int i = n - 1; i >= 0; --i) {
        // Maintain decreasing stack
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(nums[i]);
    }

    return result;
}

int main() {
    vector<int> input = {1, 3, 4, 2};
    vector<int> output = nextGreaterElements(input);

    cout << "Input: [";
    for (int i = 0; i < input.size(); ++i)
        cout << input[i] << (i < input.size() - 1 ? ", " : "");
    cout << "]\nOutput: [";
    for (int i = 0; i < output.size(); ++i)
        cout << output[i] << (i < output.size() - 1 ? ", " : "");
    cout << "]\n";

    return 0;
}