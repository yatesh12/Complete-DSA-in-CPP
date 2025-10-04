#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& arr, int students, int maxAllowedPages) {
    int stud = 1, pages = 0;
    for (int p : arr) {
        if (pages + p <= maxAllowedPages) {
            pages += p;
        } else {
            stud++;
            pages = p;
            if (stud > students) 
                return false;
        }
    }
    return true;
}

int allocateBooks(vector<int>& pages, int students) {
    int n = pages.size();
    if (n < students) 
        return -1;

    int st = 0;
    int end = 0;
    for (int p : pages) 
        end += p;

    int answer = end;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isValid(pages, students, mid)) { // search left half
            answer = mid;
            end = mid - 1;    
        } else { // search right half
            st = mid + 1;     
        }
    }
    return answer;
}

int main() {
    vector<int> pages = {10, 20, 30, 40};
    int students = 2;

    cout << allocateBooks(pages, students) << "\n";
    return 0;
}