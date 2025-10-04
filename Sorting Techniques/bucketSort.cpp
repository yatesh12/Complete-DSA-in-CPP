#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(float arr[], int n) {
    // Step 1: Create empty buckets
    vector<float> buckets[n];

    // Step 2: Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; // Index in bucket
        buckets[index].push_back(arr[i]);
    }

    // Step 3: Sort each bucket
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Step 4: Concatenate all buckets
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bucketSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}