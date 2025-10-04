#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (b == 0)
        throw "Division by zero error!";
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        cout << "Result: " << result << endl;
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }

    return 0;
}
