#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// Q.1 reverse number
// int reverseInteger(int number)
// {
//     int ans = 0;
//     while (number != 0)
//     {
//         int digit = number % 10;

//         if((ans > INT_MAX / 10) || (ans < INT_MIN / 10)){
//             return 0;
//         }

//         ans = (ans * 10) + digit;
//         number = number / 10;

//     }
//     return ans;
// }

// int main()
// {
//     int n;
//     cout << "Enter the Number: " << endl;
//     cin >> n;
//     int result = reverseInteger(n);
//     cout << result << endl;
// }


// Q.2 reverse number
#include <iostream>
using namespace std;

int onesComplement(int n) {
    int mask = 0, temp = n;

    // Create mask with bits set equal to number of bits in n
    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return (~n) & mask;
}

int main() {
    int n = 10;
    cout << "1's Complement of " << n << " is: " << onesComplement(n) << endl;
    return 0;
}
 