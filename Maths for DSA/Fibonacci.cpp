#include <iostream>
#include <vector>
using namespace std;

int fibNormal(int n) {
    if (n <= 1) return n;
    return fibNormal(n - 1) + fibNormal(n - 2);
}

int fibTopDown(int n, vector<int>& dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibTopDown(n-1, dp) + fibTopDown(n-2, dp);
}

int fibBottomUp(int n){
    if(n <= 1) return n;
    int a = 0, b = 1;

    for(int i = 2; i <= n; i++){
        int temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    int n;
    cout << "Enter no: ";
    cin >> n;

    vector<int> dp(n+1, -1);

    // Time: O(n ^ 2) - Space: O(n) recursive stack
    cout << "Recursion: " << fibTopDown(n, dp) << endl;

    // Time: O(n) - Space: O(n)
    cout << "Top-Down (Memoization): " << fibTopDown(n, dp) << endl;
    
    // Time: O(n) - Space: O(1)
    cout << "Bottom-Up (Tabulation): " << fibBottomUp(n) << endl;

    return 0;
}