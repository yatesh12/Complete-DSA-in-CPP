#include <iostream>
using namespace std;

int main() {
    int amount = 1310;
    int hundred = 0, fifty = 0, twenty = 0, ten = 0;

    switch (1) {
        case 1:
            hundred = amount / 100;
            amount %= 100;
        case 2:
            fifty = amount / 50;
            amount %= 50;
        case 3:
            twenty = amount / 20;
            amount %= 20;
        case 4:
            ten = amount / 10;
            amount %= 10;
            break;
        default:
            break;
    }

    cout << "₹100 notes: " << hundred << endl;
    cout << "₹50 notes: " << fifty << endl;
    cout << "₹20 notes: " << twenty << endl;
    cout << "₹10 notes: " << ten << endl;

    return 0;
}
