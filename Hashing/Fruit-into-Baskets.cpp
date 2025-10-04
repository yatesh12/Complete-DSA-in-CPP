#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int>& arr){
    int left = 0, maxLen = 0;
    unordered_map<int, int> count;

    for(int right=0; right < arr.size(); ++right){
        count[arr[right]]++;

        while(count.size() > 2){
            count[arr[left]]--;
            if(count[arr[left]] == 0) count.erase(arr[left]);

            ++left;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
  vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};

  int count = solution(arr);
  cout << count << endl;
  return 0;
}