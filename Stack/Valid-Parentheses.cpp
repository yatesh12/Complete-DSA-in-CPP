#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            if ((st.top() == '(' && c == ')') ||
                (st.top() == '{' && c == '}') ||
                (st.top() == '[' && c == ']')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    vector<string> testCases = {
        "()[]{}",     // true
        "([{}])",     // true
        "(]",         // false
        "([)]",       // false
        "{[()]}",     // true
        "(",          // false
        "",           // true
        "((()))",     // true
        "(()))",      // false
        "[{()}](){}", // true
    };

    for (const string& s : testCases) {
        cout << "Input: \"" << s << "\" - Output: " 
             << (isValid(s) ? "true" : "false") << endl;
    }

    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(N)