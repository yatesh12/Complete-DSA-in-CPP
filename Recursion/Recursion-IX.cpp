#include <iostream>
using namespace std;

void permute(string str, int l, int r) {
    // base case
    if (l == r) {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; ++i) {
        swap(str[l], str[i]);        // Swap current index with i
        permute(str, l + 1, r);      // Recurse for the rest
        swap(str[l], str[i]);        // Backtracks
    }
}

int main() {
    string s = "abc";
    permute(s, 0, s.length() - 1);
    return 0;
}