#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bubbleSort(vector<int> arr){
    int n = arr.size();

    for(int i = 0; i < n - 1; i++){
        bool isSwap = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }

        if(!isSwap){ // Array is already sorted
            return arr;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {1, 7, 2, 0, 9, 3};
    vector<int> result = bubbleSort(arr);

    for (int i : result)
        cout << i << " ";

    return 0;
}