#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time: O(m x n) & Space: O(m x n)
int countSquareSubmatrics(vector<vector<int>> matrix){
    int count = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // Fill first column
    for (int i = 0; i < rows; ++i){
        dp[i][0] = matrix[i][0];
    }

    // Fill first row
    for (int j = 0; j < cols; ++j){
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }else{
                dp[i][j] = 0;
            }
        }
    }


    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){ 
            count += dp[i][j];
        }
    }
    return count;
}

// Time: O(m x n) & Space: O(1)
int countSquares(vector<vector<int>>& matrix) {
    int count = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1 && i > 0 && j > 0) {
                matrix[i][j] = 1 + min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]);
            }
            count += matrix[i][j];
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};

    int result = countSquares(matrix);
    cout << result << endl;
    return 0;
}
