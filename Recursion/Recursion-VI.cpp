#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0;

    // Count elements less than or equal to pivot
    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    // Place pivot at its correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // Partition the array around the pivot
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    // base case
    if(s >= e){
        return;
    }

    int p = partition(arr, s, e);

    // sorting of left part
    quickSort(arr, s, p-1);

    // sorting of right part
    quickSort(arr, p+1, e);

}

int main() {
  int arr[10] = {2,5,4,8,1, 15, 89, 0, 4, 7};
  int n = 10;

  quickSort(arr, 0, n - 1);
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }cout << endl;


  return 0;
}