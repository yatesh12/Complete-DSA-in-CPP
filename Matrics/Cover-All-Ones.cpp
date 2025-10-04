#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumArea(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int minRow = rows, maxRow = -1;
    int minCol = cols, maxCol = -1;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    if (maxRow == -1) return 0;

    int height = maxRow - minRow + 1;
    int width  = maxCol - minCol + 1;
    return height * width;
}

int main() {
    // Hardcoded input for testing
    vector<vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << "Minimum Area: " << minimumArea(grid) << "\n";
    return 0;
}