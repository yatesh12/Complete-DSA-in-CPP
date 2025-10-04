#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
        return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
    }

    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        if (isSafe(x + 1, y, n, visited, m)) {
            path.push_back('D');
            solve(m, n, ans, x + 1, y, visited, path);
            path.pop_back();
        }

        // Left
        if (isSafe(x, y - 1, n, visited, m)) {
            path.push_back('L');
            solve(m, n, ans, x, y - 1, visited, path);
            path.pop_back();
        }

        // Right
        if (isSafe(x, y + 1, n, visited, m)) {
            path.push_back('R');
            solve(m, n, ans, x, y + 1, visited, path);
            path.pop_back();
        }

        // Up
        if (isSafe(x - 1, y, n, visited, m)) {
            path.push_back('U');
            solve(m, n, ans, x - 1, y, visited, path);
            path.pop_back();
        }

        visited[x][y] = 0; // Backtrack
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        if (m[0][0] == 0) return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(m, n, ans, 0, 0, visited, "");
        sort(ans.begin(), ans.end()); // Optional: sort paths alphabetically
        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.findPath(maze, maze.size());

    if (paths.empty()) {
        cout << "-1\n";
    } else {
        for (const string& path : paths) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}