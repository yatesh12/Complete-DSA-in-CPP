#include <iostream>
#include <vector>
using namespace std;

int solveKnapsack(vector<int>& weight, vector<int>& value, int W) {
    int n = weight.size();
    vector<int> dp(W + 1, 0);

   for (int i = 0; i < n; ++i) {
    // Traverse backwards to avoid overwriting needed values
        for (int w = W; w >= weight[i]; --w) {
            // exclude or include value
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    return dp[W];
}

int main() {
    vector<int> weight = {2, 3, 4, 5};
    vector<int> value = {3, 4, 5, 6};
    int W = 5;

    int maxValue = solveKnapsack(weight, value, W);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}


// Time and Space Complexity
// - Time: O(n x W)
// - Space: O(W)
