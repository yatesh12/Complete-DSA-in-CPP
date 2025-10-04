#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int target){
    int n = arr.size(), s = 0, e = n - 1;

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(arr[mid] == target) return mid;
        // Check sorted part
        if(arr[s] <= arr[mid]){ // Left sorted
            if(arr[s] <= target && target <= arr[mid]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }else{
            if(arr[mid] <= target && target <= arr[e]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
  vector<int> arr = {5,6,7,8,9,0,1,2,3};
  int ans = search(arr, 2);
  cout << ans;
  return 0;
}

// Time: O(log N)
// Space: O(1)