// #include <iostream>
// using namespace std;

// int main() {
//     for (int i = 1; i <= 5; i++) {
//         if (i == 3) {
//             continue; // Skip when i == 3
//         }
//         cout << i << " ";
//     }
//     return 0;
// }

// Output: 1 2 4 5
// ===============================================

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter the value of A and B: " << endl;
    cin >> a >> b;

    char ch;
    cout << "Enter the choice" << endl;
    cin >> ch;

    switch (ch)
    {
    case '+':
        cout << (a + b) << endl;
        break;

    case '-':
        cout << (a - b) << endl;
        break;

    case '*':
        cout << (a * b) << endl;
        break;

    case '/':
        cout << (a / b) << endl;
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}