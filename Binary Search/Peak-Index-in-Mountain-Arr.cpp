#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, h = arr.size() - 1;

    while (l < h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] < arr[mid + 1]) {
            // Peak is to the right
            l = mid + 1;
        } else {
            // Peak is at mid or to the left
            h = mid;
        }
    }
    return l; // or h, since l == h
}

int main() {
    vector<int> mountain = {0, 2, 4, 7, 5, 3, 1};
    int peakIndex = peakIndexInMountainArray(mountain);
    cout << "Peak Index: " << peakIndex << endl;
    cout << "Peak Value: " << mountain[peakIndex] << endl;
    return 0;
}