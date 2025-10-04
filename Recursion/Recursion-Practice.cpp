#include <iostream>
using namespace std;

void resursion(int n){
    if(n == 0){
        return;
    }

    cout << n << " ";
    resursion(n - 1);
}


int sum(int n){
    if(n == 1){
        return 1;
    }

    return n + sum(n-1);
}

int main() {
    int n = 4;
    // resursion(n);

    int ans = sum(n);
    cout << ans;
  return 0;
}