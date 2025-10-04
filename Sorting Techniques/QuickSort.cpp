#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // Left half
        quickSort(arr, pi + 1, high); // Right Half
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr){
        cout << num << " ";
    }cout << "\n";

    return 0;
}  


// Time Complexity
// - Average Case: O(n log n)
// - Worst Case: O(n²) (when array is already sorted or reverse sorted)

// Space Complexity: O(log n) - due to recursive stack calls
