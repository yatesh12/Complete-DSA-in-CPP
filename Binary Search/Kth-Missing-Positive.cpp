#include <iostream>
#include <vector>
using namespace std;

// Find kth missing positive. time: O(log N) Space: O(1)
int findKthPositive(vector<int>& arr, int k){
    int left = 0, right = arr.size();

    while(left < right){
        int mid = left + (right - left) / 2;
        
        if(arr[mid] - mid - 1 < k){
            left = mid + 1;
        }else{
            right = mid;
        }
    }

    return left + k;
}

int main() {
  vector<int> arr = {1,2,3,4,5};
  int k = 5;
  int ans = findKthPositive(arr, k);
  cout << ans << endl;
  return 0;
}