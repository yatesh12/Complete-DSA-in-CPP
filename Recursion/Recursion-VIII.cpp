#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, string> PhoneMap = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
};

void phoneNumber(const string& digits, int index, string& current, vector<string>& output) {
    
    if (index == digits.length()) {
        output.push_back(current);
        return;
    }

    string letters = PhoneMap[digits[index]];

    for (char ch : letters) {
        current.push_back(ch);
        phoneNumber(digits, index + 1, current, output);
        current.pop_back();  // backtrack
    }
}

int main() {
    string digits = "39";
    vector<string> output;
    string current;

    if (!digits.empty()) {
        phoneNumber(digits, 0, current, output);
    }

    cout << "Letter combinations for \"" << digits << "\":" << endl;
    for (const string& combo : output) {
        cout << combo << " ";
    }
    cout << endl;

    return 0;
}