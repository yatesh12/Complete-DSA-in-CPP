#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> selectionSort(vector<int> arr){
    int n = arr.size();

    for(int i = 0; i < n - 1; i++){
        int minIndex = i; // Assume 1st element is smallest
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    return arr;
}

int main()
{
    vector<int> arr = {1, 7, 2, 0, 9, 3};
    vector<int> result = selectionSort(arr);

    for (int i : result)
        cout << i << " ";

    return 0;
}