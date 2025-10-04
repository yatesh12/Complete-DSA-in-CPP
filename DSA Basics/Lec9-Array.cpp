#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int Arr[] = {50, 12, 1, 18, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);

    // sort(Arr, Arr + n);
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i=0; i<n; i++){
        if(Arr[i] > max){
            max = Arr[i];
        }
        if(Arr[i] < min){
            min = Arr[i];
        }
    }


    cout << "Smaller: " << min << endl;
    cout << "Greater: " << max << endl;

}