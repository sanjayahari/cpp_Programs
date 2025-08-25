#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr[8] = {1, 5, 8, 9, 7, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int st = 1, en = n-2,mid=st+(en-st)/2;
    while(st <= en) {
        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
            cout << "Peak found at index: " << mid << " with value: " << arr[mid] << endl;
            return 0; // Peak found
        } else if(arr[mid-1] < arr[mid]){
            st =mid + 1; // Move to the right half
         } else {
            en = mid - 1; // Move to the left half
        }
        }

    
    }
