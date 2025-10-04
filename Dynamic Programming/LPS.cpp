#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPalindromicSubsequence(const string& s) {
    int n = s.size();

    // Two 1D arrays to optimize space: prev for previous row, curr for current computation
    vector<int> prev(n, 0), curr(n, 0);

    // Traverse the string in reverse to build up LPS from substrings
    for (int i = n - 1; i >= 0; --i) {
        curr[i] = 1; // Base case: single character is always a palindrome of length 1

        // Explore all substrings starting from s[i] to s[j]
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                // Characters match → extend LPS by 2 (add both ends)
                curr[j] = prev[j - 1] + 2;
            } else {
                // No match → take the longer LPS from excluding either s[i] or s[j]
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }

        // Move current row into previous for next iteration
        prev = curr;
    }

    // Final result is stored at the end of curr (LPS of entire string)
    return curr[n - 1];
}


int LPS(const string& s) {
    int n = s.size();
    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = 1;
        int prev = 0;

        for (int j = i + 1; j < n; ++j) {
            int temp = dp[j];
            if (s[i] == s[j]) {
                dp[j] = prev + 2;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }

    return dp[n - 1];
}

int main() {
    string s = "bbbcb";
    int lpsLength = longestPalindromicSubsequence(s);
    cout << "Longest Palindromic Subsequence Length: " << lpsLength << endl;
    return 0;
}

// Time: O(n^2)
// Space: O(n)