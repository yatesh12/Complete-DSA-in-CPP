// #include <iostream>
// using namespace std;

// string reverseString(string ch, int s, int e) {
//     if (s >= e) {
//         return ch;
//     }

//     swap(ch[s], ch[e]);
//     return reverseString(ch, s + 1, e - 1);
// }

// int main() {
//     string ch = "Hello";
//     string ans = reverseString(ch, 0, ch.length() - 1);
//     cout << ans << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

bool checkPalindrom(string ch, int i, int j){
    
    if (i >= j){
        return true;
    }

    if (ch[i] != ch[j]){
        return false;
    }
    else{
        return checkPalindrom(ch, i + 1, j - 1);
    }
}

int main()
{
    string ch = "Helloolleh";

    string input = ch;
    for (char &c : input){
        c = tolower(c);
    }

    bool ans = checkPalindrom(input, 0, ch.length() - 1);

    if (ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}