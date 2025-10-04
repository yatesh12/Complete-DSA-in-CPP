// #include <iostream>
// using namespace std;

// bool isSorted(int arr[], int n){
//     if(n == 0 || n == 1){
//         return true;
//     }

//     if(arr[0] > arr[1]){
//         return false;
//     }else{
//         bool remainingPart = isSorted(arr+1, n - 1);
//     }
// }

// int main() {
//   int arr[5] = {1,2,3,0,5};
//     int size  = sizeof(arr) / sizeof(arr[0]);

//   bool ans = isSorted(arr, size);

//   if(ans){
//     cout << "Array is Sorted" << endl;
//   }else{
//     cout << "Array is Not Sorted" << endl;
//   }

//   return 0;
// }

// =============================================

// #include <iostream>
// using namespace std;
// bool isFound(int Arr[], int n, int key){
//     if(n == 0){
//         return false;
//     }

//     if(Arr[0] == key){
//         return true;
//     }else{
//         bool remainingPart = isFound(Arr + 1, n - 1, key);
//         return remainingPart;
//     }
// }
// int main() {
//   int Arr[5] = {1,2,3,4,5};
//   int key = 2;
//     int size  = sizeof(Arr) / sizeof(Arr[0]);

//   int ans = isFound(Arr, size, key);

//   if(ans){
//     cout << key << " is Present" << endl;
//   }else{
//     cout << key << " is Absent" << endl;
//   }
//   return 0;
// }

// ===========================================

#include <iostream>
using namespace std;

bool binarySearch(int Arr[], int s, int e, int key){
    if(s > e){
        return false;
    }

    int mid = s + (e - s) / 2;

    if(Arr[mid] == key){
        return true;
    }else if(Arr[mid] < key){
        return binarySearch(Arr, mid + 1, e, key);
    }else{
        return binarySearch(Arr,s, mid - 1, key);
    }

}

int main() {

    int Arr[5] = {1,3,4,5,9};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    int key = 51;

    int s = Arr[0];
    int e = Arr[size - 1];
    bool ans = binarySearch(Arr, s, e, key);
  
if(ans){
    cout << key << " is Present" << endl;
  }else{
    cout << key << " is Absent" << endl;
  }
  
  return 0;
}