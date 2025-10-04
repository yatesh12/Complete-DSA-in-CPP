#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> arr){
    int n = arr.size();

    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev]; 
            prev--;
        }
        // placing the curr ele in its correct position
        arr[prev + 1] = curr;
    }

    return arr;
}

int main()
{
    vector<int> arr = {1, 7, 2, 0, 9, 3};
    vector<int> result = insertionSort(arr);

    for (int i : result)
        cout << i << " ";
    return 0;
}