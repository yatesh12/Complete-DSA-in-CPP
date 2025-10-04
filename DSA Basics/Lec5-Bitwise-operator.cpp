// #include <iostream>
// using namespace std;

// int main() {
//     int n = 10, a = 0, b = 1, sum = 0;
//     cout << "Fibonacci sequence: ";
//     for (int i = 0; i < n; i++) {
//         cout << a << " ";
//         sum += a;
//         int next = a + b;
//         a = b;
//         b = next;
//     }
//     cout << "\nFibonacci sequence sum: " << sum;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n = 145;
//     vector<int> list;

//     while (n != 0) {
//         int digit = n % 10;
//         list.insert(list.begin(), digit);
        
//         n = n / 10;
//     }

//     for(int digits : list){
//         cout << digits << " ";
//     }

//     return 0;
// }


#include <iostream>
using namespace std;

int main() {
    int n = 145;
    string s = to_string(n);

    for (char c : s) {
        cout << c << " ";
    }

    return 0;
}
