#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(const string& s1, const string& s2) {
  int n = s2.size();
  vector<int> dp(n + 1, 0);

  for(char a : s1){
    int prev = 0;
    for(int j = 1; j <= n; j++){
        int temp = dp[j];
        dp[j] = (a == s2[j - 1]) ? prev + 1 : max(dp[j], dp[j-1]);
        prev = temp;
    }
  }

  return dp[n];
}

int LCSExplain(const string& s1, const string& s2) {
    int n = s2.size();

    // Initialize a 1D DP array for storing LCS lengths up to index j of s2
    vector<int> dp(n + 1, 0);

    // Iterate over each character of s1
    for (char a : s1) {
        int prev = 0; // Stores dp[j-1] from previous iteration (for diagonal reference)

        // Traverse through s2 from left to right
        for (int j = 1; j <= n; j++) {
            int temp = dp[j]; // Temporarily hold current dp[j] for the next round's prev

            // If current characters match, extend LCS by 1 (diagonal move)
            // Else, take the max of previous results (top or left cell analogy)
            dp[j] = (a == s2[j - 1]) ? prev + 1 : max(dp[j], dp[j - 1]);

            // Update prev for next j
            prev = temp;
        }
    }

    // dp[n] holds the final LCS length
    return dp[n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int lcsLength = longestCommonSubsequence(s1, s2);
    cout << "LCS Length: " << lcsLength << endl;

    return 0;
}

// Time: O(n x m)
// space: O(n)