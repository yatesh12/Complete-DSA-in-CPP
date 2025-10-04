#include <iostream>
using namespace std;

void powerFunc(int a)
{
    for (int i = 1; i <= a; i++) {
        cout << i << " * 2 = " << i * 2 << endl;
    }
}

int main()
{
    powerFunc(15);
    return 0;
}
