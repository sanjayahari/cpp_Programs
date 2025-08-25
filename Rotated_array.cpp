#include <iostream>
#include <vector>
using namespace std;

// Funstion to find the pivot index in a rotated sorted array
int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int s=0, e=n-1;
    int mid;
    int target = 0; // Example target value to search for
    while(s <= e){
        mid= s + (e - s) / 2;
        if(arr[s] <= arr[mid-1]){
            // If the left part is sorted
            if(arr[s] <= target && target <= arr[mid-1]){
                e = mid - 1; // Search in the left part
            } else {
                s = mid+1; // Search in the right part
            }
        }
        if(arr[mid+1] <= arr[e]){
            // If the right part is sorted  
            if(arr[mid+1] <= target && target <= arr[e]){
                s = mid + 1; // Search in the right part
            } else {
                e = mid - 1; // Search in the left part
            } 
        }
        if(arr[mid] == target) {  
            // If the array is not rotated or has only one element
                cout << "Element found at index: " << mid << endl;
                return 0; // Element found
            
        }
    }
    return -1; // Element not found


}