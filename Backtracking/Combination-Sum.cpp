#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// --------- Optimized DFS Solution ------------
void dfs(vector<int>& candidates, int start, int target, vector<int>& path, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(path);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > target) break; // Prune unnecessary paths

        path.push_back(candidates[i]);
        dfs(candidates, i, target - candidates[i], path, res); // Allow reuse
        path.pop_back(); // Backtrack
    }
}

vector<vector<int>> combinationSumDFS(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Sort for pruning
    vector<vector<int>> res;
    vector<int> path;
    dfs(candidates, 0, target, path, res);
    return res;
}

// -------------------- MAIN --------------------
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    cout << "\nOptimized DFS Solution:\n";

    vector<vector<int>> res = combinationSumDFS(candidates, target);
    for (const auto& comb : res) {
        for (int num : comb) cout << num << " ";
        cout << "\n";
    }

    return 0;
}


// Time Complexity: O(2^n · k)
// Space: O(k · #combinations)