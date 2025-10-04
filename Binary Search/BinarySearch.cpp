#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int Arr[], int target, int size){
    int low = 0, high = size - 1;
    if (!is_sorted(Arr, Arr + size)) {
        throw "Array is not sorted!";
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (Arr[mid] == target){
            return mid;
        }
        else if (Arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){

    int Arr[6] = {1, 2, 6, 8, 9, 18};
    int target = 10;
    int n = sizeof(Arr) / sizeof(Arr[0]);

    try{
    int result = binarySearch(Arr, target, n);
    cout << result << endl;
    }
    catch(const char* msg){
        cout << "Exception caught: " << msg << endl;
    }

    return 0;
}