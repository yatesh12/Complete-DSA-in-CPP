#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e){
    int i = s;
    int j = mid + 1;
    vector<int> temp;

    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // left half
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    // right half
    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+s] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int s, int e){
    if(s < e){
    int mid = s + (e - s) / 2;

    // left half call
    mergeSort(arr, s, mid);
    // right half call
    mergeSort(arr, mid+1, e);

    merge(arr, s, mid, e);
    }
}

int main() {
  vector<int> arr = {12, 31, 2, 56, 85, 12, 5};
  int s = 0;
  int e = arr.size() - 1;

  mergeSort(arr, s, e);

  for(int i : arr){
    cout << i << " ";
  }

  return 0;
}