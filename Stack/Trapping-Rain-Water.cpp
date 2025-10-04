#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size(), totalWater = 0;
    stack<int> st; // stores indices

    for (int i = 0; i < n; ++i) {
        // While current height is greater than the height at stack top
        while (!st.empty() && height[i] > height[st.top()]) {
            int mid = st.top();
            st.pop();

            if (st.empty()) break; // no left boundary

            int left = st.top();
            int width = i - left - 1;
            int boundedHeight = min(height[left], height[i]) - height[mid];

            totalWater += width * boundedHeight;
        }
        st.push(i);
    }

    return totalWater;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(height);

    cout << "Output: " << result << endl;

    return 0;
}